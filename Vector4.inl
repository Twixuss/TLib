namespace TLib
{
   template<class TScalar>
   struct Vector4
   {
      using Scalar = TScalar;
      using FScalar = const Scalar&;
      using Vector2 = Vector2<Scalar>;
      using Vector3 = Vector3<Scalar>;
      using FVector2 = const Vector2&;
      using FVector3 = const Vector3&;
      using FVector4 = const Vector4&;
      union
      {
         struct
         {
            Scalar x, y, z, w;
         };
         Scalar scl[4];
      };
#pragma region [ Constructors ]
      constexpr Vector4() noexcept :
         x( (Scalar)0 ),
         y( (Scalar)0 ),
         z( (Scalar)0 ),
         w( (Scalar)0 )
      {     
      }
      constexpr Vector4( FScalar v ) noexcept :
         x( v ),
         y( v ),
         z( v ),
         w( v )
      {
      }
      constexpr Vector4( FScalar x, FScalar y ) noexcept :
         x( x ),
         y( y ),
         z(),
         w()
      {
      }
      constexpr Vector4( FScalar x, FScalar y, FScalar z ) noexcept :
         x( x ),
         y( y ),
         z( z ),
         w()
      {
      }
      constexpr Vector4( FScalar x, FScalar y, FScalar z, FScalar w ) noexcept :
         x( x ),
         y( y ),
         z( z ),
         w( w )
      {
      }
      constexpr Vector4( FVector3 v ) noexcept :
         x( v.x ),
         y( v.y ),
         z( v.z ),
         w()
      {
      }
      constexpr Vector4( FVector3 v, FScalar w )  noexcept :
         x( v.x ),
         y( v.y ),
         z( v.z ),
         w( w )
      {
      }
      constexpr Vector4( FScalar x, FVector3 v )  noexcept :
         x( x ),
         y( v.x ),
         z( v.y ),
         w( v.z )
      {
      }
      constexpr Vector4( FVector2 v ) noexcept :
         x( v.x ),
         y( v.y ),
         z(),
         w()
      {
      }
      constexpr Vector4( FVector2 v, FScalar z, FScalar w )  noexcept :
         x( v.x ),
         y( v.y ),
         z( z ),
         w( w )
      {
      }
      constexpr Vector4( FScalar x, FVector2 v, FScalar w )  noexcept :
         x( x ),
         y( v.x ),
         z( v.y ),
         w( w )
      {
      }
      constexpr Vector4( FScalar x, FScalar y, FVector2 v )  noexcept :
         x( x ),
         y( y ),
         z( v.x ),
         w( v.y )
      {
      }
      constexpr Vector4( FVector2 a, FVector2 b )  noexcept :
         x( a.x ),
         y( a.y ),
         z( b.x ),
         w( b.y )
      {
      }
      constexpr Vector4( FVector4 ) = default;
      constexpr Vector4( Vector4&& ) = default;
      template<class Other>
      constexpr explicit Vector4( const Vector4<Other>& other ) noexcept :
         x( (Scalar) other.x ),
         y( (Scalar) other.y ),
         z( (Scalar) other.z ),
         w( (Scalar) other.w )
      {
      }
#pragma endregion
#pragma region [ operator= ]
      constexpr Vector4& operator=( FVector4 ) = default;
      constexpr Vector4& operator=( Vector4&& ) = default;
#pragma endregion
      [[nodiscard]] constexpr Scalar SqrMagnitude() const noexcept
      {
         return x * x + y * y + z * z + w * w;
      }
      template<class ConvertTo = Scalar>
      [[nodiscard]] constexpr ConvertTo Magnitude() const noexcept
      {
         return Math::Sqrt( (ConvertTo)SqrMagnitude() );
      }
      template<class ConvertTo = Scalar>
      [[nodiscard]] constexpr Vector4<ConvertTo> Normalized() const noexcept
      {
         return (Vector4<ConvertTo>)*this / Magnitude<ConvertTo>();
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
      [[nodiscard]] constexpr Vector4 xxxw() const noexcept { return { x, x, x, w }; }
      [[nodiscard]] constexpr Vector4 xxyx() const noexcept { return { x, x, y, x }; }
      [[nodiscard]] constexpr Vector4 xxyy() const noexcept { return { x, x, y, y }; }
      [[nodiscard]] constexpr Vector4 xxyz() const noexcept { return { x, x, y, z }; }
      [[nodiscard]] constexpr Vector4 xxyw() const noexcept { return { x, x, y, w }; }
      [[nodiscard]] constexpr Vector4 xxzx() const noexcept { return { x, x, z, x }; }
      [[nodiscard]] constexpr Vector4 xxzy() const noexcept { return { x, x, z, y }; }
      [[nodiscard]] constexpr Vector4 xxzz() const noexcept { return { x, x, z, z }; }
      [[nodiscard]] constexpr Vector4 xxzw() const noexcept { return { x, x, z, w }; }
      [[nodiscard]] constexpr Vector4 xxwx() const noexcept { return { x, x, w, x }; }
      [[nodiscard]] constexpr Vector4 xxwy() const noexcept { return { x, x, w, y }; }
      [[nodiscard]] constexpr Vector4 xxwz() const noexcept { return { x, x, w, z }; }
      [[nodiscard]] constexpr Vector4 xxww() const noexcept { return { x, x, w, w }; }
      [[nodiscard]] constexpr Vector4 xyxx() const noexcept { return { x, y, x, x }; }
      [[nodiscard]] constexpr Vector4 xyxy() const noexcept { return { x, y, x, y }; }
      [[nodiscard]] constexpr Vector4 xyxz() const noexcept { return { x, y, x, z }; }
      [[nodiscard]] constexpr Vector4 xyxw() const noexcept { return { x, y, x, w }; }
      [[nodiscard]] constexpr Vector4 xyyx() const noexcept { return { x, y, y, x }; }
      [[nodiscard]] constexpr Vector4 xyyy() const noexcept { return { x, y, y, y }; }
      [[nodiscard]] constexpr Vector4 xyyz() const noexcept { return { x, y, y, z }; }
      [[nodiscard]] constexpr Vector4 xyyw() const noexcept { return { x, y, y, w }; }
      [[nodiscard]] constexpr Vector4 xyzx() const noexcept { return { x, y, z, x }; }
      [[nodiscard]] constexpr Vector4 xyzy() const noexcept { return { x, y, z, y }; }
      [[nodiscard]] constexpr Vector4 xyzz() const noexcept { return { x, y, z, z }; }
      [[nodiscard]] constexpr Vector4 xyzw() const noexcept { return { x, y, z, w }; }
      [[nodiscard]] constexpr Vector4 xywx() const noexcept { return { x, y, w, x }; }
      [[nodiscard]] constexpr Vector4 xywy() const noexcept { return { x, y, w, y }; }
      [[nodiscard]] constexpr Vector4 xywz() const noexcept { return { x, y, w, z }; }
      [[nodiscard]] constexpr Vector4 xyww() const noexcept { return { x, y, w, w }; }
      [[nodiscard]] constexpr Vector4 xzxx() const noexcept { return { x, z, x, x }; }
      [[nodiscard]] constexpr Vector4 xzxy() const noexcept { return { x, z, x, y }; }
      [[nodiscard]] constexpr Vector4 xzxz() const noexcept { return { x, z, x, z }; }
      [[nodiscard]] constexpr Vector4 xzxw() const noexcept { return { x, z, x, w }; }
      [[nodiscard]] constexpr Vector4 xzyx() const noexcept { return { x, z, y, x }; }
      [[nodiscard]] constexpr Vector4 xzyy() const noexcept { return { x, z, y, y }; }
      [[nodiscard]] constexpr Vector4 xzyz() const noexcept { return { x, z, y, z }; }
      [[nodiscard]] constexpr Vector4 xzyw() const noexcept { return { x, z, y, w }; }
      [[nodiscard]] constexpr Vector4 xzzx() const noexcept { return { x, z, z, x }; }
      [[nodiscard]] constexpr Vector4 xzzy() const noexcept { return { x, z, z, y }; }
      [[nodiscard]] constexpr Vector4 xzzz() const noexcept { return { x, z, z, z }; }
      [[nodiscard]] constexpr Vector4 xzzw() const noexcept { return { x, z, z, w }; }
      [[nodiscard]] constexpr Vector4 xzwx() const noexcept { return { x, z, w, x }; }
      [[nodiscard]] constexpr Vector4 xzwy() const noexcept { return { x, z, w, y }; }
      [[nodiscard]] constexpr Vector4 xzwz() const noexcept { return { x, z, w, z }; }
      [[nodiscard]] constexpr Vector4 xzww() const noexcept { return { x, z, w, w }; }
      [[nodiscard]] constexpr Vector4 xwxx() const noexcept { return { x, w, x, x }; }
      [[nodiscard]] constexpr Vector4 xwxy() const noexcept { return { x, w, x, y }; }
      [[nodiscard]] constexpr Vector4 xwxz() const noexcept { return { x, w, x, z }; }
      [[nodiscard]] constexpr Vector4 xwxw() const noexcept { return { x, w, x, w }; }
      [[nodiscard]] constexpr Vector4 xwyx() const noexcept { return { x, w, y, x }; }
      [[nodiscard]] constexpr Vector4 xwyy() const noexcept { return { x, w, y, y }; }
      [[nodiscard]] constexpr Vector4 xwyz() const noexcept { return { x, w, y, z }; }
      [[nodiscard]] constexpr Vector4 xwyw() const noexcept { return { x, w, y, w }; }
      [[nodiscard]] constexpr Vector4 xwzx() const noexcept { return { x, w, z, x }; }
      [[nodiscard]] constexpr Vector4 xwzy() const noexcept { return { x, w, z, y }; }
      [[nodiscard]] constexpr Vector4 xwzz() const noexcept { return { x, w, z, z }; }
      [[nodiscard]] constexpr Vector4 xwzw() const noexcept { return { x, w, z, w }; }
      [[nodiscard]] constexpr Vector4 xwwx() const noexcept { return { x, w, w, x }; }
      [[nodiscard]] constexpr Vector4 xwwy() const noexcept { return { x, w, w, y }; }
      [[nodiscard]] constexpr Vector4 xwwz() const noexcept { return { x, w, w, z }; }
      [[nodiscard]] constexpr Vector4 xwww() const noexcept { return { x, w, w, w }; }
      [[nodiscard]] constexpr Vector4 yxxx() const noexcept { return { y, x, x, x }; }
      [[nodiscard]] constexpr Vector4 yxxy() const noexcept { return { y, x, x, y }; }
      [[nodiscard]] constexpr Vector4 yxxz() const noexcept { return { y, x, x, z }; }
      [[nodiscard]] constexpr Vector4 yxxw() const noexcept { return { y, x, x, w }; }
      [[nodiscard]] constexpr Vector4 yxyx() const noexcept { return { y, x, y, x }; }
      [[nodiscard]] constexpr Vector4 yxyy() const noexcept { return { y, x, y, y }; }
      [[nodiscard]] constexpr Vector4 yxyz() const noexcept { return { y, x, y, z }; }
      [[nodiscard]] constexpr Vector4 yxyw() const noexcept { return { y, x, y, w }; }
      [[nodiscard]] constexpr Vector4 yxzx() const noexcept { return { y, x, z, x }; }
      [[nodiscard]] constexpr Vector4 yxzy() const noexcept { return { y, x, z, y }; }
      [[nodiscard]] constexpr Vector4 yxzz() const noexcept { return { y, x, z, z }; }
      [[nodiscard]] constexpr Vector4 yxzw() const noexcept { return { y, x, z, w }; }
      [[nodiscard]] constexpr Vector4 yxwx() const noexcept { return { y, x, w, x }; }
      [[nodiscard]] constexpr Vector4 yxwy() const noexcept { return { y, x, w, y }; }
      [[nodiscard]] constexpr Vector4 yxwz() const noexcept { return { y, x, w, z }; }
      [[nodiscard]] constexpr Vector4 yxww() const noexcept { return { y, x, w, w }; }
      [[nodiscard]] constexpr Vector4 yyxx() const noexcept { return { y, y, x, x }; }
      [[nodiscard]] constexpr Vector4 yyxy() const noexcept { return { y, y, x, y }; }
      [[nodiscard]] constexpr Vector4 yyxz() const noexcept { return { y, y, x, z }; }
      [[nodiscard]] constexpr Vector4 yyxw() const noexcept { return { y, y, x, w }; }
      [[nodiscard]] constexpr Vector4 yyyx() const noexcept { return { y, y, y, x }; }
      [[nodiscard]] constexpr Vector4 yyyy() const noexcept { return { y, y, y, y }; }
      [[nodiscard]] constexpr Vector4 yyyz() const noexcept { return { y, y, y, z }; }
      [[nodiscard]] constexpr Vector4 yyyw() const noexcept { return { y, y, y, w }; }
      [[nodiscard]] constexpr Vector4 yyzx() const noexcept { return { y, y, z, x }; }
      [[nodiscard]] constexpr Vector4 yyzy() const noexcept { return { y, y, z, y }; }
      [[nodiscard]] constexpr Vector4 yyzz() const noexcept { return { y, y, z, z }; }
      [[nodiscard]] constexpr Vector4 yyzw() const noexcept { return { y, y, z, w }; }
      [[nodiscard]] constexpr Vector4 yywx() const noexcept { return { y, y, w, x }; }
      [[nodiscard]] constexpr Vector4 yywy() const noexcept { return { y, y, w, y }; }
      [[nodiscard]] constexpr Vector4 yywz() const noexcept { return { y, y, w, z }; }
      [[nodiscard]] constexpr Vector4 yyww() const noexcept { return { y, y, w, w }; }
      [[nodiscard]] constexpr Vector4 yzxx() const noexcept { return { y, z, x, x }; }
      [[nodiscard]] constexpr Vector4 yzxy() const noexcept { return { y, z, x, y }; }
      [[nodiscard]] constexpr Vector4 yzxz() const noexcept { return { y, z, x, z }; }
      [[nodiscard]] constexpr Vector4 yzxw() const noexcept { return { y, z, x, w }; }
      [[nodiscard]] constexpr Vector4 yzyx() const noexcept { return { y, z, y, x }; }
      [[nodiscard]] constexpr Vector4 yzyy() const noexcept { return { y, z, y, y }; }
      [[nodiscard]] constexpr Vector4 yzyz() const noexcept { return { y, z, y, z }; }
      [[nodiscard]] constexpr Vector4 yzyw() const noexcept { return { y, z, y, w }; }
      [[nodiscard]] constexpr Vector4 yzzx() const noexcept { return { y, z, z, x }; }
      [[nodiscard]] constexpr Vector4 yzzy() const noexcept { return { y, z, z, y }; }
      [[nodiscard]] constexpr Vector4 yzzz() const noexcept { return { y, z, z, z }; }
      [[nodiscard]] constexpr Vector4 yzzw() const noexcept { return { y, z, z, w }; }
      [[nodiscard]] constexpr Vector4 yzwx() const noexcept { return { y, z, w, x }; }
      [[nodiscard]] constexpr Vector4 yzwy() const noexcept { return { y, z, w, y }; }
      [[nodiscard]] constexpr Vector4 yzwz() const noexcept { return { y, z, w, z }; }
      [[nodiscard]] constexpr Vector4 yzww() const noexcept { return { y, z, w, w }; }
      [[nodiscard]] constexpr Vector4 ywxx() const noexcept { return { y, w, x, x }; }
      [[nodiscard]] constexpr Vector4 ywxy() const noexcept { return { y, w, x, y }; }
      [[nodiscard]] constexpr Vector4 ywxz() const noexcept { return { y, w, x, z }; }
      [[nodiscard]] constexpr Vector4 ywxw() const noexcept { return { y, w, x, w }; }
      [[nodiscard]] constexpr Vector4 ywyx() const noexcept { return { y, w, y, x }; }
      [[nodiscard]] constexpr Vector4 ywyy() const noexcept { return { y, w, y, y }; }
      [[nodiscard]] constexpr Vector4 ywyz() const noexcept { return { y, w, y, z }; }
      [[nodiscard]] constexpr Vector4 ywyw() const noexcept { return { y, w, y, w }; }
      [[nodiscard]] constexpr Vector4 ywzx() const noexcept { return { y, w, z, x }; }
      [[nodiscard]] constexpr Vector4 ywzy() const noexcept { return { y, w, z, y }; }
      [[nodiscard]] constexpr Vector4 ywzz() const noexcept { return { y, w, z, z }; }
      [[nodiscard]] constexpr Vector4 ywzw() const noexcept { return { y, w, z, w }; }
      [[nodiscard]] constexpr Vector4 ywwx() const noexcept { return { y, w, w, x }; }
      [[nodiscard]] constexpr Vector4 ywwy() const noexcept { return { y, w, w, y }; }
      [[nodiscard]] constexpr Vector4 ywwz() const noexcept { return { y, w, w, z }; }
      [[nodiscard]] constexpr Vector4 ywww() const noexcept { return { y, w, w, w }; }
      [[nodiscard]] constexpr Vector4 zxxx() const noexcept { return { z, x, x, x }; }
      [[nodiscard]] constexpr Vector4 zxxy() const noexcept { return { z, x, x, y }; }
      [[nodiscard]] constexpr Vector4 zxxz() const noexcept { return { z, x, x, z }; }
      [[nodiscard]] constexpr Vector4 zxxw() const noexcept { return { z, x, x, w }; }
      [[nodiscard]] constexpr Vector4 zxyx() const noexcept { return { z, x, y, x }; }
      [[nodiscard]] constexpr Vector4 zxyy() const noexcept { return { z, x, y, y }; }
      [[nodiscard]] constexpr Vector4 zxyz() const noexcept { return { z, x, y, z }; }
      [[nodiscard]] constexpr Vector4 zxyw() const noexcept { return { z, x, y, w }; }
      [[nodiscard]] constexpr Vector4 zxzx() const noexcept { return { z, x, z, x }; }
      [[nodiscard]] constexpr Vector4 zxzy() const noexcept { return { z, x, z, y }; }
      [[nodiscard]] constexpr Vector4 zxzz() const noexcept { return { z, x, z, z }; }
      [[nodiscard]] constexpr Vector4 zxzw() const noexcept { return { z, x, z, w }; }
      [[nodiscard]] constexpr Vector4 zxwx() const noexcept { return { z, x, w, x }; }
      [[nodiscard]] constexpr Vector4 zxwy() const noexcept { return { z, x, w, y }; }
      [[nodiscard]] constexpr Vector4 zxwz() const noexcept { return { z, x, w, z }; }
      [[nodiscard]] constexpr Vector4 zxww() const noexcept { return { z, x, w, w }; }
      [[nodiscard]] constexpr Vector4 zyxx() const noexcept { return { z, y, x, x }; }
      [[nodiscard]] constexpr Vector4 zyxy() const noexcept { return { z, y, x, y }; }
      [[nodiscard]] constexpr Vector4 zyxz() const noexcept { return { z, y, x, z }; }
      [[nodiscard]] constexpr Vector4 zyxw() const noexcept { return { z, y, x, w }; }
      [[nodiscard]] constexpr Vector4 zyyx() const noexcept { return { z, y, y, x }; }
      [[nodiscard]] constexpr Vector4 zyyy() const noexcept { return { z, y, y, y }; }
      [[nodiscard]] constexpr Vector4 zyyz() const noexcept { return { z, y, y, z }; }
      [[nodiscard]] constexpr Vector4 zyyw() const noexcept { return { z, y, y, w }; }
      [[nodiscard]] constexpr Vector4 zyzx() const noexcept { return { z, y, z, x }; }
      [[nodiscard]] constexpr Vector4 zyzy() const noexcept { return { z, y, z, y }; }
      [[nodiscard]] constexpr Vector4 zyzz() const noexcept { return { z, y, z, z }; }
      [[nodiscard]] constexpr Vector4 zyzw() const noexcept { return { z, y, z, w }; }
      [[nodiscard]] constexpr Vector4 zywx() const noexcept { return { z, y, w, x }; }
      [[nodiscard]] constexpr Vector4 zywy() const noexcept { return { z, y, w, y }; }
      [[nodiscard]] constexpr Vector4 zywz() const noexcept { return { z, y, w, z }; }
      [[nodiscard]] constexpr Vector4 zyww() const noexcept { return { z, y, w, w }; }
      [[nodiscard]] constexpr Vector4 zzxx() const noexcept { return { z, z, x, x }; }
      [[nodiscard]] constexpr Vector4 zzxy() const noexcept { return { z, z, x, y }; }
      [[nodiscard]] constexpr Vector4 zzxz() const noexcept { return { z, z, x, z }; }
      [[nodiscard]] constexpr Vector4 zzxw() const noexcept { return { z, z, x, w }; }
      [[nodiscard]] constexpr Vector4 zzyx() const noexcept { return { z, z, y, x }; }
      [[nodiscard]] constexpr Vector4 zzyy() const noexcept { return { z, z, y, y }; }
      [[nodiscard]] constexpr Vector4 zzyz() const noexcept { return { z, z, y, z }; }
      [[nodiscard]] constexpr Vector4 zzyw() const noexcept { return { z, z, y, w }; }
      [[nodiscard]] constexpr Vector4 zzzx() const noexcept { return { z, z, z, x }; }
      [[nodiscard]] constexpr Vector4 zzzy() const noexcept { return { z, z, z, y }; }
      [[nodiscard]] constexpr Vector4 zzzz() const noexcept { return { z, z, z, z }; }
      [[nodiscard]] constexpr Vector4 zzzw() const noexcept { return { z, z, z, w }; }
      [[nodiscard]] constexpr Vector4 zzwx() const noexcept { return { z, z, w, x }; }
      [[nodiscard]] constexpr Vector4 zzwy() const noexcept { return { z, z, w, y }; }
      [[nodiscard]] constexpr Vector4 zzwz() const noexcept { return { z, z, w, z }; }
      [[nodiscard]] constexpr Vector4 zzww() const noexcept { return { z, z, w, w }; }
      [[nodiscard]] constexpr Vector4 zwxx() const noexcept { return { z, w, x, x }; }
      [[nodiscard]] constexpr Vector4 zwxy() const noexcept { return { z, w, x, y }; }
      [[nodiscard]] constexpr Vector4 zwxz() const noexcept { return { z, w, x, z }; }
      [[nodiscard]] constexpr Vector4 zwxw() const noexcept { return { z, w, x, w }; }
      [[nodiscard]] constexpr Vector4 zwyx() const noexcept { return { z, w, y, x }; }
      [[nodiscard]] constexpr Vector4 zwyy() const noexcept { return { z, w, y, y }; }
      [[nodiscard]] constexpr Vector4 zwyz() const noexcept { return { z, w, y, z }; }
      [[nodiscard]] constexpr Vector4 zwyw() const noexcept { return { z, w, y, w }; }
      [[nodiscard]] constexpr Vector4 zwzx() const noexcept { return { z, w, z, x }; }
      [[nodiscard]] constexpr Vector4 zwzy() const noexcept { return { z, w, z, y }; }
      [[nodiscard]] constexpr Vector4 zwzz() const noexcept { return { z, w, z, z }; }
      [[nodiscard]] constexpr Vector4 zwzw() const noexcept { return { z, w, z, w }; }
      [[nodiscard]] constexpr Vector4 zwwx() const noexcept { return { z, w, w, x }; }
      [[nodiscard]] constexpr Vector4 zwwy() const noexcept { return { z, w, w, y }; }
      [[nodiscard]] constexpr Vector4 zwwz() const noexcept { return { z, w, w, z }; }
      [[nodiscard]] constexpr Vector4 zwww() const noexcept { return { z, w, w, w }; }
      [[nodiscard]] constexpr Vector4 wxxx() const noexcept { return { w, x, x, x }; }
      [[nodiscard]] constexpr Vector4 wxxy() const noexcept { return { w, x, x, y }; }
      [[nodiscard]] constexpr Vector4 wxxz() const noexcept { return { w, x, x, z }; }
      [[nodiscard]] constexpr Vector4 wxxw() const noexcept { return { w, x, x, w }; }
      [[nodiscard]] constexpr Vector4 wxyx() const noexcept { return { w, x, y, x }; }
      [[nodiscard]] constexpr Vector4 wxyy() const noexcept { return { w, x, y, y }; }
      [[nodiscard]] constexpr Vector4 wxyz() const noexcept { return { w, x, y, z }; }
      [[nodiscard]] constexpr Vector4 wxyw() const noexcept { return { w, x, y, w }; }
      [[nodiscard]] constexpr Vector4 wxzx() const noexcept { return { w, x, z, x }; }
      [[nodiscard]] constexpr Vector4 wxzy() const noexcept { return { w, x, z, y }; }
      [[nodiscard]] constexpr Vector4 wxzz() const noexcept { return { w, x, z, z }; }
      [[nodiscard]] constexpr Vector4 wxzw() const noexcept { return { w, x, z, w }; }
      [[nodiscard]] constexpr Vector4 wxwx() const noexcept { return { w, x, w, x }; }
      [[nodiscard]] constexpr Vector4 wxwy() const noexcept { return { w, x, w, y }; }
      [[nodiscard]] constexpr Vector4 wxwz() const noexcept { return { w, x, w, z }; }
      [[nodiscard]] constexpr Vector4 wxww() const noexcept { return { w, x, w, w }; }
      [[nodiscard]] constexpr Vector4 wyxx() const noexcept { return { w, y, x, x }; }
      [[nodiscard]] constexpr Vector4 wyxy() const noexcept { return { w, y, x, y }; }
      [[nodiscard]] constexpr Vector4 wyxz() const noexcept { return { w, y, x, z }; }
      [[nodiscard]] constexpr Vector4 wyxw() const noexcept { return { w, y, x, w }; }
      [[nodiscard]] constexpr Vector4 wyyx() const noexcept { return { w, y, y, x }; }
      [[nodiscard]] constexpr Vector4 wyyy() const noexcept { return { w, y, y, y }; }
      [[nodiscard]] constexpr Vector4 wyyz() const noexcept { return { w, y, y, z }; }
      [[nodiscard]] constexpr Vector4 wyyw() const noexcept { return { w, y, y, w }; }
      [[nodiscard]] constexpr Vector4 wyzx() const noexcept { return { w, y, z, x }; }
      [[nodiscard]] constexpr Vector4 wyzy() const noexcept { return { w, y, z, y }; }
      [[nodiscard]] constexpr Vector4 wyzz() const noexcept { return { w, y, z, z }; }
      [[nodiscard]] constexpr Vector4 wyzw() const noexcept { return { w, y, z, w }; }
      [[nodiscard]] constexpr Vector4 wywx() const noexcept { return { w, y, w, x }; }
      [[nodiscard]] constexpr Vector4 wywy() const noexcept { return { w, y, w, y }; }
      [[nodiscard]] constexpr Vector4 wywz() const noexcept { return { w, y, w, z }; }
      [[nodiscard]] constexpr Vector4 wyww() const noexcept { return { w, y, w, w }; }
      [[nodiscard]] constexpr Vector4 wzxx() const noexcept { return { w, z, x, x }; }
      [[nodiscard]] constexpr Vector4 wzxy() const noexcept { return { w, z, x, y }; }
      [[nodiscard]] constexpr Vector4 wzxz() const noexcept { return { w, z, x, z }; }
      [[nodiscard]] constexpr Vector4 wzxw() const noexcept { return { w, z, x, w }; }
      [[nodiscard]] constexpr Vector4 wzyx() const noexcept { return { w, z, y, x }; }
      [[nodiscard]] constexpr Vector4 wzyy() const noexcept { return { w, z, y, y }; }
      [[nodiscard]] constexpr Vector4 wzyz() const noexcept { return { w, z, y, z }; }
      [[nodiscard]] constexpr Vector4 wzyw() const noexcept { return { w, z, y, w }; }
      [[nodiscard]] constexpr Vector4 wzzx() const noexcept { return { w, z, z, x }; }
      [[nodiscard]] constexpr Vector4 wzzy() const noexcept { return { w, z, z, y }; }
      [[nodiscard]] constexpr Vector4 wzzz() const noexcept { return { w, z, z, z }; }
      [[nodiscard]] constexpr Vector4 wzzw() const noexcept { return { w, z, z, w }; }
      [[nodiscard]] constexpr Vector4 wzwx() const noexcept { return { w, z, w, x }; }
      [[nodiscard]] constexpr Vector4 wzwy() const noexcept { return { w, z, w, y }; }
      [[nodiscard]] constexpr Vector4 wzwz() const noexcept { return { w, z, w, z }; }
      [[nodiscard]] constexpr Vector4 wzww() const noexcept { return { w, z, w, w }; }
      [[nodiscard]] constexpr Vector4 wwxx() const noexcept { return { w, w, x, x }; }
      [[nodiscard]] constexpr Vector4 wwxy() const noexcept { return { w, w, x, y }; }
      [[nodiscard]] constexpr Vector4 wwxz() const noexcept { return { w, w, x, z }; }
      [[nodiscard]] constexpr Vector4 wwxw() const noexcept { return { w, w, x, w }; }
      [[nodiscard]] constexpr Vector4 wwyx() const noexcept { return { w, w, y, x }; }
      [[nodiscard]] constexpr Vector4 wwyy() const noexcept { return { w, w, y, y }; }
      [[nodiscard]] constexpr Vector4 wwyz() const noexcept { return { w, w, y, z }; }
      [[nodiscard]] constexpr Vector4 wwyw() const noexcept { return { w, w, y, w }; }
      [[nodiscard]] constexpr Vector4 wwzx() const noexcept { return { w, w, z, x }; }
      [[nodiscard]] constexpr Vector4 wwzy() const noexcept { return { w, w, z, y }; }
      [[nodiscard]] constexpr Vector4 wwzz() const noexcept { return { w, w, z, z }; }
      [[nodiscard]] constexpr Vector4 wwzw() const noexcept { return { w, w, z, w }; }
      [[nodiscard]] constexpr Vector4 wwwx() const noexcept { return { w, w, w, x }; }
      [[nodiscard]] constexpr Vector4 wwwy() const noexcept { return { w, w, w, y }; }
      [[nodiscard]] constexpr Vector4 wwwz() const noexcept { return { w, w, w, z }; }
      [[nodiscard]] constexpr Vector4 wwww() const noexcept { return { w, w, w, w }; }
#pragma endregion
      [[nodiscard]] constexpr static bool Equal( FVector4 a, FVector4 b, FScalar epsilon ) noexcept
      {
         return (
            Math::Abs( a.x - b.x ) < epsilon &&
            Math::Abs( a.y - b.y ) < epsilon &&
            Math::Abs( a.z - b.z ) < epsilon &&
            Math::Abs( a.w - b.w ) < epsilon );
      }
      [[nodiscard]] constexpr static Scalar Dot( FVector4 a, FVector4 b ) noexcept
      {
         return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
      }
#pragma region [ op Vec ]
      [[nodiscard]] constexpr friend Vector4 operator+( FVector4 a ) noexcept
      {
         return a;
      }
      [[nodiscard]] constexpr friend Vector4 operator-( FVector4 a ) noexcept
      {
         return { -a.x,-a.y,-a.z,-a.w };
      }
#pragma endregion
#pragma region [ Vec op Vec ]
      [[nodiscard]] constexpr friend Vector4 operator+( FVector4 a, FVector4 b ) noexcept
      {
         return
         {
            a.x + b.x,
            a.y + b.y,
            a.z + b.z,
            a.w + b.w,
         };
      }
      [[nodiscard]] constexpr friend Vector4 operator-( FVector4 a, FVector4 b ) noexcept
      {
         return
         {
            a.x - b.x,
            a.y - b.y,
            a.z - b.z,
            a.w - b.w,
         };
      }
      [[nodiscard]] constexpr friend Vector4 operator*( FVector4 a, FVector4 b ) noexcept
      {
         return
         {
            a.x * b.x,
            a.y * b.y,
            a.z * b.z,
            a.w * b.w,
         };
      }
      [[nodiscard]] constexpr friend Vector4 operator/( FVector4 a, FVector4 b ) noexcept
      {
         return
         {
            a.x / b.x,
            a.y / b.y,
            a.z / b.z,
            a.w / b.w,
         };
      }
#pragma endregion
#pragma region [ Vec op= Vec ]
      constexpr friend Vector4& operator+=( Vector4 & a, FVector4 b ) noexcept
      {
         a.x += b.x;
         a.y += b.y;
         a.z += b.z;
         a.w += b.w;
         return a;
      }
      constexpr friend Vector4& operator-=( Vector4 & a, FVector4 b ) noexcept
      {
         a.x -= b.x;
         a.y -= b.y;
         a.z -= b.z;
         a.w -= b.w;
         return a;
      }
      constexpr friend Vector4& operator*=( Vector4 & a, FVector4 b ) noexcept
      {
         a.x *= b.x;
         a.y *= b.y;
         a.z *= b.z;
         a.w *= b.w;
         return a;
      }
      constexpr friend Vector4& operator/=( Vector4 & a, FVector4 b ) noexcept
      {
         a.x /= b.x;
         a.y /= b.y;
         a.z /= b.z;
         a.w /= b.w;
         return a;
      }
#pragma endregion
#pragma region [ Comparison ]
      [[nodiscard]] constexpr friend bool operator==( FVector4 a, FVector4 b ) noexcept
      {
         return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
      }
      [[nodiscard]] constexpr friend bool operator!=( FVector4 a, FVector4 b ) noexcept
      {
         return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
      }
#pragma endregion
      template<typename T>
      constexpr friend std::basic_ostream<T>& operator<<( std::basic_ostream<T>& s, FVector4 v ) noexcept
      {
         return s << '[' << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ']';
      }
   };
}