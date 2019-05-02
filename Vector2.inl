namespace TLib
{
   template<class TScalar>
   struct Vector2
   {
      using Scalar = TScalar;
      using FScalar = const Scalar&;
      using Vector3 = Vector3<Scalar>;
      using Vector4 = Vector4<Scalar>;
      using FVector2 = const Vector2&;
      using FVector3 = const Vector3&;
      using FVector4 = const Vector4&;
      union
      {
         struct
         {
            Scalar x, y;
         };
         Scalar scl[2];
      };
#pragma region [ Constructors ]
      constexpr Vector2() noexcept :
         x( (Scalar)0 ),
         y( (Scalar)0 )
      {     
      }
      constexpr Vector2( FScalar v ) noexcept :
         x( v ),
         y( v )
      {
      }
      constexpr Vector2( FScalar x, FScalar y ) noexcept :
         x( x ),
         y( y )
      {
      }
      constexpr Vector2( FVector2 ) = default;
      constexpr Vector2( Vector2&& ) = default;
      template<class Other>
      constexpr explicit Vector2( const Vector2<Other>& other ) noexcept :
         x( (Scalar) other.x ),
         y( (Scalar) other.y )
      {
      }
#pragma endregion
#pragma region [ operator= ]
      constexpr Vector2& operator=( FVector2 ) = default;
      constexpr Vector2& operator=( Vector2&& ) = default;
#pragma endregion
      [[nodiscard]] constexpr Scalar SqrMagnitude() const noexcept
      {
         return x * x + y * y;
      }
      template<class ConvertTo = Scalar>
      [[nodiscard]] constexpr ConvertTo Magnitude() const noexcept
      {
         return Math::Sqrt( (ConvertTo)SqrMagnitude() );
      }
      template<class ConvertTo = Scalar>
      [[nodiscard]] constexpr Vector2<ConvertTo> Normalized() const noexcept
      {
         return (Vector2<ConvertTo>)*this / Magnitude<ConvertTo>();
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
      [[nodiscard]] constexpr Vector2 yx() const noexcept { return { y, x }; }
      [[nodiscard]] constexpr Vector2 yy() const noexcept { return { y, y }; }
      [[nodiscard]] constexpr Vector3 xxx() const noexcept { return { x, x, x }; }
      [[nodiscard]] constexpr Vector3 xxy() const noexcept { return { x, x, y }; }
      [[nodiscard]] constexpr Vector3 xyx() const noexcept { return { x, y, x }; }
      [[nodiscard]] constexpr Vector3 xyy() const noexcept { return { x, y, y }; }
      [[nodiscard]] constexpr Vector3 yxx() const noexcept { return { y, x, x }; }
      [[nodiscard]] constexpr Vector3 yxy() const noexcept { return { y, x, y }; }
      [[nodiscard]] constexpr Vector3 yyx() const noexcept { return { y, y, x }; }
      [[nodiscard]] constexpr Vector3 yyy() const noexcept { return { y, y, y }; }
      [[nodiscard]] constexpr Vector4 xxxx() const noexcept { return { x, x, x, x }; }
      [[nodiscard]] constexpr Vector4 xxxy() const noexcept { return { x, x, x, y }; }
      [[nodiscard]] constexpr Vector4 xxyx() const noexcept { return { x, x, y, x }; }
      [[nodiscard]] constexpr Vector4 xxyy() const noexcept { return { x, x, y, y }; }
      [[nodiscard]] constexpr Vector4 xyxx() const noexcept { return { x, y, x, x }; }
      [[nodiscard]] constexpr Vector4 xyxy() const noexcept { return { x, y, x, y }; }
      [[nodiscard]] constexpr Vector4 xyyx() const noexcept { return { x, y, y, x }; }
      [[nodiscard]] constexpr Vector4 xyyy() const noexcept { return { x, y, y, y }; }
      [[nodiscard]] constexpr Vector4 yxxx() const noexcept { return { y, x, x, x }; }
      [[nodiscard]] constexpr Vector4 yxxy() const noexcept { return { y, x, x, y }; }
      [[nodiscard]] constexpr Vector4 yxyx() const noexcept { return { y, x, y, x }; }
      [[nodiscard]] constexpr Vector4 yxyy() const noexcept { return { y, x, y, y }; }
      [[nodiscard]] constexpr Vector4 yyxx() const noexcept { return { y, y, x, x }; }
      [[nodiscard]] constexpr Vector4 yyxy() const noexcept { return { y, y, x, y }; }
      [[nodiscard]] constexpr Vector4 yyyx() const noexcept { return { y, y, y, x }; }
      [[nodiscard]] constexpr Vector4 yyyy() const noexcept { return { y, y, y, y }; }
#pragma endregion
      [[nodiscard]] constexpr static bool Equal( FVector2 a, FVector2 b, FScalar epsilon ) noexcept
      {
         return (
            Math::Abs( a.x - b.x ) < epsilon &&
            Math::Abs( a.y - b.y ) < epsilon );
      }
      [[nodiscard]] constexpr static Vector2 Cross( FVector2 a ) noexcept
      {
         return
         {
            a.y,
            -a.x
         };
      }
      [[nodiscard]] constexpr static Scalar Dot( FVector2 a, FVector2 b ) noexcept
      {
         return a.x * b.x + a.y * b.y;
      }
#pragma region [ op Vec ]
      [[nodiscard]] constexpr friend Vector2 operator+( FVector2 a ) noexcept
      {
         return a;
      }
      [[nodiscard]] constexpr friend Vector2 operator-( FVector2 a ) noexcept
      {
         return { -a.x,-a.y };
      }
#pragma endregion
#pragma region [ Vec op Vec ]
      [[nodiscard]] constexpr friend Vector2 operator+( FVector2 a, FVector2 b ) noexcept
      {
         return
         {
            a.x + b.x,
            a.y + b.y
         };
      }
      [[nodiscard]] constexpr friend Vector2 operator-( FVector2 a, FVector2 b ) noexcept
      {
         return
         {
            a.x - b.x,
            a.y - b.y
         };
      }
      [[nodiscard]] constexpr friend Vector2 operator*( FVector2 a, FVector2 b ) noexcept
      {
         return
         {
            a.x * b.x,
            a.y * b.y
         };
      }
      [[nodiscard]] constexpr friend Vector2 operator/( FVector2 a, FVector2 b ) noexcept
      {
         return
         {
            a.x / b.x,
            a.y / b.y
         };
      }
#pragma endregion
#pragma region [ Vec op= Vec ]
      constexpr friend Vector2& operator+=( Vector2& a, FVector2 b ) noexcept
      {
         a.x += b.x;
         a.y += b.y;
         return a;
      }
      constexpr friend Vector2& operator-=( Vector2& a, FVector2 b ) noexcept
      {
         a.x -= b.x;
         a.y -= b.y;
         return a;
      }
      constexpr friend Vector2& operator*=( Vector2& a, FVector2 b ) noexcept
      {
         a.x *= b.x;
         a.y *= b.y;
         return a;
      }
      constexpr friend Vector2& operator/=( Vector2& a, FVector2 b ) noexcept
      {
         a.x /= b.x;
         a.y /= b.y;
         return a;
      }
#pragma endregion
#pragma region [ Comparison ]
      [[nodiscard]] constexpr friend bool operator==( FVector2 a, FVector2 b ) noexcept
      {
         return a.x == b.x && a.y == b.y;
      }
      [[nodiscard]] constexpr friend bool operator!=( FVector2 a, FVector2 b ) noexcept
      {
         return a.x != b.x || a.y != b.y;
      }
#pragma endregion

      template<typename T>
      constexpr friend std::basic_ostream<T>& operator<<( std::basic_ostream<T> & s, FVector2 v ) noexcept
      {
         return s << '[' << v.x << ", " << v.y << ']';
      }
   };
}