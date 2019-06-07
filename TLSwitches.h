#ifndef _TL_SWITHES_H
#define _TL_SWITHES_H

#ifndef TL_USE_SSE
#define TL_USE_SSE 1
#pragma message("TLib: TL_USE_SSE is not defined. Defaulting to 1")
#endif
#ifndef TL_ALLOW_THROW
#define TL_ALLOW_THROW 1
#pragma message("TLib: TL_ALLOW_THROW is not defined. Defaulting to 1")
#endif
#ifndef TL_CHECK_LEAKS
#define TL_CHECK_LEAKS 0
#pragma message("TLib: TL_CHECK_LEAKS is not defined. Defaulting to 0")
#endif

#endif
