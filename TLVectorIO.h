#ifndef _TL_VECTOR_IO_H
#define _TL_VECTOR_IO_H

#include "TLVector.h"

namespace TLib
{
   template<class T, class Scalar>
   std::basic_ostream<T>& operator<<(std::basic_ostream<T>& os, FVector2<Scalar> v)
   {
      return os << v.x << ' ' << v.y;
   }
   template<class T, class Scalar>
   std::basic_ostream<T>& operator<<(std::basic_ostream<T>& os, FVector3<Scalar> v)
   {
      return os << v.x << ' ' << v.y << ' ' << v.z;
   }
   template<class T, class Scalar>
   std::basic_ostream<T>& operator<<(std::basic_ostream<T>& os, FVector4<Scalar> v)
   {
      return os << v.x << ' ' << v.y << ' ' << v.z << ' ' << v.w;
   }
   template<class T, class Scalar>
   std::basic_istream<T>& operator>>(std::basic_istream<T>& is, FVector2<Scalar> v)
   {
      return is >> v.x >> v.y;
   }
   template<class T, class Scalar>
   std::basic_istream<T>& operator>>(std::basic_istream<T>& is, FVector3<Scalar> v)
   {
      return is >> v.x >> v.y >> v.z;
   }
   template<class T, class Scalar>
   std::basic_istream<T>& operator>>(std::basic_istream<T>& is, FVector4<Scalar> v)
   {
      return is >> v.x >> v.y >> v.z >> v.w;
   }
}

#endif