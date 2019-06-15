#ifndef _TL_RANDOM_H
#define _TL_RANDOM_H

#include <random>
#include <numeric>

#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max

namespace TLib
{
   /*
   Returns a random number in range ['min';'max'].
   */
   template<class T>
   T Random(T min, T max)
   {      
      static std::mt19937 randMT(std::random_device{}());
      std::conditional_t<
         std::is_floating_point_v<T>,
         std::uniform_real_distribution<T>,
         std::uniform_int_distribution<T>> range(min, max);
      return range(randMT);
   }

   /*
   Returns a random number in range [0;'max'].
   */
   template<class T>
   T Random(T max)
   {      
      return Random<T>((T)0, max);
   }

   /*
   Returns a random number in full range.
   */
   template<class T>
   T Random()
   {      
      return Random<T>(std::numeric_limits<T>::min(),std::numeric_limits<T>::max());
   }
}

#pragma pop_macro("min")
#pragma pop_macro("max")
#endif