#ifndef _TL_VECTOR_H
#define _TL_VECTOR_H

#include "TLAttributes.h"
#include "TLSwitches.h"

#if TL_USE_SSE == 1
#include <xmmintrin.h>
#endif
#include <iostream>

#include "TLExceptions.h"
#include "TLMath.h"
#include "TLRandom.h"

namespace TLib

{
   template<class Scalar> struct Vector2;
   template<class Scalar> struct Vector3;
   template<class Scalar> struct Vector4;
   template<class Scalar> struct Matrix3x3;
   template<class Scalar> struct Matrix4x4;
}

#include "TLVector2.inl"
#include "TLVector3.inl"
#include "TLVector4.inl"
#include "TLMatrix3x3.inl"
#include "TLMatrix4x4.inl"

namespace TLib
{
   template<class T> using FVector2 = const Vector2<T>&;
   template<class T> using FVector3 = const Vector3<T>&;
   template<class T> using FVector4 = const Vector4<T>&;
   template<class T> using FMatrix3x3 = const Matrix3x3<T>&;
   template<class T> using FMatrix4x4 = const Matrix4x4<T>&;

   using Vec2f = Vector2<float>;
   using Vec3f = Vector3<float>;
   using Vec4f = Vector4<float>;
   using Mat3x3f = Matrix3x3<float>;
   using Mat4x4f = Matrix4x4<float>;

   using Vec2d = Vector2<double>;
   using Vec3d = Vector3<double>;
   using Vec4d = Vector4<double>;
   using Mat3x3d = Matrix3x3<double>;
   using Mat4x4d = Matrix4x4<double>;

   using Vec2ld = Vector2<long double>;
   using Vec3ld = Vector3<long double>;
   using Vec4ld = Vector4<long double>;
   using Mat3x3ld = Matrix3x3<long double>;
   using Mat4x4ld = Matrix4x4<long double>;

   using Vec3s = Vector3<short>;
   using Vec2s = Vector2<short>;
   using Vec4s = Vector4<short>;
   using Mat3x3s = Matrix3x3<short>;
   using Mat4x4s = Matrix4x4<short>;

   using Vec3i = Vector3<int>;
   using Vec2i = Vector2<int>;
   using Vec4i = Vector4<int>;
   using Mat3x3i = Matrix3x3<int>;
   using Mat4x4i = Matrix4x4<int>;

   using Vec3l = Vector3<long>;
   using Vec2l = Vector2<long>;
   using Vec4l = Vector4<long>;
   using Mat3x3l = Matrix3x3<long>;
   using Mat4x4l = Matrix4x4<long>;

   using Vec3ll = Vector3<long long>;
   using Vec2ll = Vector2<long long>;
   using Vec4ll = Vector4<long long>;
   using Mat3x3ll = Matrix3x3<long long>;
   using Mat4x4ll = Matrix4x4<long long>;

   namespace Math
   {
      template<class Scalar>
      TL_NODISCARD TL_CONSTEXPR Vector2<Scalar> Abs(const Vector2<Scalar>& a)
      {
         return
         {
            Abs(a.x),
            Abs(a.y)
         }
      }
      template<class Scalar>
      TL_NODISCARD TL_CONSTEXPR Vector3<Scalar> Abs(const Vector3<Scalar>& a)
      {
         return
         {
            Abs(a.x),
            Abs(a.y),
            Abs(a.z)
         }
      }
      template<class Scalar>
      TL_NODISCARD TL_CONSTEXPR Vector4<Scalar> Abs(const Vector4<Scalar>& a)
      {
         return
         {
            Abs(a.x),
            Abs(a.y),
            Abs(a.z),
            Abs(a.w)
         }
      }
      template<class Scalar>
      TL_NODISCARD TL_CONSTEXPR Scalar Area(Vector3<Scalar> a, 
                                            Vector3<Scalar> b, 
                                            Vector3<Scalar> c) TL_NOEXCEPT
      {
         auto ab = (a - b).Magnitude();
         auto ac = (a - c).Magnitude();
         auto cb = (c - b).Magnitude();
         auto p = (ab + ac + cb) * (Scalar)0.5;
         return Sqrt(p * (p - ab) * (p - ac) * (p - cb));
      }
      template<class Scalar>
      TL_NODISCARD TL_CONSTEXPR Vector3<Scalar> CalculateTangent(Vector3<Scalar> pa,
                                                                 Vector3<Scalar> pb,
                                                                 Vector3<Scalar> pc,
                                                                 Vector2<Scalar> ta,
                                                                 Vector2<Scalar> tb,
                                                                 Vector2<Scalar> tc) TL_NOEXCEPT
      {
         auto area = Area(pa, pb, pc);
         Vector3<Scalar> result;
         if (area != 0.0f)
         {
            float delta = 1.0f / area;
            auto distBA = pb - pa;
            auto distCA = pc - pa;
            auto tdistBA = tb - ta;
            auto tdistCA = tc - ta;
            result.x = delta * ((distBA.x * tdistCA.y) + (distCA.x * -tdistBA.y));
            result.y = delta * ((distBA.y * tdistCA.y) + (distCA.y * -tdistBA.y));
            result.z = delta * ((distBA.z * tdistCA.y) + (distCA.z * -tdistBA.y));
         }
         return result;
      }
   }

   template<class Vector, class Scalar = Vector::Scalar, class = std::enable_if_t<std::is_same_v<Vector, Vector4<Scalar>>>>
   Vector Random(Scalar min, Scalar max)
   {
      return
      {
         Random<Scalar>(min, max),
         Random<Scalar>(min, max),
         Random<Scalar>(min, max),
         Random<Scalar>(min, max)
      };
   }
}

#endif