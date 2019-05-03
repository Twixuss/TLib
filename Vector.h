#ifndef _TLIB_VECTOR_H
#define _TLIB_VECTOR_H

#include "Switches.h"
#include "Math.h"

#if TL_USE_SSE == 1
#include <xmmintrin.h>
#endif
#include <iostream>

namespace TLib
{
   template<class TScalar> struct Vector2;
   template<class TScalar> struct Vector3;
   template<class TScalar> struct Vector4;
   template<class TScalar> struct Matrix3x3;
   template<class TScalar> struct Matrix4x4;
}

#include "Vector2.inl"
#include "Vector3.inl"
#include "Vector4.inl"
#include "Matrix3x3.inl"
#include "Matrix4x4.inl"

namespace TLib
{
   template<class Scalar> using FVector2 = const Vector2<Scalar> &;
   template<class Scalar> using FVector3 = const Vector3<Scalar> &;
   template<class Scalar> using FVector4 = const Vector4<Scalar> &;
   template<class Scalar> using FMatrix3x3 = const Matrix3x3<Scalar> &;
   template<class Scalar> using FMatrix4x4 = const Matrix4x4<Scalar> &;

   using Vec2f = Vector2<float>;
   using Vec3f = Vector3<float>;
   using Vec4f = Vector4<float>;
   using Mat3x3f = Matrix3x3<float>;
   using Mat4x4f = Matrix4x4<float>;

   using FVec2f = FVector2<float>;
   using FVec3f = FVector3<float>;
   using FVec4f = FVector4<float>;
   using FMat3x3f = FMatrix3x3<float>;
   using FMat4x4f = FMatrix4x4<float>;

   using Vec3i = Vector3<int>;
   using Vec2i = Vector2<int>;
   using Vec4i = Vector4<int>;
   using Mat3x3i = Matrix3x3<int>;
   using Mat4x4i = Matrix4x4<int>;

   using FVec3i = FVector3<int>;
   using FVec2i = FVector2<int>;
   using FVec4i = FVector4<int>;
   using FMat3x3i = FMatrix3x3<int>;
   using FMat4x4i = FMatrix4x4<int>;
   namespace Math
   {
      template<class Scalar>
      constexpr Scalar Area( FVector3<Scalar> a, FVector3<Scalar> b, FVector3<Scalar> c )
      {
         auto ab = ( a - b ).Magnitude();
         auto ac = ( a - c ).Magnitude();
         auto cb = ( c - b ).Magnitude();
         auto p = ( ab + ac + cb ) * ( Scalar )0.5;
         return Sqrt( p * ( p - ab ) * ( p - ac ) * ( p - cb ) );
      }
      template<class Scalar>
      constexpr Vector3<Scalar> CalculateTangent( FVector3<Scalar> pa,
                                                  FVector3<Scalar> pb,
                                                  FVector3<Scalar> pc,
                                                  FVector2<Scalar> ta,
                                                  FVector2<Scalar> tb,
                                                  FVector2<Scalar> tc )
      {
         auto area = Area( pa, pb, pc );
         if ( area != 0.0f )
         {
            float delta = 1.0f / area;
            auto distBA = pb - pa;
            auto distCA = pc - pa;
            auto tdistBA = tb - ta;
            auto tdistCA = tc - ta;
            // Calculates the face tangent to the current triangle.
            return
            {
               delta * ( ( distBA.x * tdistCA.y ) + ( distCA.x * -tdistBA.y ) ),
               delta * ( ( distBA.y * tdistCA.y ) + ( distCA.y * -tdistBA.y ) ),
               delta * ( ( distBA.z * tdistCA.y ) + ( distCA.z * -tdistBA.y ) )
            };
         }
         return{};
      }
   }
}

#endif