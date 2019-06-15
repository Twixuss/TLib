namespace TLib
{
   template<class TScalar>
   struct Vector4
   {
      using Scalar = TScalar;
      using Vector2 = Vector2<Scalar>;
      using Vector3 = Vector3<Scalar>;
      Scalar x{};
      Scalar y{};
      Scalar z{};
      Scalar w{};
      TL_CONSTEXPR Vector4() = default;
      TL_CONSTEXPR Vector4(Scalar v) TL_NOEXCEPT : x(v), y(v), z(v), w(v) {}
      TL_CONSTEXPR Vector4(Scalar x, Scalar y, Scalar z = {}, Scalar w = {}) TL_NOEXCEPT : x(x), y(y), z(z), w(w) {}
      TL_CONSTEXPR Vector4(Vector2 a, Vector2 b = {}) TL_NOEXCEPT : x(a.x), y(a.y), z(b.x), w(b.y) {}
      TL_CONSTEXPR Vector4(Vector2 v, Scalar z, Scalar w = {}) TL_NOEXCEPT : x(v.x), y(v.y), z(z), w(w) {}
      TL_CONSTEXPR Vector4(Scalar x, Vector2 v, Scalar w = {}) TL_NOEXCEPT : x(x), y(v.x), z(v.y), w(w) {}
      TL_CONSTEXPR Vector4(Scalar x, Scalar y, Vector2 v) TL_NOEXCEPT : x(x), y(y), z(v.x), w(v.y) {}
      TL_CONSTEXPR Vector4(Vector3 v, Scalar w = {}) TL_NOEXCEPT : x(v.x), y(v.y), z(v.z), w(w) {}
      TL_CONSTEXPR Vector4(Scalar x, Vector3 v) TL_NOEXCEPT : x(x), y(v.x), z(v.y), w(v.z) {}
      TL_CONSTEXPR Vector4(const Vector4&) = default;
      TL_CONSTEXPR Vector4(Vector4&&) = default;
      template<class Other>
      TL_CONSTEXPR explicit Vector4(const Vector4<Other>& other) TL_NOEXCEPT :
      x((Scalar)other.x),
         y((Scalar)other.y),
         z((Scalar)other.z),
         w((Scalar)other.w)
      {
      }
      TL_CONSTEXPR Vector4& operator=(const Vector4&) = default;
      TL_CONSTEXPR Vector4& operator=(Vector4&&) = default;
      TL_NODISCARD TL_CONSTEXPR Scalar SqrMagnitude() const TL_NOEXCEPT
      {
         return x * x + y * y + z * z + w * w;
      }
      template<class ConvertTo = Scalar>
      TL_NODISCARD TL_CONSTEXPR ConvertTo Magnitude() const TL_NOEXCEPT
      {
         return Math::Sqrt((ConvertTo)SqrMagnitude());
      }
      template<class ConvertTo = Scalar>
      TL_NODISCARD TL_CONSTEXPR Vector4<ConvertTo> Normalized() const
      {
         auto magnitude = Magnitude<ConvertTo>();
         if (magnitude == 0)
            TL_THROW(DivideByZeroException);
         return (Vector4<ConvertTo>) * this / magnitude;
      }
      TL_NODISCARD TL_CONSTEXPR Scalar* Data() TL_NOEXCEPT
      {
         return &x;
      }
      TL_NODISCARD TL_CONSTEXPR const Scalar* Data() const TL_NOEXCEPT
      {
         return &x;
      }
      TL_NODISCARD TL_CONSTEXPR Scalar& operator[](unsigned i) TL_NOEXCEPT
      {
         return Data()[i];
      }
      TL_NODISCARD TL_CONSTEXPR Scalar operator[](unsigned i) const TL_NOEXCEPT
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
      TL_NODISCARD TL_CONSTEXPR Vector4 xxxw() const TL_NOEXCEPT { return {x, x, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxyx() const TL_NOEXCEPT { return {x, x, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxyy() const TL_NOEXCEPT { return {x, x, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxyz() const TL_NOEXCEPT { return {x, x, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxyw() const TL_NOEXCEPT { return {x, x, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxzx() const TL_NOEXCEPT { return {x, x, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxzy() const TL_NOEXCEPT { return {x, x, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxzz() const TL_NOEXCEPT { return {x, x, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxzw() const TL_NOEXCEPT { return {x, x, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxwx() const TL_NOEXCEPT { return {x, x, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxwy() const TL_NOEXCEPT { return {x, x, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxwz() const TL_NOEXCEPT { return {x, x, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xxww() const TL_NOEXCEPT { return {x, x, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyxx() const TL_NOEXCEPT { return {x, y, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyxy() const TL_NOEXCEPT { return {x, y, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyxz() const TL_NOEXCEPT { return {x, y, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyxw() const TL_NOEXCEPT { return {x, y, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyyx() const TL_NOEXCEPT { return {x, y, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyyy() const TL_NOEXCEPT { return {x, y, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyyz() const TL_NOEXCEPT { return {x, y, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyyw() const TL_NOEXCEPT { return {x, y, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyzx() const TL_NOEXCEPT { return {x, y, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyzy() const TL_NOEXCEPT { return {x, y, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyzz() const TL_NOEXCEPT { return {x, y, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyzw() const TL_NOEXCEPT { return {x, y, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xywx() const TL_NOEXCEPT { return {x, y, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xywy() const TL_NOEXCEPT { return {x, y, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xywz() const TL_NOEXCEPT { return {x, y, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xyww() const TL_NOEXCEPT { return {x, y, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzxx() const TL_NOEXCEPT { return {x, z, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzxy() const TL_NOEXCEPT { return {x, z, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzxz() const TL_NOEXCEPT { return {x, z, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzxw() const TL_NOEXCEPT { return {x, z, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzyx() const TL_NOEXCEPT { return {x, z, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzyy() const TL_NOEXCEPT { return {x, z, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzyz() const TL_NOEXCEPT { return {x, z, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzyw() const TL_NOEXCEPT { return {x, z, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzzx() const TL_NOEXCEPT { return {x, z, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzzy() const TL_NOEXCEPT { return {x, z, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzzz() const TL_NOEXCEPT { return {x, z, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzzw() const TL_NOEXCEPT { return {x, z, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzwx() const TL_NOEXCEPT { return {x, z, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzwy() const TL_NOEXCEPT { return {x, z, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzwz() const TL_NOEXCEPT { return {x, z, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xzww() const TL_NOEXCEPT { return {x, z, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwxx() const TL_NOEXCEPT { return {x, w, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwxy() const TL_NOEXCEPT { return {x, w, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwxz() const TL_NOEXCEPT { return {x, w, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwxw() const TL_NOEXCEPT { return {x, w, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwyx() const TL_NOEXCEPT { return {x, w, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwyy() const TL_NOEXCEPT { return {x, w, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwyz() const TL_NOEXCEPT { return {x, w, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwyw() const TL_NOEXCEPT { return {x, w, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwzx() const TL_NOEXCEPT { return {x, w, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwzy() const TL_NOEXCEPT { return {x, w, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwzz() const TL_NOEXCEPT { return {x, w, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwzw() const TL_NOEXCEPT { return {x, w, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwwx() const TL_NOEXCEPT { return {x, w, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwwy() const TL_NOEXCEPT { return {x, w, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwwz() const TL_NOEXCEPT { return {x, w, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 xwww() const TL_NOEXCEPT { return {x, w, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxxx() const TL_NOEXCEPT { return {y, x, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxxy() const TL_NOEXCEPT { return {y, x, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxxz() const TL_NOEXCEPT { return {y, x, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxxw() const TL_NOEXCEPT { return {y, x, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxyx() const TL_NOEXCEPT { return {y, x, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxyy() const TL_NOEXCEPT { return {y, x, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxyz() const TL_NOEXCEPT { return {y, x, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxyw() const TL_NOEXCEPT { return {y, x, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxzx() const TL_NOEXCEPT { return {y, x, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxzy() const TL_NOEXCEPT { return {y, x, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxzz() const TL_NOEXCEPT { return {y, x, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxzw() const TL_NOEXCEPT { return {y, x, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxwx() const TL_NOEXCEPT { return {y, x, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxwy() const TL_NOEXCEPT { return {y, x, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxwz() const TL_NOEXCEPT { return {y, x, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yxww() const TL_NOEXCEPT { return {y, x, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyxx() const TL_NOEXCEPT { return {y, y, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyxy() const TL_NOEXCEPT { return {y, y, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyxz() const TL_NOEXCEPT { return {y, y, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyxw() const TL_NOEXCEPT { return {y, y, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyyx() const TL_NOEXCEPT { return {y, y, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyyy() const TL_NOEXCEPT { return {y, y, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyyz() const TL_NOEXCEPT { return {y, y, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyyw() const TL_NOEXCEPT { return {y, y, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyzx() const TL_NOEXCEPT { return {y, y, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyzy() const TL_NOEXCEPT { return {y, y, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyzz() const TL_NOEXCEPT { return {y, y, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyzw() const TL_NOEXCEPT { return {y, y, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yywx() const TL_NOEXCEPT { return {y, y, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yywy() const TL_NOEXCEPT { return {y, y, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yywz() const TL_NOEXCEPT { return {y, y, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yyww() const TL_NOEXCEPT { return {y, y, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzxx() const TL_NOEXCEPT { return {y, z, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzxy() const TL_NOEXCEPT { return {y, z, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzxz() const TL_NOEXCEPT { return {y, z, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzxw() const TL_NOEXCEPT { return {y, z, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzyx() const TL_NOEXCEPT { return {y, z, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzyy() const TL_NOEXCEPT { return {y, z, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzyz() const TL_NOEXCEPT { return {y, z, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzyw() const TL_NOEXCEPT { return {y, z, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzzx() const TL_NOEXCEPT { return {y, z, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzzy() const TL_NOEXCEPT { return {y, z, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzzz() const TL_NOEXCEPT { return {y, z, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzzw() const TL_NOEXCEPT { return {y, z, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzwx() const TL_NOEXCEPT { return {y, z, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzwy() const TL_NOEXCEPT { return {y, z, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzwz() const TL_NOEXCEPT { return {y, z, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 yzww() const TL_NOEXCEPT { return {y, z, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywxx() const TL_NOEXCEPT { return {y, w, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywxy() const TL_NOEXCEPT { return {y, w, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywxz() const TL_NOEXCEPT { return {y, w, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywxw() const TL_NOEXCEPT { return {y, w, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywyx() const TL_NOEXCEPT { return {y, w, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywyy() const TL_NOEXCEPT { return {y, w, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywyz() const TL_NOEXCEPT { return {y, w, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywyw() const TL_NOEXCEPT { return {y, w, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywzx() const TL_NOEXCEPT { return {y, w, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywzy() const TL_NOEXCEPT { return {y, w, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywzz() const TL_NOEXCEPT { return {y, w, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywzw() const TL_NOEXCEPT { return {y, w, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywwx() const TL_NOEXCEPT { return {y, w, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywwy() const TL_NOEXCEPT { return {y, w, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywwz() const TL_NOEXCEPT { return {y, w, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 ywww() const TL_NOEXCEPT { return {y, w, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxxx() const TL_NOEXCEPT { return {z, x, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxxy() const TL_NOEXCEPT { return {z, x, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxxz() const TL_NOEXCEPT { return {z, x, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxxw() const TL_NOEXCEPT { return {z, x, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxyx() const TL_NOEXCEPT { return {z, x, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxyy() const TL_NOEXCEPT { return {z, x, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxyz() const TL_NOEXCEPT { return {z, x, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxyw() const TL_NOEXCEPT { return {z, x, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxzx() const TL_NOEXCEPT { return {z, x, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxzy() const TL_NOEXCEPT { return {z, x, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxzz() const TL_NOEXCEPT { return {z, x, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxzw() const TL_NOEXCEPT { return {z, x, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxwx() const TL_NOEXCEPT { return {z, x, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxwy() const TL_NOEXCEPT { return {z, x, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxwz() const TL_NOEXCEPT { return {z, x, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zxww() const TL_NOEXCEPT { return {z, x, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyxx() const TL_NOEXCEPT { return {z, y, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyxy() const TL_NOEXCEPT { return {z, y, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyxz() const TL_NOEXCEPT { return {z, y, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyxw() const TL_NOEXCEPT { return {z, y, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyyx() const TL_NOEXCEPT { return {z, y, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyyy() const TL_NOEXCEPT { return {z, y, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyyz() const TL_NOEXCEPT { return {z, y, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyyw() const TL_NOEXCEPT { return {z, y, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyzx() const TL_NOEXCEPT { return {z, y, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyzy() const TL_NOEXCEPT { return {z, y, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyzz() const TL_NOEXCEPT { return {z, y, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyzw() const TL_NOEXCEPT { return {z, y, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zywx() const TL_NOEXCEPT { return {z, y, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zywy() const TL_NOEXCEPT { return {z, y, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zywz() const TL_NOEXCEPT { return {z, y, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zyww() const TL_NOEXCEPT { return {z, y, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzxx() const TL_NOEXCEPT { return {z, z, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzxy() const TL_NOEXCEPT { return {z, z, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzxz() const TL_NOEXCEPT { return {z, z, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzxw() const TL_NOEXCEPT { return {z, z, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzyx() const TL_NOEXCEPT { return {z, z, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzyy() const TL_NOEXCEPT { return {z, z, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzyz() const TL_NOEXCEPT { return {z, z, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzyw() const TL_NOEXCEPT { return {z, z, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzzx() const TL_NOEXCEPT { return {z, z, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzzy() const TL_NOEXCEPT { return {z, z, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzzz() const TL_NOEXCEPT { return {z, z, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzzw() const TL_NOEXCEPT { return {z, z, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzwx() const TL_NOEXCEPT { return {z, z, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzwy() const TL_NOEXCEPT { return {z, z, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzwz() const TL_NOEXCEPT { return {z, z, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zzww() const TL_NOEXCEPT { return {z, z, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwxx() const TL_NOEXCEPT { return {z, w, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwxy() const TL_NOEXCEPT { return {z, w, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwxz() const TL_NOEXCEPT { return {z, w, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwxw() const TL_NOEXCEPT { return {z, w, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwyx() const TL_NOEXCEPT { return {z, w, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwyy() const TL_NOEXCEPT { return {z, w, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwyz() const TL_NOEXCEPT { return {z, w, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwyw() const TL_NOEXCEPT { return {z, w, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwzx() const TL_NOEXCEPT { return {z, w, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwzy() const TL_NOEXCEPT { return {z, w, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwzz() const TL_NOEXCEPT { return {z, w, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwzw() const TL_NOEXCEPT { return {z, w, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwwx() const TL_NOEXCEPT { return {z, w, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwwy() const TL_NOEXCEPT { return {z, w, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwwz() const TL_NOEXCEPT { return {z, w, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 zwww() const TL_NOEXCEPT { return {z, w, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxxx() const TL_NOEXCEPT { return {w, x, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxxy() const TL_NOEXCEPT { return {w, x, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxxz() const TL_NOEXCEPT { return {w, x, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxxw() const TL_NOEXCEPT { return {w, x, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxyx() const TL_NOEXCEPT { return {w, x, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxyy() const TL_NOEXCEPT { return {w, x, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxyz() const TL_NOEXCEPT { return {w, x, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxyw() const TL_NOEXCEPT { return {w, x, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxzx() const TL_NOEXCEPT { return {w, x, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxzy() const TL_NOEXCEPT { return {w, x, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxzz() const TL_NOEXCEPT { return {w, x, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxzw() const TL_NOEXCEPT { return {w, x, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxwx() const TL_NOEXCEPT { return {w, x, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxwy() const TL_NOEXCEPT { return {w, x, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxwz() const TL_NOEXCEPT { return {w, x, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wxww() const TL_NOEXCEPT { return {w, x, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyxx() const TL_NOEXCEPT { return {w, y, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyxy() const TL_NOEXCEPT { return {w, y, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyxz() const TL_NOEXCEPT { return {w, y, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyxw() const TL_NOEXCEPT { return {w, y, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyyx() const TL_NOEXCEPT { return {w, y, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyyy() const TL_NOEXCEPT { return {w, y, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyyz() const TL_NOEXCEPT { return {w, y, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyyw() const TL_NOEXCEPT { return {w, y, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyzx() const TL_NOEXCEPT { return {w, y, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyzy() const TL_NOEXCEPT { return {w, y, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyzz() const TL_NOEXCEPT { return {w, y, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyzw() const TL_NOEXCEPT { return {w, y, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wywx() const TL_NOEXCEPT { return {w, y, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wywy() const TL_NOEXCEPT { return {w, y, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wywz() const TL_NOEXCEPT { return {w, y, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wyww() const TL_NOEXCEPT { return {w, y, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzxx() const TL_NOEXCEPT { return {w, z, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzxy() const TL_NOEXCEPT { return {w, z, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzxz() const TL_NOEXCEPT { return {w, z, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzxw() const TL_NOEXCEPT { return {w, z, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzyx() const TL_NOEXCEPT { return {w, z, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzyy() const TL_NOEXCEPT { return {w, z, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzyz() const TL_NOEXCEPT { return {w, z, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzyw() const TL_NOEXCEPT { return {w, z, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzzx() const TL_NOEXCEPT { return {w, z, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzzy() const TL_NOEXCEPT { return {w, z, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzzz() const TL_NOEXCEPT { return {w, z, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzzw() const TL_NOEXCEPT { return {w, z, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzwx() const TL_NOEXCEPT { return {w, z, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzwy() const TL_NOEXCEPT { return {w, z, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzwz() const TL_NOEXCEPT { return {w, z, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wzww() const TL_NOEXCEPT { return {w, z, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwxx() const TL_NOEXCEPT { return {w, w, x, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwxy() const TL_NOEXCEPT { return {w, w, x, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwxz() const TL_NOEXCEPT { return {w, w, x, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwxw() const TL_NOEXCEPT { return {w, w, x, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwyx() const TL_NOEXCEPT { return {w, w, y, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwyy() const TL_NOEXCEPT { return {w, w, y, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwyz() const TL_NOEXCEPT { return {w, w, y, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwyw() const TL_NOEXCEPT { return {w, w, y, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwzx() const TL_NOEXCEPT { return {w, w, z, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwzy() const TL_NOEXCEPT { return {w, w, z, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwzz() const TL_NOEXCEPT { return {w, w, z, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwzw() const TL_NOEXCEPT { return {w, w, z, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwwx() const TL_NOEXCEPT { return {w, w, w, x}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwwy() const TL_NOEXCEPT { return {w, w, w, y}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwwz() const TL_NOEXCEPT { return {w, w, w, z}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 wwww() const TL_NOEXCEPT { return {w, w, w, w}; }
      TL_NODISCARD TL_CONSTEXPR Vector4 operator+() TL_NOEXCEPT
      {
         return {+x,+y,+z,+w};
      }
      TL_NODISCARD TL_CONSTEXPR Vector4 operator-() TL_NOEXCEPT
      {
         return {-x,-y,-z,-w};
      }
      TL_CONSTEXPR Vector4& operator+=(Vector4 v) TL_NOEXCEPT
      {
         x += v.x;
         y += v.y;
         z += v.z;
         w += v.w;
         return *this;
      }
      TL_CONSTEXPR Vector4& operator-=(Vector4 v) TL_NOEXCEPT
      {
         x -= v.x;
         y -= v.y;
         z -= v.z;
         w -= v.w;
         return *this;
      }
      TL_CONSTEXPR Vector4& operator*=(Vector4 v) TL_NOEXCEPT
      {
         x *= v.x;
         y *= v.y;
         z *= v.z;
         w *= v.w;
         return *this;
      }
      TL_CONSTEXPR Vector4& operator/=(Vector4 v) TL_NOEXCEPT
      {
         x /= v.x;
         y /= v.y;
         z /= v.z;
         w /= v.w;
         return *this;
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector4 operator+(Vector4 a, Vector4 b) TL_NOEXCEPT
      {
         return
         {
            a.x + b.x,
            a.y + b.y,
            a.z + b.z,
            a.w + b.w,
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector4 operator-(Vector4 a, Vector4 b) TL_NOEXCEPT
      {
         return
         {
            a.x - b.x,
            a.y - b.y,
            a.z - b.z,
            a.w - b.w,
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector4 operator*(Vector4 a, Vector4 b) TL_NOEXCEPT
      {
         return
         {
            a.x * b.x,
            a.y * b.y,
            a.z * b.z,
            a.w * b.w,
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector4 operator/(Vector4 a, Vector4 b) TL_NOEXCEPT
      {
         return
         {
            a.x / b.x,
            a.y / b.y,
            a.z / b.z,
            a.w / b.w,
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend bool operator==(Vector4 a, Vector4 b) TL_NOEXCEPT
      {
         return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
      }
      TL_NODISCARD TL_CONSTEXPR friend bool operator!=(Vector4 a, Vector4 b) TL_NOEXCEPT
      {
         return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
      }
      TL_NODISCARD TL_CONSTEXPR static bool Equal(Vector4 a, Vector4 b, Scalar epsilon) TL_NOEXCEPT
      {
         return (
            Math::Abs(a.x - b.x) < epsilon &&
            Math::Abs(a.y - b.y) < epsilon &&
            Math::Abs(a.z - b.z) < epsilon &&
            Math::Abs(a.w - b.w) < epsilon);
      }
      TL_NODISCARD TL_CONSTEXPR static Scalar Dot(Vector4 a, Vector4 b) TL_NOEXCEPT
      {
         return a.x* b.x + a.y * b.y + a.z * b.z + a.w * b.w;
      }
      template<typename T>
      friend std::basic_ostream<T>& operator<<(std::basic_ostream<T> & s, Vector4 v) TL_NOEXCEPT
      {
         return s << '[' << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ']';
      }
   };
}