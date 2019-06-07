#ifndef _TLIB_MONITOR_H
#define _TLIB_MONITOR_H

#include "TLAttributes.h"
#include "TLVector.h"
#if TL_OS_IS_WINDOWS
#include <Windows.h>
namespace TLib
{
   namespace Monitor
   {
      namespace Primary
      {
         inline Vec2i GetResolution()
         {
            return {GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)};
         }
      }
   }
}
#endif
#endif