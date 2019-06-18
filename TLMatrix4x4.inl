namespace TLib
{
   template<class Scalar_>
   struct Matrix4x4
   {
      using Scalar = Scalar_;
      using FScalar = Scalar;
      using Vector2 = Vector3<Scalar>;
      using Vector3 = Vector3<Scalar>;
      using Vector4 = Vector4<Scalar>;
      using FVector2 = const Vector2 &;
      using FVector3 = const Vector3 &;
      using FVector4 = const Vector4 &;
      using Matrix3x3 = Matrix3x3<Scalar>;
      using FMatrix3x3 = const Matrix3x3 &;
      using FMatrix4x4 = const Matrix4x4 &;
      Vector4 i{};
      Vector4 j{};
      Vector4 k{};
      Vector4 l{};
      TL_CONSTEXPR Matrix4x4() = default;
      TL_CONSTEXPR Matrix4x4(FScalar v) noexcept :
         i(v),
         j(v),
         k(v),
         l(v)
      {
      }
      TL_CONSTEXPR Matrix4x4(FScalar ix, FScalar iy, FScalar iz, FScalar iw,
                             FScalar jx, FScalar jy, FScalar jz, FScalar jw,
                             FScalar kx, FScalar ky, FScalar kz, FScalar kw,
                             FScalar lx, FScalar ly, FScalar lz, FScalar lw) noexcept :
         i(ix, iy, iz, iw),
         j(jx, jy, jz, jw),
         k(kx, ky, kz, kw),
         l(lx, ly, lz, lw)
      {
      }
      TL_CONSTEXPR Matrix4x4(FVector4 v) noexcept :
         i(v),
         j(v),
         k(v),
         l(v)
      {
      }
      TL_CONSTEXPR Matrix4x4(FVector4 i, FVector4 j, FVector4 k, FVector4 l) noexcept :
         i(i),
         j(j),
         k(k),
         l(l)
      {
      }
      TL_CONSTEXPR Matrix4x4(FMatrix3x3 m) noexcept :
         i(  m.i  , 0),
         j(  m.j  , 0),
         k(  m.k  , 0),
         l(0, 0, 0, 1)
      {
      }
      TL_CONSTEXPR Matrix4x4(const Matrix4x4&) = default;
      TL_CONSTEXPR Matrix4x4(Matrix4x4&&) = default;
      TL_CONSTEXPR Matrix4x4& operator=(const Matrix4x4&) = default;
      TL_CONSTEXPR Matrix4x4& operator=(Matrix4x4&&) = default;
#pragma region [ Data ]
      TL_NODISCARD TL_CONSTEXPR Vector4* Data() noexcept
      {
         return &i;
      }
      TL_NODISCARD TL_CONSTEXPR const Vector4* Data() const noexcept
      {
         return &i;
      }
      TL_NODISCARD TL_CONSTEXPR Vector4& operator[](unsigned i) noexcept
      {
         return Data()[i];
      }
      TL_NODISCARD TL_CONSTEXPR const Vector4& operator[](unsigned i) const noexcept
      {
         return Data()[i];
      }
#pragma endregion
      TL_NODISCARD TL_CONSTEXPR Matrix4x4 Transposed() const noexcept
      {
         return {
            i.x, j.x, k.x, l.x,
            i.y, j.y, k.y, l.y,
            i.z, j.z, k.z, l.z,
            i.w, j.w, k.w, l.w,
         };
      }
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 Identity() noexcept
      {
         return
         {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
         };
      }
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 Translation(FScalar x, FScalar y, FScalar z = {}) noexcept
      {
         return
         {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            x, y, z, 1
         };
      }
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 Translation(FVector3 v) noexcept
      {
         return Translation(v.x, v.y, v.z);
      }
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 RotationX(FScalar a) noexcept
      {
         return
         {
            1,   0   ,   0   , 0,
            0, cos(a), sin(a), 0,
            0,-sin(a), cos(a), 0,
            0,   0   ,   0   , 1,
         };
      }
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 RotationY(FScalar a) noexcept
      {
         return
         {
            cos(a), 0, sin(a), 0,
              0   , 1,   0   , 0,
           -sin(a), 0, cos(a), 0,
              0   , 0,   0   , 1,
         };
      }
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 RotationZ(FScalar a) noexcept
      {
         return
         {
            cos(a), sin(a), 0, 0,
           -sin(a), cos(a), 0, 0,
              0   ,   0   , 1, 0,
              0   ,   0   , 0, 1
         };
      }
      //Roll, Pitch, Yaw (ZXY)
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 RotationZXY(FScalar x, FScalar y, FScalar z) noexcept
      {
         return (RotationY(y) * RotationX(x))* RotationZ(z);
      }
      //Yaw, Pitch, Roll (YXZ)
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 RotationYXZ(FScalar x, FScalar y, FScalar z) noexcept
      {
         return (RotationZ(z) * RotationX(x))* RotationY(y);
      }
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 RotationZXY(FVector4 v) noexcept
      {
         return RotationZXY(v.x, v.y, v.z);
      }
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 RotationYXZ(FVector4 v) noexcept
      {
         return RotationYXZ(v.x, v.y, v.z);
      }
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 Scaling(FScalar x, FScalar y, FScalar z = (Scalar)1) noexcept
      {
         return
         {
            x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, z, 0,
            0, 0, 0, 1
         };
      }
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 Orthographic(FScalar w, FScalar h, FScalar nearZ, FScalar farZ)
      {
         TL_ASSERT(!Math::Equal<Scalar>(w,    (Scalar)0.0, (Scalar)0.00001));
         TL_ASSERT(!Math::Equal<Scalar>(h,    (Scalar)0.0, (Scalar)0.00001));
         TL_ASSERT(!Math::Equal<Scalar>(farZ, nearZ,       (Scalar)0.00001));
         Scalar range = 1.0 / (farZ-nearZ);
         return 
         {
            2 / w, 0,    0,     0,
            0,     2 / h,0,     0,
            0,     0,    range, -range * nearZ,
            0,     0,    0,     1,
         };
      }
      TL_NODISCARD TL_CONSTEXPR static Matrix4x4 Perspective(FScalar fov, FScalar aspect, FScalar nz, FScalar fz) noexcept
      {
         Scalar h = 1.0f / tan(fov * (Scalar)Math::Pi / 360.0f);
         Scalar w = h / aspect;
         Scalar fzdfmn = fz / (fz - nz);
         return
         {
            w, 0,      0     , 0,
            0, h,      0     , 0,
            0, 0,   fzdfmn   , 1,
            0, 0,-fzdfmn * nz, 0
         };
      }
      TL_NODISCARD TL_CONSTEXPR Matrix4x4& operator*=(FMatrix4x4 m)
      {
         i = m * i;
         j = m * j;
         k = m * k;
         l = m * l;
         return *this;
      }
      TL_NODISCARD TL_CONSTEXPR friend Vector4 operator*(FMatrix4x4 a, FVector4 b) noexcept
      {
         return
         {
            a.i.x * b.x + a.j.x * b.y + a.k.x * b.z + a.l.x * b.w,
            a.i.y * b.x + a.j.y * b.y + a.k.y * b.z + a.l.y * b.w,
            a.i.z * b.x + a.j.z * b.y + a.k.z * b.z + a.l.z * b.w,
            a.i.w * b.x + a.j.w * b.y + a.k.w * b.z + a.l.w * b.w,
         };
      }
      TL_NODISCARD TL_CONSTEXPR friend Matrix4x4 operator*(FMatrix4x4 a, FMatrix4x4 b) noexcept
      {
         return
         {
            a * b.i,
            a * b.j,
            a * b.k,
            a * b.l
         };
      }
      template<typename T>
      friend std::basic_ostream<T>& operator<<(std::basic_ostream<T> & s, FMatrix4x4 m) noexcept
      {
         return s << m.i << '\n' << m.j << '\n' << m.k << '\n' << m.l;
      }
   };
}