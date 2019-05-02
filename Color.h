#ifndef _TLIB_COLOR_H
#define _TLIB_COLOR_H

namespace TLib
{
   template<typename Scalar>
   struct Color
   {
      Scalar r, g, b, a;
   };
   using ColorF32 = Color<float>;
}

#endif