namespace TLib
{
   template<class TScalar>
   struct Vector2
   {
      using Scalar = TScalar;
      using FScalar = const Scalar &;
      using Vector3 = Vector3<Scalar>;
      using Vector4 = Vector4<Scalar>;
      using FVector2 = const Vector2 &;
      using FVector3 = const Vector3 &;
      using FVector4 = const Vector4 &;
      Scalar x{};
      Scalar y{};
      TL_CONSTEXPR Vector2() = default;
      TL_CONSTEXPR Vector2(FScalar v) TL_NOEXCEPT :
         x(v),
         y(v)
      {
      }
      TL_CONSTEXPR Vector2(FScalar x, FScalar y) TL_NOEXCEPT :
         x(x),
         y(y)
      {
      }
      TL_CONSTEXPR Vector2(const Vector2&) = default;
      TL_CONSTEXPR Vector2(Vector2&&) = default;
      template<class Other>
      TL_CONSTEXPR explicit Vector2(const Vector2<Other>& other) TL_NOEXCEPT :
         x((Scalar)other.x),
         y((Scalar)other.y)
      {
      }
      TL_CONSTEXPR Vector2& operator=(const Vector2&) = default;
      TL_CONSTEXPR Vector2& operator=(Vector2&&) = default;
      TL_NODISCARD TL_CONSTEXPR Scalar SqrMagnitude() const TL_NOEXCEPT
      {
         return x * x + y * y;
      }
      template<class ConvertTo = Scalar>
      TL_NODISCARD TL_CONSTEXPR ConvertTo Magnitude() const TL_NOEXCEPT
      {
         return Math::Sqrt((ConvertTo)SqrMagnitude());
      }
      template<class ConvertTo = Scalar>
      TL_NODISCARD TL_CONSTEXPR Vector2<ConvertTo> Normalized() const TL_NOEXCEPT
      {
         return (Vector2<ConvertTo>)* this / Magnitude<ConvertTo>();
      }
      TL_NODISCARD TL_CONSTEXPR Vector2 Clamped(FScalar val) const TL_NOEXCEPT
      {
         auto ret = *this;
         if (ret.Magnitude() > val)
            return ret.Normalized() * val;
         return ret;
      }
      TL_NODISCARD TL_CONSTEXPR Scalar* Data() TL_NOEXCEPT
      {
         return scl;
      }
      TL_NODISCARD TL_CONSTEXPR const Scalar* Data() const TL_NOEXCEPT
      {
         return scl;
      }
      TL_NODISCARD TL_CONSTEXPR Vector2 xx() const TL_NOEXCEPT { return {x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 xy() const TL_NOEXCEPT { return {x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 yx() const TL_NOEXCEPT { return {y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 yy() const TL_NOEXCEPT { return {y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xxx() const TL_NOEXCEPT { return {x, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xxy() const TL_NOEXCEPT { return {x, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xyx() const TL_NOEXCEPT { return {x, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xyy() const TL_NOEXCEPT { return {x, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yxx() const TL_NOEXCEPT { return {y, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yxy() const TL_NOEXCEPT { return {y, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yyx() const TL_NOEXCEPT { return {y, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yyy() const TL_NOEXCEPT { return {y, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxxx() const TL_NOEXCEPT { return {x, x, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxxy() const TL_NOEXCEPT { return {x, x, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxyx() const TL_NOEXCEPT { return {x, x, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxyy() const TL_NOEXCEPT { return {x, x, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyxx() const TL_NOEXCEPT { return {x, y, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyxy() const TL_NOEXCEPT { return {x, y, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyyx() const TL_NOEXCEPT { return {x, y, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyyy() const TL_NOEXCEPT { return {x, y, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxxx() const TL_NOEXCEPT { return {y, x, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxxy() const TL_NOEXCEPT { return {y, x, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxyx() const TL_NOEXCEPT { return {y, x, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxyy() const TL_NOEXCEPT { return {y, x, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyxx() const TL_NOEXCEPT { return {y, y, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyxy() const TL_NOEXCEPT { return {y, y, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyyx() const TL_NOEXCEPT { return {y, y, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyyy() const TL_NOEXCEPT { return {y, y, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 operator+() TL_NOEXCEPT
      {
         return {+x,+y};
      }
      TL_NODISCARD TL_CONSTEXPR Vector2 operator-() TL_NOEXCEPT
      {
         return {-x,-y};
      }
      TL_CONSTEXPR Vector2& operator+=(FVector2 v) TL_NOEXCEPT
      {
         x += v.x;
         y += v.y;
         return *this;
      }
      TL_CONSTEXPR Vector2& operator-=(FVector2 v) TL_NOEXCEPT
      {
         x -= v.x;
         y -= v.y;
         return *this;
      }
      TL_CONSTEXPR Vector2& operator*=(FVector2 v) TL_NOEXCEPT
      {
         x *= v.x;
         y *= v.y;
         return *this;
      }
      TL_CONSTEXPR Vector2& operator/=(FVector2 v) TL_NOEXCEPT
      {
         x /= v.x;
         y /= v.y;
         return *this;
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector2 operator+(FVector2 a, FVector2 b) TL_NOEXCEPT
      {
         return
         {
            a.x + b.x,
            a.y + b.y
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector2 operator-(FVector2 a, FVector2 b) TL_NOEXCEPT
      {
         return
         {
            a.x - b.x,
            a.y - b.y
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector2 operator*(FVector2 a, FVector2 b) TL_NOEXCEPT
      {
         return
         {
            a.x * b.x,
            a.y * b.y
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector2 operator/(FVector2 a, FVector2 b) TL_NOEXCEPT
      {
         return
         {
            a.x / b.x,
            a.y / b.y
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend bool operator==(FVector2 a, FVector2 b) TL_NOEXCEPT
      {
         return a.x == b.x && a.y == b.y;
      }
      TL_NODISCARD TL_CONSTEXPR friend bool operator!=(FVector2 a, FVector2 b) TL_NOEXCEPT
      {
         return a.x != b.x || a.y != b.y;
      }
      TL_NODISCARD TL_CONSTEXPR static bool Equal(FVector2 a, FVector2 b, FScalar epsilon) TL_NOEXCEPT
      {
         return (
            Math::Abs(a.x - b.x) < epsilon &&
            Math::Abs(a.y - b.y) < epsilon);
      }
      TL_NODISCARD TL_CONSTEXPR static Vector2 Cross(FVector2 a) TL_NOEXCEPT
      {
         return
         {
            a.y,
            -a.x
         };
      }
      TL_NODISCARD TL_CONSTEXPR static Scalar Dot(FVector2 a, FVector2 b) TL_NOEXCEPT
      {
         return a.x* b.x + a.y * b.y;
      }
      TL_NODISCARD TL_CONSTEXPR Scalar Angle() const noexcept
      {
         auto dx = Dot(*this, Right());
         if (y > 0)
            return acos(dx);
         else
            return Math::Tau - acos(dx);
      }
      TL_CONSTEXPR static Vector2 Right() TL_NOEXCEPT { return {1, 0}; }
      TL_CONSTEXPR static Vector2 Up() TL_NOEXCEPT { return {0, 1}; }
      template<typename T>
      friend std::basic_ostream<T>& operator<<(std::basic_ostream<T> & s, FVector2 v) TL_NOEXCEPT
      {
         return s << '[' << v.x << ", " << v.y << ']';
      }
   };
}