#ifndef _TL_SORTED_LIST_H
#define _TL_SORTED_LIST_H
#include <iostream>
#pragma push_macro("new")
#undef new
namespace TLib
{
   template<class T>
   class SortedList
   {
   public:
      using ElementType = T;
      SortedList(unsigned capacity = 0) :
         m_Capacity(capacity),
         m_First((ElementType*)malloc(m_Capacity * sizeof(ElementType))),
         m_End(m_First)
      {
      }
      ~SortedList()
      {
         for (auto& e : *this)
         {
            e.~ElementType();
         }
         free(m_First);
      }
      template<class...Args>
      ElementType& Emplace(Args...args)
      {
         if ((m_End - m_First) >= m_Capacity)
            Realloc();
         ElementType* last_ptr = m_End;
         new(last_ptr) ElementType(args...);
         m_End++;
         return *(last_ptr);
      }
      ElementType& Add(const ElementType& elem)
      {
      }
      ElementType* begin()
      {
         return m_First;
      }
      ElementType* end()
      {
         return m_End;
      }
   private:
      void Realloc()
      {
         ElementType* oldList = m_First;
         unsigned diff = m_End - m_First;
         m_Capacity *= 2;
         m_First = (ElementType*)malloc(m_Capacity * sizeof(ElementType));
         m_End = m_First + diff;
         for (int i = 0;i < diff;i++)
            new(m_First + i) ElementType(*(oldList + i));
         for (int i = 0;i < diff;i++)
            (oldList + i)->~ElementType();
         free(oldList);
      }
      unsigned m_Capacity;
      ElementType* m_First;
      ElementType* m_End;
   };
}

#pragma pop_macro("new")
#endif