namespace TLib
{
   template<class TScalar>
   struct Vector3
   {
      using Scalar = TScalar;
      using FScalar = const Scalar &;
      using Vector2 = Vector2<Scalar>;
      using Vector4 = Vector4<Scalar>;
      using FVector2 = const Vector2 &;
      using FVector3 = const Vector3 &;
      using FVector4 = const Vector4 &;
      Scalar x{};
      Scalar y{};
      Scalar z{};
      TL_CONSTEXPR Vector3() = default;
      TL_CONSTEXPR Vector3(FScalar v) TL_NOEXCEPT :
         x(v),
         y(v),
         z(v)
      {
      }
      TL_CONSTEXPR Vector3(FScalar x, FScalar y) TL_NOEXCEPT :
         x(x),
         y(y)
      {
      }
      TL_CONSTEXPR Vector3(FScalar x, FScalar y, FScalar z) TL_NOEXCEPT :
         x(x),
         y(y),
         z(z)
      {
      }
      TL_CONSTEXPR Vector3(FVector2 v, FScalar z = {}) TL_NOEXCEPT :
         x(v.x),
         y(v.y),
         z(z)
      {
      }
      TL_CONSTEXPR Vector3(FScalar x, FVector2 v) TL_NOEXCEPT :
         x(x),
         y(v.x),
         z(v.y)
      {
      }
      TL_CONSTEXPR Vector3(const Vector3&) = default;
      TL_CONSTEXPR Vector3(Vector3&&) = default;
      template<class Other>
      TL_CONSTEXPR explicit Vector3(const Vector3<Other>& other) TL_NOEXCEPT :
         x((Scalar)other.x),
         y((Scalar)other.y),
         z((Scalar)other.z)
      {
      }
      TL_CONSTEXPR Vector3& operator=(const Vector3&) = default;
      TL_CONSTEXPR Vector3& operator=(Vector3&&) = default;
      TL_NODISCARD TL_CONSTEXPR Scalar SqrMagnitude() const TL_NOEXCEPT
      {
         return x * x + y * y + z * z;
      }
      template<class ConvertTo = Scalar>
      TL_NODISCARD TL_CONSTEXPR ConvertTo Magnitude() const TL_NOEXCEPT
      {
         return Math::Sqrt((ConvertTo)SqrMagnitude());
      }
      template<class ConvertTo = Scalar>
      TL_NODISCARD TL_CONSTEXPR Vector3<ConvertTo> Normalized() const TL_NOEXCEPT
      {
         return (Vector3<ConvertTo>)* this / Magnitude<ConvertTo>();
      }
      TL_NODISCARD TL_CONSTEXPR Vector3 Clamped(FScalar val) const TL_NOEXCEPT
      {
         auto ret = *this;
         if (ret.Magnitude() > val)
            return ret.Normalized() * val;
         return ret;
      }
      TL_NODISCARD TL_CONSTEXPR Vector3 ProjectedOn(FVector3 v) const TL_NOEXCEPT
      {
         return v * Dot(*this, v);
      }
      TL_NODISCARD TL_CONSTEXPR Scalar* Data() TL_NOEXCEPT
      {
         return scl;
      }
      TL_NODISCARD TL_CONSTEXPR const Scalar* Data() const TL_NOEXCEPT
      {
         return scl;
      }
      TL_NODISCARD TL_CONSTEXPR Scalar& operator[](unsigned i) TL_NOEXCEPT
      {
         return Data()[i];
      }
      TL_NODISCARD TL_CONSTEXPR FScalar operator[](unsigned i) const TL_NOEXCEPT
      {
         return Data()[i];
      }
      TL_NODISCARD TL_CONSTEXPR Vector2 xx() const TL_NOEXCEPT { return {x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 xy() const TL_NOEXCEPT { return {x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 xz() const TL_NOEXCEPT { return {x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 yx() const TL_NOEXCEPT { return {y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 yy() const TL_NOEXCEPT { return {y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 yz() const TL_NOEXCEPT { return {y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 zx() const TL_NOEXCEPT { return {z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 zy() const TL_NOEXCEPT { return {z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector2 zz() const TL_NOEXCEPT { return {z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xxx() const TL_NOEXCEPT { return {x, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xxy() const TL_NOEXCEPT { return {x, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xxz() const TL_NOEXCEPT { return {x, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xyx() const TL_NOEXCEPT { return {x, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xyy() const TL_NOEXCEPT { return {x, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xyz() const TL_NOEXCEPT { return {x, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xzx() const TL_NOEXCEPT { return {x, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xzy() const TL_NOEXCEPT { return {x, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 xzz() const TL_NOEXCEPT { return {x, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yxx() const TL_NOEXCEPT { return {y, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yxy() const TL_NOEXCEPT { return {y, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yxz() const TL_NOEXCEPT { return {y, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yyx() const TL_NOEXCEPT { return {y, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yyy() const TL_NOEXCEPT { return {y, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yyz() const TL_NOEXCEPT { return {y, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yzx() const TL_NOEXCEPT { return {y, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yzy() const TL_NOEXCEPT { return {y, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 yzz() const TL_NOEXCEPT { return {y, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 zxx() const TL_NOEXCEPT { return {z, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 zxy() const TL_NOEXCEPT { return {z, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 zxz() const TL_NOEXCEPT { return {z, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 zyx() const TL_NOEXCEPT { return {z, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 zyy() const TL_NOEXCEPT { return {z, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 zyz() const TL_NOEXCEPT { return {z, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 zzx() const TL_NOEXCEPT { return {z, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 zzy() const TL_NOEXCEPT { return {z, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 zzz() const TL_NOEXCEPT { return {z, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxxx() const TL_NOEXCEPT { return {x, x, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxxy() const TL_NOEXCEPT { return {x, x, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxxz() const TL_NOEXCEPT { return {x, x, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxyx() const TL_NOEXCEPT { return {x, x, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxyy() const TL_NOEXCEPT { return {x, x, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxyz() const TL_NOEXCEPT { return {x, x, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxzx() const TL_NOEXCEPT { return {x, x, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxzy() const TL_NOEXCEPT { return {x, x, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxzz() const TL_NOEXCEPT { return {x, x, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyxx() const TL_NOEXCEPT { return {x, y, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyxy() const TL_NOEXCEPT { return {x, y, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyxz() const TL_NOEXCEPT { return {x, y, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyyx() const TL_NOEXCEPT { return {x, y, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyyy() const TL_NOEXCEPT { return {x, y, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyyz() const TL_NOEXCEPT { return {x, y, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyzx() const TL_NOEXCEPT { return {x, y, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyzy() const TL_NOEXCEPT { return {x, y, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyzz() const TL_NOEXCEPT { return {x, y, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzxx() const TL_NOEXCEPT { return {x, z, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzxy() const TL_NOEXCEPT { return {x, z, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzxz() const TL_NOEXCEPT { return {x, z, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzyx() const TL_NOEXCEPT { return {x, z, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzyy() const TL_NOEXCEPT { return {x, z, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzyz() const TL_NOEXCEPT { return {x, z, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzzx() const TL_NOEXCEPT { return {x, z, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzzy() const TL_NOEXCEPT { return {x, z, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzzz() const TL_NOEXCEPT { return {x, z, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxxx() const TL_NOEXCEPT { return {y, x, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxxy() const TL_NOEXCEPT { return {y, x, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxxz() const TL_NOEXCEPT { return {y, x, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxyx() const TL_NOEXCEPT { return {y, x, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxyy() const TL_NOEXCEPT { return {y, x, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxyz() const TL_NOEXCEPT { return {y, x, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxzx() const TL_NOEXCEPT { return {y, x, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxzy() const TL_NOEXCEPT { return {y, x, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxzz() const TL_NOEXCEPT { return {y, x, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyxx() const TL_NOEXCEPT { return {y, y, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyxy() const TL_NOEXCEPT { return {y, y, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyxz() const TL_NOEXCEPT { return {y, y, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyyx() const TL_NOEXCEPT { return {y, y, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyyy() const TL_NOEXCEPT { return {y, y, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyyz() const TL_NOEXCEPT { return {y, y, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyzx() const TL_NOEXCEPT { return {y, y, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyzy() const TL_NOEXCEPT { return {y, y, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyzz() const TL_NOEXCEPT { return {y, y, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzxx() const TL_NOEXCEPT { return {y, z, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzxy() const TL_NOEXCEPT { return {y, z, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzxz() const TL_NOEXCEPT { return {y, z, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzyx() const TL_NOEXCEPT { return {y, z, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzyy() const TL_NOEXCEPT { return {y, z, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzyz() const TL_NOEXCEPT { return {y, z, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzzx() const TL_NOEXCEPT { return {y, z, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzzy() const TL_NOEXCEPT { return {y, z, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzzz() const TL_NOEXCEPT { return {y, z, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxxx() const TL_NOEXCEPT { return {z, x, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxxy() const TL_NOEXCEPT { return {z, x, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxxz() const TL_NOEXCEPT { return {z, x, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxyx() const TL_NOEXCEPT { return {z, x, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxyy() const TL_NOEXCEPT { return {z, x, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxyz() const TL_NOEXCEPT { return {z, x, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxzx() const TL_NOEXCEPT { return {z, x, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxzy() const TL_NOEXCEPT { return {z, x, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxzz() const TL_NOEXCEPT { return {z, x, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyxx() const TL_NOEXCEPT { return {z, y, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyxy() const TL_NOEXCEPT { return {z, y, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyxz() const TL_NOEXCEPT { return {z, y, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyyx() const TL_NOEXCEPT { return {z, y, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyyy() const TL_NOEXCEPT { return {z, y, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyyz() const TL_NOEXCEPT { return {z, y, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyzx() const TL_NOEXCEPT { return {z, y, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyzy() const TL_NOEXCEPT { return {z, y, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyzz() const TL_NOEXCEPT { return {z, y, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzxx() const TL_NOEXCEPT { return {z, z, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzxy() const TL_NOEXCEPT { return {z, z, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzxz() const TL_NOEXCEPT { return {z, z, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzyx() const TL_NOEXCEPT { return {z, z, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzyy() const TL_NOEXCEPT { return {z, z, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzyz() const TL_NOEXCEPT { return {z, z, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzzx() const TL_NOEXCEPT { return {z, z, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzzy() const TL_NOEXCEPT { return {z, z, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzzz() const TL_NOEXCEPT { return {z, z, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector3 operator+() TL_NOEXCEPT
      {
         return {+x,+y,+z};
      }
      TL_NODISCARD TL_CONSTEXPR Vector3 operator-() TL_NOEXCEPT
      {
         return {-x,-y,-z};
      }
      TL_CONSTEXPR Vector3& operator+=(FVector3 v) TL_NOEXCEPT
      {
         x += v.x;
         y += v.y;
         z += v.z;
         return *this;
      }
      TL_CONSTEXPR Vector3& operator-=(FVector3 v) TL_NOEXCEPT
      {
         x -= v.x;
         y -= v.y;
         z -= v.z;
         return *this;
      }
      TL_CONSTEXPR Vector3& operator*=(FVector3 v) TL_NOEXCEPT
      {
         x *= v.x;
         y *= v.y;
         z *= v.z;
         return *this;
      }
      TL_CONSTEXPR Vector3& operator/=(FVector3 v) TL_NOEXCEPT
      {
         x /= v.x;
         y /= v.y;
         z /= v.z;
         return *this;
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector3 operator+(FVector3 a, FVector3 b) TL_NOEXCEPT
      {
         return
         {
            a.x + b.x,
            a.y + b.y,
            a.z + b.z
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector3 operator-(FVector3 a, FVector3 b) TL_NOEXCEPT
      {
         return
         {
            a.x - b.x,
            a.y - b.y,
            a.z - b.z
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector3 operator*(FVector3 a, FVector3 b) TL_NOEXCEPT
      {
         return
         {
            a.x * b.x,
            a.y * b.y,
            a.z * b.z
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector3 operator/(FVector3 a, FVector3 b) TL_NOEXCEPT
      {
         return
         {
            a.x / b.x,
            a.y / b.y,
            a.z / b.z
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend bool operator==(FVector3 a, FVector3 b) TL_NOEXCEPT
      {
         return a.x == b.x && a.y == b.y && a.z == b.z;
      }
      TL_NODISCARD TL_CONSTEXPR friend bool operator!=(FVector3 a, FVector3 b) TL_NOEXCEPT
      {
         return a.x != b.x || a.y != b.y || a.z != b.z;
      }
      TL_NODISCARD TL_CONSTEXPR static bool Equal(FVector3 a, FVector3 b, FScalar epsilon) TL_NOEXCEPT
      {
         return (
            Math::Abs(a.x - b.x) < epsilon &&
            Math::Abs(a.y - b.y) < epsilon &&
            Math::Abs(a.z - b.z) < epsilon);
      }
      TL_NODISCARD TL_CONSTEXPR static Vector3 Cross(FVector3 a, FVector3 b) TL_NOEXCEPT
      {
         return
         {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
         };
      }
      TL_NODISCARD TL_CONSTEXPR static Scalar Dot(FVector3 a, FVector3 b) TL_NOEXCEPT
      {
         return a.x* b.x + a.y * b.y + a.z * b.z;
      }
      TL_NODISCARD TL_CONSTEXPR static Vector3 Right() TL_NOEXCEPT { return {1, 0, 0}; }
      TL_NODISCARD TL_CONSTEXPR static Vector3 Up() TL_NOEXCEPT { return {0, 1, 0}; }
      TL_NODISCARD TL_CONSTEXPR static Vector3 Forward() TL_NOEXCEPT { return {0, 0, 1}; }
   };
}