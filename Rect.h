#ifndef _TLIB_RECT_H
#define _TLIB_RECT_H

#include "Vector.h"

namespace TLib
{
   template<class Scalar_>
   struct Rect
   {
      using Scalar = Scalar_;
      union
      {
         struct
         {
            Scalar x, y, w, h;
         };
         struct
         {
            Vector2<Scalar> position, size;
         };
      };
/* Vec() */
      constexpr Rect() noexcept :
         x((Scalar)0),
         y((Scalar)0),
         w((Scalar)0),
         h((Scalar)0)
      {
      }
      constexpr Rect(Scalar x, Scalar y) :
         x(x),
         y(y),
         w(),
         h()
      {
      }
      constexpr Rect(Scalar x, Scalar y, Scalar w, Scalar h) :
         x(x),
         y(y),
         w(w),
         h(h)
      {
      }
      constexpr Rect(Vector2<Scalar> p, Vector2<Scalar> s = 0) :
         x(p.x),
         y(p.y),
         w(s.x),
         h(s.y)
      {
      }
      constexpr Rect(Vector4<Scalar> v) :
         x(v.x),
         y(v.y),
         w(v.z),
         h(v.w)
      {
      }
      constexpr Rect(const Rect&) = default;
      constexpr Rect(Rect&&) = default;
      template<class Other>
      constexpr explicit Rect(const Rect<Other>& other) :
         x((Scalar)other.x),
         y((Scalar)other.y),
         z((Scalar)other.z),
         w((Scalar)other.w)
      {
      }
/* Rect = Rect */
      constexpr Rect& operator=(const Rect&) = default;
      constexpr Rect& operator=(Rect&&) = default;
/* x Rect */
      constexpr friend Rect operator+(const Rect& a)
      {
         return a;
      }
      constexpr friend Rect operator-(const Rect& a)
      {
         return { -a.x,-a.y,-a.w,-a.h };
      }
/* Rect x Rect */
      constexpr friend Rect operator+(const Rect& a, const Rect& b)
      {
         return
         {
            a.x + b.x,
            a.y + b.y,
            a.w + b.w,
            a.h + b.h,
         };
      }
      constexpr friend Rect operator-(const Rect& a, const Rect& b)
      {
         return
         {
            a.x - b.x,
            a.y - b.y,
            a.w - b.w,
            a.h - b.h,
         };
      }
      constexpr friend Rect operator*(const Rect& a, const Rect& b)
      {
         return
         {
            a.x * b.x,
            a.y * b.y,
            a.w * b.w,
            a.h * b.h,
         };
      }
      constexpr friend Rect operator/(const Rect& a, const Rect& b)
      {
         return
         {
            a.x / b.x,
            a.y / b.y,
            a.w / b.w,
            a.h / b.h,
         };
      }
/* Rect x= Rect */
      constexpr friend Rect& operator+=(Rect& a, const Rect& b)
      {
         a.x += b.x;
         a.y += b.y;
         a.w += b.w;
         a.h += b.h;
         return a;
      }
      constexpr friend Rect& operator-=(Rect& a, const Rect& b)
      {
         a.x -= b.x;
         a.y -= b.y;
         a.w -= b.w;
         a.h -= b.h;
         return a;
      }
      constexpr friend Rect& operator*=(Rect& a, const Rect& b)
      {
         a.x *= b.x;
         a.y *= b.y;
         a.w *= b.w;
         a.h *= b.h;
         return a;
      }
      constexpr friend Rect& operator/=(Rect& a, const Rect& b)
      {
         a.x /= b.x;
         a.y /= b.y;
         a.w /= b.w;
         a.h /= b.h;
         return a;
      }
/* Comparison */
      constexpr friend bool operator==(const Rect& a, const Rect& b)
      {
         return a.x == b.x && a.y == b.y && a.w == b.w && a.h == b.h;
      }
      constexpr friend bool operator!=(const Rect& a, const Rect& b)
      {
         return a.x != b.x || a.y != b.y || a.w != b.w || a.h != b.h;
      }

      constexpr bool Contains(const Vector2<Scalar> p) const noexcept
      {
         return
            x <= p.x && p.x <= x + w &&
            y <= p.y && p.y <= y + h;
      }

      constexpr static bool Equal(const Rect& a, const Rect& b, Scalar epsilon)
      {
         return (
            Math::Abs(a.x - b.x) < epsilon &&
            Math::Abs(a.y - b.y) < epsilon &&
            Math::Abs(a.w - b.w) < epsilon &&
            Math::Abs(a.h - b.h) < epsilon);
      }
      template<typename T>
      constexpr friend std::basic_ostream<T> & operator<<(std::basic_ostream<T> & s, const Rect & a)
      {
         return s << '[' << a.x << ", " << a.y << ", " << a.w << ", " << a.h << ']';
      }
   };

   template<class Scalar> using FRect = const Rect<Scalar>&;
}
#endif