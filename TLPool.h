#ifndef _TL_POOL_H
#define _TL_POOL_H

#include "Switches.h"
#include "Exceptions.h"
#include "Memory.h"

#include <stdlib.h>

#pragma push_macro("new")
#undef new
namespace TLib
{
   template<class TValueType>
   class Pool : public Allocator
   {
   public:
      using Type = Pool;
      using ValueType = TValueType;
      Pool(size_t capacity) noexcept :
         capacity(capacity),
         usedBytes(capacity * sizeof(ValueType) + (int)ceil(capacity / 32.0)),
         arr((ValueType*)malloc(usedBytes)),
         used((unsigned*)(arr + capacity))
      {
         memset(arr, 0, usedBytes);
      }
      Pool(const Pool&) = delete;
      Pool(Pool&&) = delete;
      ~Pool()
      {
         for (unsigned i = 0; i < capacity; ++i)
            if (GetFlag(i))
               arr[i].~ValueType();
         free(arr);
      }
      Pool& operator=(const Pool&) = delete;
      Pool& operator=(Pool&&) = delete;
      void* Allocate(size_t size) override
      {
         TL_ASSERT_MSG(size % sizeof(ValueType) == 0, "size must match with sizeof(ValueType)");
         for (unsigned i = 0; i < capacity; ++i)
            if (!GetFlag(i))
            {
               SetFlag(i, true);
               return arr + i;
            }
#if TL_ALLOW_THROW
         throw OutOfMemoryException("TLib::Pool: Tried to add the element to full storage");
#else
         return {};
#endif
      }
      template<class...Args>
      ValueType& Emplace(Args&& ... args) noexcept(!TL_ALLOW_THROW && std::is_nothrow_constructible_v<ValueType, Args...>)
      {
         auto ptr = Allocate(sizeof(ValueType));
         return *new(ptr) ValueType(std::forward<Args>(args)...);
      }
      void Deallocate(void* ptr) override
      {
         auto e = (ValueType*)ptr;
         if (e < arr || arr + capacity <= e)
            throw OutOfRangeException("TLib::Pool: Tried to remove value outside container");
         if (!GetFlag(e - arr))
            throw ExcessActionException("TLib::Pool: Tried to remove already removed value");
         ((ValueType*)e)->~ValueType();
         SetFlag(e - arr, false);
      }
      template<class Function>
      void ForEach(Function f) noexcept(std::is_nothrow_invocable_v<Function, ValueType&>)
      {
         for (unsigned i = 0; i < capacity; ++i)
            if (GetFlag(i))
               f(arr[i]);
      }
      void Clear()
      {
         for (unsigned i = 0; i < capacity; ++i)
            if (GetFlag(i))
            {
               SetFlag(i, false);
               arr[i].~ValueType();
            }
      }
   private:
      void SetFlag(unsigned i, bool value)
      {
         unsigned* ptr = used;
         while (i >= 32)
         {
            i -= 32;
            ptr++;
         }
         if (value)
            * ptr = *ptr | (1 << i);
         else
            *ptr = *ptr & (0xFFFFFFFE << i);
      }
      bool GetFlag(unsigned i)
      {
         unsigned* ptr = used;
         while (i >= 32)
         {
            i -= 32;
            ptr++;
         }
         return *ptr & (1 << i);
      }
      const size_t capacity;
      const size_t usedBytes;
      ValueType* arr;
      unsigned* used;
   };
   template<>
   class Pool<void> : public Allocator
   {
   public:
      Pool(size_t bytes)
      {
         data = malloc(bytes);
      }
      void* Allocate(size_t size) override
      {
         return data;
      }
   private:
      void* data;
   };
}
#pragma pop_macro("new")
#endif