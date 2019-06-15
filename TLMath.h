#ifndef _TL_MATH_H
#define _TL_MATH_H

#include <type_traits>
#include <cmath>

#include "TLAttributes.h"

namespace TLib::Math
{
   namespace
   {
      template<class Scalar>
      TL_NODISCARD TL_CONSTEXPR Scalar SqrtNewtonRaphson(const Scalar& x, const Scalar& curr, const Scalar& prev)
      {
         return curr == prev
            ? curr
            : SqrtNewtonRaphson<Scalar>(x, static_cast<Scalar>(0.5) * (curr + x / curr), curr);
      }
   }
   constexpr float Root2 = (float)1.4142135623730950488016887242097L;
   constexpr float Root3 = (float)1.7320508075688772935274463415059L;
   constexpr float Root5 = (float)2.2360679774997896964091736687313L;
   constexpr float Pi    = (float)3.1415926535897932384626433832795L;
   constexpr float Tau   = (float)6.2831853071795864769252867665590L;
   constexpr float Phi   = (float)1.6180339887498948482045868343656L;
   template<class T>             
   TL_NODISCARD TL_CONSTEXPR T Abs(const T & t)
   {
      if (t < 0)
         return -t;
      else
         return t;
   }
   template<class T>
   TL_NODISCARD TL_CONSTEXPR bool Equal(const T& a, const T& b)
   {
      return a == b;
   }
   template<class T>
   TL_NODISCARD TL_CONSTEXPR bool Equal(const T& a, const T& b, float epsilon)
   {
      return Abs(a - b) < epsilon;
   }
   template<class T>
   TL_NODISCARD TL_CONSTEXPR T Sqrt(const T& x)
   {
      if constexpr (std::is_same_v<T, float>)
         return std::sqrtf(x);
      else if constexpr (std::is_same_v<T, double>)
         return std::sqrt(x);
      else if constexpr (std::is_same_v<T, long double>)
         return std::sqrtl(x);
      else
         return x >= 0 && x < std::numeric_limits<T>::infinity()
         ? Detail::SqrtNewtonRaphson<T>(x, x, 0)
         : std::numeric_limits<T>::quiet_NaN();
   }
   template<class T>
   TL_NODISCARD TL_CONSTEXPR T Max(const T& a, const T& b)
   {
      return a > b ? a : b;
   }
   template<class T>
   TL_NODISCARD TL_CONSTEXPR T Min(const T& a, const T& b)
   {
      return a < b ? a : b;
   }
   template<class T>
   TL_NODISCARD TL_CONSTEXPR T Clamp(const T& t, const T& min, const T& max)
   {
      return t < min ? min : t > max ? max : t;
   }
   template<class T>
   TL_NODISCARD TL_CONSTEXPR T Map(const T& value, const T& smin, const T& smax, const T& dmin, const T& dmax)
   {
      return (value - smin) / (smax - smin) * (dmax - dmin) + dmin;
   }
   template<class T, class Factor>
   TL_NODISCARD TL_CONSTEXPR T Lerp(const T& a, const T& b, const Factor& t)
   {
      return a + (b - a) * t;
   }
}

#endif