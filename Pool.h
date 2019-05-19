#ifndef _TL_POOL_H
#define _TL_POOL_H

#include "Switches.h"
#include "Exceptions.h"

#include <stdlib.h>

#pragma push_macro("new")
#undef new
namespace TLib
{
   template<class ValueType_>
   class Pool
   {
   public:
      using Type = Pool;
      using ValueType = ValueType_;
      Pool( unsigned capacity ) noexcept :
         capacity( capacity ),
         arr( (ValueType*) malloc( capacity * sizeof( ValueType ) + capacity ) ),
         used( (unsigned char*) ( arr + capacity ) )
      {
         memset( arr, 0, capacity * sizeof( ValueType ) + capacity );
      }
      Pool( const Pool& ) = delete;
      Pool( Pool&& ) = delete;
      ~Pool( )
      {
         for ( unsigned i = 0;i < capacity;++i )
            if ( used[i] )
               arr[i].~ValueType( );
         free( arr );
      }
      Pool& operator=( const Pool& ) = delete;
      Pool& operator=( Pool&& ) = delete;
      template<class...Args>
      ValueType* Emplace( Args && ... args ) noexcept( !TL_ALLOW_THROW && std::is_nothrow_constructible_v<ValueType, Args...> )
      {
         for ( unsigned i = 0;i < capacity;++i )
            if ( !used[i] )
            {
               used[i] = true;
               return new( arr + i ) ValueType( std::forward<Args>(args)... );
            }
#if TL_ALLOW_THROW
         throw OutOfMemoryException( "TLib::Pool: Tried to add the element to full storage" );
#else
         return nullptr;
#endif
      }
      ValueType* Push( const ValueType & e )
      {
         return Emplace( e );
      }
      ValueType* Push( ValueType && e )
      {
         return Emplace( std::move( e ) );
      }
      bool Remove( ValueType* e ) noexcept( !TL_ALLOW_THROW )
      {
         if ( e < arr || arr + capacity <= e )
#if TL_ALLOW_THROW
            throw OutOfRangeException("TLib::Pool: Tried to remove value outside container");
#else
            return false;
#endif
         if ( !used[e - arr] )
#if TL_ALLOW_THROW
            throw ExcessActionException( "TLib::Pool: Tried to remove already removed value" );
#else
            return false;
#endif
         e->~ValueType( );
         used[e - arr] = false;
         return true;
      }
      template<class Function>
      void ForEach( Function f ) noexcept( std::is_nothrow_invocable_v<Function, ValueType&> )
      {
         for ( unsigned i = 0;i < capacity;++i )
            if ( used[i] )
               f( arr[i] );
      }
      void Clear()
      {
         for ( unsigned i = 0;i < capacity;++i )
            if ( used[i] )
            {
               used[i] = false;
               arr[i].~ValueType();
            }
      }
   private:
      const unsigned capacity;
      ValueType* arr;
      unsigned char* used;
   };
}
#pragma pop_macro("new")
#endif