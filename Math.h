#ifndef _TLIB_MATH_H
#define _TLIB_MATH_H

namespace TLib::Math
{
   namespace Detail
   {
      template<class Scalar>
      [[nodiscard]] constexpr Scalar SqrtNewtonRaphson( const Scalar& x, const Scalar& curr, const Scalar& prev )
      {
         return curr == prev
            ? curr
            : SqrtNewtonRaphson<Scalar>( x, static_cast<Scalar>(0.5) * ( curr + x / curr ), curr );
      }
   }
   constexpr float Root2 = ( float )1.4142135623730950488016887242097L;
   constexpr float Root3 = ( float )1.7320508075688772935274463415059L;
   constexpr float Root5 = ( float )2.2360679774997896964091736687313L;
   constexpr float Pi    = ( float )3.1415926535897932384626433832795L;
   constexpr float Tau   = ( float )6.2831853071795864769252867665590L;
   constexpr float Phi   = ( float )1.6180339887498948482045868343656L;
   template<class T>
   [[nodiscard]] constexpr T Abs( const T & t )
   {
      if ( t < 0 )
         return -t;
      return t;
   }
   template<class Scalar>
   [[nodiscard]] constexpr Scalar Sqrt( const Scalar& x )
   {
      return x >= 0 && x < std::numeric_limits<Scalar>::infinity()
         ? Detail::SqrtNewtonRaphson<Scalar>( x, x, 0 )
         : std::numeric_limits<Scalar>::quiet_NaN();
   }
   template<class T>
   [[nodiscard]] constexpr T Max( const T& a, const T& b )
   {
      return a > b ? a : b;
   }
   template<class T>
   [[nodiscard]] constexpr T Min( const T& a, const T& b )
   {
      return a < b ? a : b;
   }
   template<class T>
   [[nodiscard]] constexpr T Clamp( const T& t, const T& min, const T& max )
   {
      return t < min ? min : t > max ? max : t;
   }
}

#endif