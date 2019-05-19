#ifndef _TL_STRING_H
#define _TL_STRING_H

#include <sstream>
#include <utility>

namespace TLib
{
   namespace Detail
   {

      template<class T>
      void BuildString_Append( std::ostringstream& s, T&& t ) noexcept
      {
         s << t;
      }
      template<class T, class ...R>
      void BuildString_Append( std::ostringstream& s, T&& t, R&& ... r ) noexcept
      {
         BuildString_Append( s, std::forward<T>( t ) );
         BuildString_Append( s, std::forward<R>( r )... );
      }
   }
   template<class T>
   std::string BuildString( T&& t ) noexcept
   {
      std::ostringstream s;
      Detail::BuildString_Append( s, std::forward<T>( t ) );
      return s.str();
   }
   template<class T, class ...R>
   std::string BuildString( T&& t, R&& ... r ) noexcept
   {
      std::ostringstream s;
      Detail::BuildString_Append( s, std::forward<T>( t ) );
      Detail::BuildString_Append( s, std::forward<R>( r )... );
      return s.str();
   }
}

#endif