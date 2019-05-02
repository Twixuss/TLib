namespace TLib
{
   template<class TScalar>
   struct Vector3
   {
      using Scalar = TScalar;
      using FScalar = const Scalar&;
      using Vector2 = Vector2<Scalar>;
      using Vector4 = Vector4<Scalar>;
      using FVector2 = const Vector2&;
      using FVector3 = const Vector3&;
      using FVector4 = const Vector4&;
      union
      {
         struct
         {
            Scalar x, y, z;
         };
         Scalar scl[3];
      };
#pragma region [ Constructors ]
      constexpr Vector3() noexcept :
         x( (Scalar)0 ),
         y( (Scalar)0 ),
         z( (Scalar)0 )
      {     
      }
      constexpr Vector3( FScalar v ) noexcept :
         x( v ),
         y( v ),
         z( v )
      {
      }
      constexpr Vector3( FScalar x, FScalar y ) noexcept :
         x( x ),
         y( y ),
         z()
      {
      }
      constexpr Vector3( FScalar x, FScalar y, FScalar z ) noexcept :
         x( x ),
         y( y ),
         z( z )
      {
      }
      constexpr Vector3( FVector2 v, FScalar z ) noexcept :
         x( v.x ),
         y( v.y ),
         z( z )
      {
      }
      constexpr Vector3( FScalar x, FVector2 v ) noexcept :
         x( x ),
         y( v.x ),
         z( v.y )
      {
      }
      constexpr Vector3( FVector3 ) = default;
      constexpr Vector3( Vector3&& ) = default;
      template<class Other>
      constexpr explicit Vector3( const Vector3<Other>& other ) noexcept :
         x( (Scalar) other.x ),
         y( (Scalar) other.y ),
         z( (Scalar) other.z )
      {
      }
#pragma endregion
#pragma region [ operator= ]
      constexpr Vector3& operator=( FVector3 ) = default;
      constexpr Vector3& operator=( Vector3&& ) = default;
#pragma endregion
      [[nodiscard]] constexpr Scalar SqrMagnitude() const noexcept
      {
         return x * x + y * y + z * z;
      }
      template<class ConvertTo = Scalar>
      [[nodiscard]] constexpr ConvertTo Magnitude() const noexcept
      {
         return Math::Sqrt( (ConvertTo)SqrMagnitude() );
      }
      template<class ConvertTo = Scalar>
      [[nodiscard]] constexpr Vector3<ConvertTo> Normalized() const noexcept
      {
         return (Vector3<ConvertTo>)*this / Magnitude<ConvertTo>();
      }
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
#pragma region [ Element reorder ]
      [[nodiscard]] constexpr Vector2 xx() const noexcept { return { x, x }; }
      [[nodiscard]] constexpr Vector2 xy() const noexcept { return { x, y }; }
      [[nodiscard]] constexpr Vector2 xz() const noexcept { return { x, z }; }
      [[nodiscard]] constexpr Vector2 yx() const noexcept { return { y, x }; }
      [[nodiscard]] constexpr Vector2 yy() const noexcept { return { y, y }; }
      [[nodiscard]] constexpr Vector2 yz() const noexcept { return { y, z }; }
      [[nodiscard]] constexpr Vector2 zx() const noexcept { return { z, x }; }
      [[nodiscard]] constexpr Vector2 zy() const noexcept { return { z, y }; }
      [[nodiscard]] constexpr Vector2 zz() const noexcept { return { z, z }; }
      [[nodiscard]] constexpr Vector3 xxx() const noexcept { return { x, x, x }; }
      [[nodiscard]] constexpr Vector3 xxy() const noexcept { return { x, x, y }; }
      [[nodiscard]] constexpr Vector3 xxz() const noexcept { return { x, x, z }; }
      [[nodiscard]] constexpr Vector3 xyx() const noexcept { return { x, y, x }; }
      [[nodiscard]] constexpr Vector3 xyy() const noexcept { return { x, y, y }; }
      [[nodiscard]] constexpr Vector3 xyz() const noexcept { return { x, y, z }; }
      [[nodiscard]] constexpr Vector3 xzx() const noexcept { return { x, z, x }; }
      [[nodiscard]] constexpr Vector3 xzy() const noexcept { return { x, z, y }; }
      [[nodiscard]] constexpr Vector3 xzz() const noexcept { return { x, z, z }; }
      [[nodiscard]] constexpr Vector3 yxx() const noexcept { return { y, x, x }; }
      [[nodiscard]] constexpr Vector3 yxy() const noexcept { return { y, x, y }; }
      [[nodiscard]] constexpr Vector3 yxz() const noexcept { return { y, x, z }; }
      [[nodiscard]] constexpr Vector3 yyx() const noexcept { return { y, y, x }; }
      [[nodiscard]] constexpr Vector3 yyy() const noexcept { return { y, y, y }; }
      [[nodiscard]] constexpr Vector3 yyz() const noexcept { return { y, y, z }; }
      [[nodiscard]] constexpr Vector3 yzx() const noexcept { return { y, z, x }; }
      [[nodiscard]] constexpr Vector3 yzy() const noexcept { return { y, z, y }; }
      [[nodiscard]] constexpr Vector3 yzz() const noexcept { return { y, z, z }; }
      [[nodiscard]] constexpr Vector3 zxx() const noexcept { return { z, x, x }; }
      [[nodiscard]] constexpr Vector3 zxy() const noexcept { return { z, x, y }; }
      [[nodiscard]] constexpr Vector3 zxz() const noexcept { return { z, x, z }; }
      [[nodiscard]] constexpr Vector3 zyx() const noexcept { return { z, y, x }; }
      [[nodiscard]] constexpr Vector3 zyy() const noexcept { return { z, y, y }; }
      [[nodiscard]] constexpr Vector3 zyz() const noexcept { return { z, y, z }; }
      [[nodiscard]] constexpr Vector3 zzx() const noexcept { return { z, z, x }; }
      [[nodiscard]] constexpr Vector3 zzy() const noexcept { return { z, z, y }; }
      [[nodiscard]] constexpr Vector3 zzz() const noexcept { return { z, z, z }; }
      [[nodiscard]] constexpr Vector4 xxxx() const noexcept { return { x, x, x, x }; }
      [[nodiscard]] constexpr Vector4 xxxy() const noexcept { return { x, x, x, y }; }
      [[nodiscard]] constexpr Vector4 xxxz() const noexcept { return { x, x, x, z }; }
      [[nodiscard]] constexpr Vector4 xxyx() const noexcept { return { x, x, y, x }; }
      [[nodiscard]] constexpr Vector4 xxyy() const noexcept { return { x, x, y, y }; }
      [[nodiscard]] constexpr Vector4 xxyz() const noexcept { return { x, x, y, z }; }
      [[nodiscard]] constexpr Vector4 xxzx() const noexcept { return { x, x, z, x }; }
      [[nodiscard]] constexpr Vector4 xxzy() const noexcept { return { x, x, z, y }; }
      [[nodiscard]] constexpr Vector4 xxzz() const noexcept { return { x, x, z, z }; }
      [[nodiscard]] constexpr Vector4 xyxx() const noexcept { return { x, y, x, x }; }
      [[nodiscard]] constexpr Vector4 xyxy() const noexcept { return { x, y, x, y }; }
      [[nodiscard]] constexpr Vector4 xyxz() const noexcept { return { x, y, x, z }; }
      [[nodiscard]] constexpr Vector4 xyyx() const noexcept { return { x, y, y, x }; }
      [[nodiscard]] constexpr Vector4 xyyy() const noexcept { return { x, y, y, y }; }
      [[nodiscard]] constexpr Vector4 xyyz() const noexcept { return { x, y, y, z }; }
      [[nodiscard]] constexpr Vector4 xyzx() const noexcept { return { x, y, z, x }; }
      [[nodiscard]] constexpr Vector4 xyzy() const noexcept { return { x, y, z, y }; }
      [[nodiscard]] constexpr Vector4 xyzz() const noexcept { return { x, y, z, z }; }
      [[nodiscard]] constexpr Vector4 xzxx() const noexcept { return { x, z, x, x }; }
      [[nodiscard]] constexpr Vector4 xzxy() const noexcept { return { x, z, x, y }; }
      [[nodiscard]] constexpr Vector4 xzxz() const noexcept { return { x, z, x, z }; }
      [[nodiscard]] constexpr Vector4 xzyx() const noexcept { return { x, z, y, x }; }
      [[nodiscard]] constexpr Vector4 xzyy() const noexcept { return { x, z, y, y }; }
      [[nodiscard]] constexpr Vector4 xzyz() const noexcept { return { x, z, y, z }; }
      [[nodiscard]] constexpr Vector4 xzzx() const noexcept { return { x, z, z, x }; }
      [[nodiscard]] constexpr Vector4 xzzy() const noexcept { return { x, z, z, y }; }
      [[nodiscard]] constexpr Vector4 xzzz() const noexcept { return { x, z, z, z }; }
      [[nodiscard]] constexpr Vector4 yxxx() const noexcept { return { y, x, x, x }; }
      [[nodiscard]] constexpr Vector4 yxxy() const noexcept { return { y, x, x, y }; }
      [[nodiscard]] constexpr Vector4 yxxz() const noexcept { return { y, x, x, z }; }
      [[nodiscard]] constexpr Vector4 yxyx() const noexcept { return { y, x, y, x }; }
      [[nodiscard]] constexpr Vector4 yxyy() const noexcept { return { y, x, y, y }; }
      [[nodiscard]] constexpr Vector4 yxyz() const noexcept { return { y, x, y, z }; }
      [[nodiscard]] constexpr Vector4 yxzx() const noexcept { return { y, x, z, x }; }
      [[nodiscard]] constexpr Vector4 yxzy() const noexcept { return { y, x, z, y }; }
      [[nodiscard]] constexpr Vector4 yxzz() const noexcept { return { y, x, z, z }; }
      [[nodiscard]] constexpr Vector4 yyxx() const noexcept { return { y, y, x, x }; }
      [[nodiscard]] constexpr Vector4 yyxy() const noexcept { return { y, y, x, y }; }
      [[nodiscard]] constexpr Vector4 yyxz() const noexcept { return { y, y, x, z }; }
      [[nodiscard]] constexpr Vector4 yyyx() const noexcept { return { y, y, y, x }; }
      [[nodiscard]] constexpr Vector4 yyyy() const noexcept { return { y, y, y, y }; }
      [[nodiscard]] constexpr Vector4 yyyz() const noexcept { return { y, y, y, z }; }
      [[nodiscard]] constexpr Vector4 yyzx() const noexcept { return { y, y, z, x }; }
      [[nodiscard]] constexpr Vector4 yyzy() const noexcept { return { y, y, z, y }; }
      [[nodiscard]] constexpr Vector4 yyzz() const noexcept { return { y, y, z, z }; }
      [[nodiscard]] constexpr Vector4 yzxx() const noexcept { return { y, z, x, x }; }
      [[nodiscard]] constexpr Vector4 yzxy() const noexcept { return { y, z, x, y }; }
      [[nodiscard]] constexpr Vector4 yzxz() const noexcept { return { y, z, x, z }; }
      [[nodiscard]] constexpr Vector4 yzyx() const noexcept { return { y, z, y, x }; }
      [[nodiscard]] constexpr Vector4 yzyy() const noexcept { return { y, z, y, y }; }
      [[nodiscard]] constexpr Vector4 yzyz() const noexcept { return { y, z, y, z }; }
      [[nodiscard]] constexpr Vector4 yzzx() const noexcept { return { y, z, z, x }; }
      [[nodiscard]] constexpr Vector4 yzzy() const noexcept { return { y, z, z, y }; }
      [[nodiscard]] constexpr Vector4 yzzz() const noexcept { return { y, z, z, z }; }
      [[nodiscard]] constexpr Vector4 zxxx() const noexcept { return { z, x, x, x }; }
      [[nodiscard]] constexpr Vector4 zxxy() const noexcept { return { z, x, x, y }; }
      [[nodiscard]] constexpr Vector4 zxxz() const noexcept { return { z, x, x, z }; }
      [[nodiscard]] constexpr Vector4 zxyx() const noexcept { return { z, x, y, x }; }
      [[nodiscard]] constexpr Vector4 zxyy() const noexcept { return { z, x, y, y }; }
      [[nodiscard]] constexpr Vector4 zxyz() const noexcept { return { z, x, y, z }; }
      [[nodiscard]] constexpr Vector4 zxzx() const noexcept { return { z, x, z, x }; }
      [[nodiscard]] constexpr Vector4 zxzy() const noexcept { return { z, x, z, y }; }
      [[nodiscard]] constexpr Vector4 zxzz() const noexcept { return { z, x, z, z }; }
      [[nodiscard]] constexpr Vector4 zyxx() const noexcept { return { z, y, x, x }; }
      [[nodiscard]] constexpr Vector4 zyxy() const noexcept { return { z, y, x, y }; }
      [[nodiscard]] constexpr Vector4 zyxz() const noexcept { return { z, y, x, z }; }
      [[nodiscard]] constexpr Vector4 zyyx() const noexcept { return { z, y, y, x }; }
      [[nodiscard]] constexpr Vector4 zyyy() const noexcept { return { z, y, y, y }; }
      [[nodiscard]] constexpr Vector4 zyyz() const noexcept { return { z, y, y, z }; }
      [[nodiscard]] constexpr Vector4 zyzx() const noexcept { return { z, y, z, x }; }
      [[nodiscard]] constexpr Vector4 zyzy() const noexcept { return { z, y, z, y }; }
      [[nodiscard]] constexpr Vector4 zyzz() const noexcept { return { z, y, z, z }; }
      [[nodiscard]] constexpr Vector4 zzxx() const noexcept { return { z, z, x, x }; }
      [[nodiscard]] constexpr Vector4 zzxy() const noexcept { return { z, z, x, y }; }
      [[nodiscard]] constexpr Vector4 zzxz() const noexcept { return { z, z, x, z }; }
      [[nodiscard]] constexpr Vector4 zzyx() const noexcept { return { z, z, y, x }; }
      [[nodiscard]] constexpr Vector4 zzyy() const noexcept { return { z, z, y, y }; }
      [[nodiscard]] constexpr Vector4 zzyz() const noexcept { return { z, z, y, z }; }
      [[nodiscard]] constexpr Vector4 zzzx() const noexcept { return { z, z, z, x }; }
      [[nodiscard]] constexpr Vector4 zzzy() const noexcept { return { z, z, z, y }; }
      [[nodiscard]] constexpr Vector4 zzzz() const noexcept { return { z, z, z, z }; }
#pragma endregion
      [[nodiscard]] constexpr static bool Equal( FVector3 a, FVector3 b, FScalar epsilon ) noexcept
      {
         return (
            Math::Abs( a.x - b.x ) < epsilon &&
            Math::Abs( a.y - b.y ) < epsilon &&
            Math::Abs( a.z - b.z ) < epsilon );
      }
      [[nodiscard]] constexpr static Vector3 Cross( FVector3 a, FVector3 b ) noexcept
      {
         return
         {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
         };
      }
      [[nodiscard]] constexpr static Scalar Dot( FVector3 a, FVector3 b ) noexcept
      {
         return a.x * b.x + a.y * b.y + a.z * b.z;
      }
#pragma region [ op Vec ]
      [[nodiscard]] constexpr friend Vector3 operator+( FVector3 a ) noexcept
      {
         return a;
      }
      [[nodiscard]] constexpr friend Vector3 operator-( FVector3 a ) noexcept
      {
         return { -a.x,-a.y,-a.z };
      }
#pragma endregion
#pragma region [ Vec op Vec ]
      [[nodiscard]] constexpr friend Vector3 operator+( FVector3 a, FVector3 b ) noexcept
      {
         return
         {
            a.x + b.x,
            a.y + b.y,
            a.z + b.z
         };
      }
      [[nodiscard]] constexpr friend Vector3 operator-( FVector3 a, FVector3 b ) noexcept
      {
         return
         {
            a.x - b.x,
            a.y - b.y,
            a.z - b.z
         };
      }
      [[nodiscard]] constexpr friend Vector3 operator*( FVector3 a, FVector3 b ) noexcept
      {
         return
         {
            a.x * b.x,
            a.y * b.y,
            a.z * b.z
         };
      }
      [[nodiscard]] constexpr friend Vector3 operator/( FVector3 a, FVector3 b ) noexcept
      {
         return
         {
            a.x / b.x,
            a.y / b.y,
            a.z / b.z
         };
      }
#pragma endregion
#pragma region [ Vec op= Vec ]
      constexpr friend Vector3& operator+=( Vector3& a, FVector3 b ) noexcept
      {
         a.x += b.x;
         a.y += b.y;
         a.z += b.z;
         return a;
      }
      constexpr friend Vector3& operator-=( Vector3& a, FVector3 b ) noexcept
      {
         a.x -= b.x;
         a.y -= b.y;
         a.z -= b.z;
         return a;
      }
      constexpr friend Vector3& operator*=( Vector3& a, FVector3 b ) noexcept
      {
         a.x *= b.x;
         a.y *= b.y;
         a.z *= b.z;
         return a;
      }
      constexpr friend Vector3& operator/=( Vector3& a, FVector3 b ) noexcept
      {
         a.x /= b.x;
         a.y /= b.y;
         a.z /= b.z;
         return a;
      }
#pragma endregion
#pragma region [ Comparison ]
      [[nodiscard]] constexpr friend bool operator==( FVector3 a, FVector3 b ) noexcept
      {
         return a.x == b.x && a.y == b.y && a.z == b.z;
      }
      [[nodiscard]] constexpr friend bool operator!=( FVector3 a, FVector3 b ) noexcept
      {
         return a.x != b.x || a.y != b.y || a.z != b.z;
      }
#pragma endregion
      template<typename T>
      constexpr friend std::basic_ostream<T>& operator<<( std::basic_ostream<T> & s, FVector3 v ) noexcept
      {
         return s << '[' << v.x << ", " << v.y << ", " << v.z << ']';
      }
   };
}