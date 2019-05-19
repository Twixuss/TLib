#ifndef _TL_COLOR_H
#define _TL_COLOR_H

#include "Attributes.h"

namespace TLib
{
   template<typename TScalar>
   struct Color
   {
      using Scalar = TScalar;
      using FScalar = const Scalar&;
      using FColor = const Color&;
      Scalar r{};
      Scalar g{};
      Scalar b{};
      Scalar a{};
      TL_CONSTEXPR Color() = default;
      TL_CONSTEXPR Color(FScalar v, FScalar a = {}) TL_NOEXCEPT : r(v), g(v), b(v), a(a) {}
      TL_CONSTEXPR Color(FScalar r, FScalar g, FScalar b, FScalar a = {}) TL_NOEXCEPT : r(r), g(g), b(b), a(a) {}
      TL_NODISCARD TL_CONSTEXPR Color operator+() TL_NOEXCEPT
      {
         return
         {
            +r,
            +g,
            +b,
            +a
         };
      }
      TL_NODISCARD TL_CONSTEXPR Color operator+() TL_NOEXCEPT
      {
         return
         {
            -r,
            -g,
            -b,
            -a
         };
      }
      TL_NODISCARD TL_CONSTEXPR Color& operator+=(FColor c) TL_NOEXCEPT
      {
         r += c.r;
         g += c.g;
         b += c.b;
         a += c.a;
         return *this;
      }
      TL_NODISCARD TL_CONSTEXPR Color& operator-=(FColor c) TL_NOEXCEPT
      {
         r -= c.r;
         g -= c.g;
         b -= c.b;
         a -= c.a;
         return *this;
      }
      TL_NODISCARD TL_CONSTEXPR Color& operator*=(FColor c) TL_NOEXCEPT
      {
         r *= c.r;
         g *= c.g;
         b *= c.b;
         a *= c.a;
         return *this;
      }
      TL_NODISCARD TL_CONSTEXPR Color& operator/=(FColor c) TL_NOEXCEPT
      {
         r /= c.r;
         g /= c.g;
         b /= c.b;
         a /= c.a;
         return *this;
      }
      TL_NODISCARD TL_CONSTEXPR friend Color operator+(FColor a, FColor b) TL_NOEXCEPT
      {
         return
         {
            a.r + b.r,
            a.g + b.g,
            a.b + b.b,
            a.a + b.a
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Color operator-(FColor a, FColor b) TL_NOEXCEPT
      {
         return
         {
            a.r - b.r,
            a.g - b.g,
            a.b - b.b,
            a.a - b.a
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Color operator*(FColor a, FColor b) TL_NOEXCEPT
      {
         return
         {
            a.r * b.r,
            a.g * b.g,
            a.b * b.b,
            a.a * b.a
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Color operator/(FColor a, FColor b) TL_NOEXCEPT
      {
         return
         {
            a.r / b.r,
            a.g / b.g,
            a.b / b.b,
            a.a / b.a
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Color operator==(FColor a, FColor b) TL_NOEXCEPT
      {
         return a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a;
      }
      TL_NODISCARD TL_CONSTEXPR friend Color operator!=(FColor a, FColor b) TL_NOEXCEPT
      {
         return a.r != b.r || a.g != b.g || a.b != b.b || a.a != b.a;
      }
   };
   using Colorf = Color<float>;
}

#endif