#ifndef _TL_TIME_H
#define _TL_TIME_H

#include "TLAttributes.h"

#if TL_IS_WINDOWS
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")
namespace TLib
{
   template<class Float>
   class FPSLocker
   {
   public:
      FPSLocker(Float minDelta) : minDelta(minDelta), delta(), lastTicks(), freq()
      {
         QueryPerformanceFrequency(&freq);
      }
      void Update()
      {
         LARGE_INTEGER currentTime;
         QueryPerformanceCounter(&currentTime);
         delta = (Float)(currentTime.QuadPart - lastTicks) / freq.QuadPart;
         lastTicks = currentTime.QuadPart;
         Float sleepSeconds = minDelta - delta;
         if (sleepSeconds > 0)
         {
            timeBeginPeriod(1);
            Sleep((DWORD)(sleepSeconds * 1000));
            timeEndPeriod(1);
         }
         QueryPerformanceCounter(&currentTime);
         delta = (Float)(currentTime.QuadPart - lastTicks) / freq.QuadPart;
         lastTicks = currentTime.QuadPart;
      }
      void SetMinDelta(Float v)
      {
         minDelta = v;
      }
   private:
      Float minDelta;
      Float delta;
      long long lastTicks;
      LARGE_INTEGER freq;
   };
   template<class Float>
   class Clock
   {
   public:
      Clock() : delta(), totalTime(), count(), lastTicks(), freq()
      {
         QueryPerformanceFrequency(&freq);
         LARGE_INTEGER currentTime;
         QueryPerformanceCounter(&currentTime);
         lastTicks = currentTime.QuadPart;
      }
      void Update()
      {
         LARGE_INTEGER currentTime;
         QueryPerformanceCounter(&currentTime);
         delta = (Float)(currentTime.QuadPart - lastTicks) / freq.QuadPart;
         totalTime += delta;
         lastTicks = currentTime.QuadPart;
         count++;
      }
      void SetMinDelta(Float v)
      {
         minDelta = v;
      }
      Float GetDelta() const
      {
         return delta;
      }
      Float GetTotalTime() const
      {
         return totalTime;
      }
      unsigned GetCount() const
      {
         return count;
      }
   private:
      Float delta, totalTime;
      unsigned count;
      long long lastTicks;
      LARGE_INTEGER freq;
   };
}
#endif /* WINDOWS */

#endif /* _TLIB_TIME_H */