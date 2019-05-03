#ifndef _TL_SQUARE_MATRIX_H
#define _TL_SQUARE_MATRIX_H

#include <cassert>
#include <iostream>

namespace GG
{
   template<class TScalar>
   struct SquareMatrix
   {
   public:
      using Scalar = TScalar;
      using FScalar = const Scalar &;
      using FSquareMatrix = const SquareMatrix &;
      static constexpr auto NothrowScalar = std::is_nothrow_default_constructible_v<Scalar>;
      SquareMatrix( unsigned size ) noexcept( NothrowScalar ) :
         m_Size( size ),
         m_Arr( new Scalar[m_Size * m_Size]{} )
      {
         assert( size > 1 && "Why not use just one scalar?" );
      }
      SquareMatrix( FSquareMatrix other ) noexcept( NothrowScalar ) :
         m_Size( other.m_Size ),
         m_Arr( new Scalar[m_Size * m_Size]{} )
      {
         for ( int i = 0; i < m_Size * m_Size; i++ )
            m_Arr[i] = other[i];
      }
      ~SquareMatrix()
      {
         delete[] m_Arr;
      }
      Scalar& operator[]( unsigned i ) noexcept
      {
         assert( i < m_Size * m_Size );
         return m_Arr[i];
      }
      const Scalar& operator[]( unsigned i ) const noexcept
      {
         assert( i < m_Size * m_Size );
         return m_Arr[i];
      }
      Scalar& Get( unsigned x, unsigned y ) noexcept
      {
         assert( y * m_Size + x );
         return m_Arr[y * m_Size + x];
      }
      const Scalar& Get( unsigned x, unsigned y ) const noexcept
      {
         assert( y * m_Size + x );
         return m_Arr[y * m_Size + x];
      }
      Scalar Determinant() const
      {
         Scalar result{};
         switch ( m_Size )
         {
         case 2:
         {
            result += Get( 0, 0 ) * Get( 1, 1 );
            result -= Get( 0, 1 ) * Get( 1, 0 );
            break;
         }
         case 3:
         {
            result += Get( 0, 0 ) * Get( 1, 1 ) * Get( 2, 2 );
            result += Get( 1, 0 ) * Get( 2, 1 ) * Get( 0, 2 );
            result += Get( 2, 0 ) * Get( 0, 1 ) * Get( 1, 2 );
            result -= Get( 2, 0 ) * Get( 1, 1 ) * Get( 0, 2 );
            result -= Get( 0, 0 ) * Get( 2, 1 ) * Get( 1, 2 );
            result -= Get( 1, 0 ) * Get( 0, 1 ) * Get( 2, 2 );
            break;
         }
         default:
            break;
         }
         return result;
      }
      SquareMatrix Transposed() const noexcept( NothrowScalar )
      {
         SquareMatrix ret( m_Size );
         for ( unsigned y = 0; y < m_Size; y++ )
            for ( unsigned x = 0; x < m_Size; x++ )
               ret.Get( x, y ) = Get( y, x );
         return ret;
      }
      SquareMatrix Inversed() const noexcept( NothrowScalar )
      {
         SquareMatrix ret( m_Size );
         switch ( m_Size )
         {
         case 2:
         {
            const auto& a = Get( 0, 0 );
            const auto& b = Get( 1, 0 );
            const auto& c = Get( 0, 1 );
            const auto& d = Get( 1, 1 );
            ret.Get( 0, 0 ) = -d / ( b * c - a * d );
            ret.Get( 1, 0 ) = b / ( b * c - a * d );
            ret.Get( 0, 1 ) = c / ( b * c - a * d );
            ret.Get( 1, 1 ) = -a / ( b * c - a * d );

            break;
         }
         default:
            break;
         }
         return ret;
      }
      friend SquareMatrix operator+( FSquareMatrix a, FSquareMatrix b ) noexcept( NothrowScalar )
      {
         assert( a.m_Size == b.m_Size );
         SquareMatrix ret( a.m_Size );
         for ( int i = 0; i < m_Size * m_Size; i++ )
            ret[i] = a[i] + b[i];
      }
      friend SquareMatrix operator-( FSquareMatrix a, FSquareMatrix b ) noexcept( NothrowScalar )
      {
         assert( a.m_Size == b.m_Size );
         SquareMatrix ret( a.m_Size );
         for ( int i = 0; i < m_Size * m_Size; i++ )
            ret[i] = a[i] - b[i];
      }
      friend SquareMatrix operator*( FSquareMatrix a, FSquareMatrix b ) noexcept( NothrowScalar )
      {
         assert( a.m_Size == b.m_Size );
         SquareMatrix ret( a.m_Size );

         for ( int i = 0; i < ret.m_Size * ret.m_Size; i += ret.m_Size )
            for ( int j = 0; j < ret.m_Size; j++ )
               for ( int n = 0; n < ret.m_Size; n++ )
                  ret[i + j] += a[i + n] * b[j + ret.m_Size * n];

         return ret;
      }
      template<class T>
      friend std::basic_ostream<T> & operator<<( std::basic_ostream<T> & os, FSquareMatrix m )
      {
         for ( int y = 0; y < m.m_Size; y++ )
         {
            os << "[" << m[y * m.m_Size];
            for ( int x = 1; x < m.m_Size; x++ )
               os << ", " << m[y * m.m_Size + x];
            os << "]\n";
         }
         return os;
      }
   private:
      unsigned m_Size;
      Scalar* m_Arr;
   };
}

#endif