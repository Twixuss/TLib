namespace TLib
{
   template<class Scalar_>
   struct Matrix3x3
   {
      using Scalar = Scalar_;
      using FScalar = const Scalar&;
      using Vector3 = Vector3<Scalar>;
      using FVector3 = const Vector3&;
      using FMatrix3x3 = const Matrix3x3&;
      union
      {
         struct
         {
            Vector3 i, j, k;
         };
         Vector3 vec[3];
         Scalar scl[3][3];
      };
      constexpr Matrix3x3() = default;
      constexpr Matrix3x3( FScalar v ) noexcept :
         i( v ),
         j( v ),
         k( v )
      {
      }
      constexpr Matrix3x3( FScalar ix, FScalar iy, FScalar iz,
                           FScalar jx, FScalar jy, FScalar jz,
                           FScalar kx, FScalar ky, FScalar kz ) noexcept :
         i( ix, iy, iz ),
         j( jx, jy, jz ),
         k( kx, ky, kz )
      {
      }
      constexpr Matrix3x3( FVector3 v ) noexcept :
         i( v ),
         j( v ),
         k( v )
      {
      }
      constexpr Matrix3x3( FVector3 i, FVector3 j, FVector3 k ) noexcept :
         i( i ),
         j( j ),
         k( k )
      {
      }
      constexpr Matrix3x3( FMatrix3x3 ) = default;
      constexpr Matrix3x3( Matrix3x3&& ) = default;

      constexpr Matrix3x3& operator=( FMatrix3x3 ) = default;
      constexpr Matrix3x3& operator=( Matrix3x3&& ) = default;
#pragma region [ Data ]
      [[nodiscard]] constexpr Scalar* Data() noexcept
      {
         return scl;
      }
      [[nodiscard]] constexpr const Scalar* Data() const noexcept
      {
         return scl;
      }
#pragma endregion
      constexpr Matrix3x3 Transposed() noexcept
      {
         return {
            i.x, j.x, k.x,
            i.y, j.y, k.y,
            i.z, j.z, k.z
         };
      }
      constexpr friend Vector3 operator*( FMatrix3x3 a, FVector3 b ) noexcept
      {
         return
         {
            a.i.x * b.x + a.j.x * b.y + a.k.x * b.z,
            a.i.y * b.x + a.j.y * b.y + a.k.y * b.z,
            a.i.z * b.x + a.j.z * b.y + a.k.z * b.z,
         };
      }
      constexpr friend Matrix3x3 operator*( FMatrix3x3 a, FMatrix3x3 b ) noexcept
      {
         return
         {
            a * b.i,
            a * b.j,
            a * b.k
         };
      }
      constexpr static Matrix3x3 Identity() noexcept
      {
         return
         {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
         };
      }
      constexpr static Matrix3x3 RotationX( FScalar a ) noexcept
      {
         return
         {
            1, 0       , 0       ,
            0, cos( a ), sin( a ),
            0,-sin( a ), cos( a )
         };
      }
      constexpr static Matrix3x3 RotationY( FScalar a ) noexcept
      {
         return
         {
            cos( a ), 0, sin( a ),
            0       , 1, 0       ,
            -sin( a ), 0, cos( a )
         };
      }
      constexpr static Matrix3x3 RotationZ( FScalar a ) noexcept
      {
         return
         {
            cos( a ), sin( a ), 0,
            -sin( a ), cos( a ), 0,
            0       , 0       , 1
         };
      }
      //Roll, Pitch, Yaw (ZXY)
      constexpr static Matrix3x3 RotationZXY( FVector3 v ) noexcept
      {
         return ( RotationY( v.y ) * RotationX( v.x ) )* RotationZ( v.z );
      }
      //Yaw, Pitch, Roll (YXZ)
      constexpr static Matrix3x3 RotationYXZ( FVector3 v ) noexcept
      {
         return ( RotationZ( v.z ) * RotationX( v.x ) )* RotationY( v.y );
      }
      template<typename T>
      friend std::basic_ostream<T>& operator<<( std::basic_ostream<T>& s, FMatrix3x3 m ) noexcept
      {
         return s << m.i << '\n' << m.j << '\n' << m.k;
      }
   };
}