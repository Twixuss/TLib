#ifndef _TL_RANDOM_COLOR_H
#define _TL_RANDOM_COLOR_H

#include "TLColor.h"
#include "TLRandom.h"

namespace TLib
{
   template<class Color>
   Color Random(typename Color::FScalar min, typename Color::FScalar max)
   {
      return
      {
         Random<Color::Scalar>(min, max),
         Random<Color::Scalar>(min, max),
         Random<Color::Scalar>(min, max),
      };
   }
}

#endif