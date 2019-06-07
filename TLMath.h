#ifndef _TL_MATH_H
#define _TL_MATH_H

#include <type_traits>
#include <cmath>

#include "TLAttributes.h"

namespace TLib::Math
{
   namespace Detail
   {
      template<class Scalar>
      [[nodiscard]] constexpr Scalar SqrtNewtonRaphson(const Scalar& x, const Scalar& curr, const Scalar& prev)
      {
         return curr == prev
            ? curr
            : SqrtNewtonRaphson<Scalar>(x, static_cast<Scalar>(0.5) * (curr + x / curr), curr);
      }
   }
   constexpr float Root2 = static_cast<float>(1.4142135623730950488016887242097L);
   constexpr float Root3 = static_cast<float>(1.7320508075688772935274463415059L);
   constexpr float Root5 = static_cast<float>(2.2360679774997896964091736687313L);
   constexpr float Pi    = static_cast<float>(3.1415926535897932384626433832795L);
   constexpr float Tau   = static_cast<float>(6.2831853071795864769252867665590L);
   constexpr float Phi   = static_cast<float>(1.6180339887498948482045868343656L);
   template<class T>
   [[nodiscard]] constexpr T Abs(const T & t)
   {
#if TL_CXX_VERSION > 2017
      if constexpr (std::is_constant_evaluated() || !std::is_arithmetic_v<T>)
         if (t < 0)
            return -t;
         else
            return t;
      else
         return abs(t);
#else
      if (t < 0)
         return -t;
      else
         return t;
#endif
   }
   template<class T>
   [[nodiscard]] constexpr T Sqrt(const T & x)
   {
#if TL_CXX_VERSION > 2017
      if constexpr (std::is_constant_evaluated() || !std::is_arithmetic_v<T>)
         return x >= 0 && x < std::numeric_limits<T>::infinity()
         ? Detail::SqrtNewtonRaphson<T>(x, x, 0)
         : std::numeric_limits<T>::quiet_NaN();
      else if constexpr (std::is_same_v<T, double>)
         return std::sqrt(x);
      else if constexpr (std::is_same_v<T, long double>)
         return std::sqrtl(x);
      else
         return std::sqrtf(x);
#else
      if constexpr (!std::is_arithmetic_v<T>)
         return x >= 0 && x < std::numeric_limits<T>::infinity()
         ? Detail::SqrtNewtonRaphson<T>(x, x, 0)
         : std::numeric_limits<T>::quiet_NaN();
      else if constexpr (std::is_same_v<T, double>)
         return std::sqrt(x);
      else if constexpr (std::is_same_v<T, long double>)
         return std::sqrtl(x);
      else
         return std::sqrtf(x);
#endif
   }
   template<class T>
   [[nodiscard]] constexpr T Max(const T & a, const T & b)
   {
      return a > b ? a : b;
   }
   template<class T>
   [[nodiscard]] constexpr T Min(const T & a, const T & b)
   {
      return a < b ? a : b;
   }
   template<class T>
   [[nodiscard]] constexpr T Clamp(const T & t, const T & min, const T & max)
   {
      return t < min ? min : t > max ? max : t;
   }
}

#endif