#ifndef _TL_STRING_H
#define _TL_STRING_H

#include <sstream>
#include <utility>

namespace TLib
{
   namespace Detail
   {

      template<class T>
      void BuildString_Append( std::ostringstream& s, const T& t ) noexcept
      {
         s << t;
      }
      template<class T, class ...R>
      void BuildString_Append( std::ostringstream& s, const T& t, const R&... r ) noexcept
      {
         BuildString_Append( s, t );
         BuildString_Append( s, r... );
      }
   }

   template<class T>
   std::string BuildString( const T& t ) noexcept
   {
      std::ostringstream s;
      Detail::BuildString_Append( s, t );
      return s.str();
   }
   template<class T, class ...R>
   std::string BuildString( const T& t, const R&... r ) noexcept
   {
      std::ostringstream s;
      Detail::BuildString_Append( s, t );
      Detail::BuildString_Append( s, r... );
      return s.str();
   }
}

#endif