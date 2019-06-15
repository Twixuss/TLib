#ifndef _TL_EXCEPTIONS_H
#define _TL_EXCEPTIONS_H

#include "TLSwitches.h"

#include <exception>

#if TL_ALLOW_THROW

#include "TLString.h"


#define TL_CREATE_EXCEPTION(name)                                                                 \
class name##Exception : public std::exception                                                     \
{                                                                                                 \
public:                                                                                           \
   template<class...T>                                                                            \
   name##Exception(T&&... t) noexcept : exception(BuildString(#name "Exception:\n", t...).data()) \
   {                                                                                              \
   }                                                                                              \
}

namespace TLib
{
   TL_CREATE_EXCEPTION(AssertionFailed);
   TL_CREATE_EXCEPTION(DivideByZero);
   TL_CREATE_EXCEPTION(ExcessAction);
   TL_CREATE_EXCEPTION(FileNotFound);
   TL_CREATE_EXCEPTION(NotImplemented);
   TL_CREATE_EXCEPTION(OutOfRange);
   TL_CREATE_EXCEPTION(OutOfMemory);
}

#define TL_THROW(type,...) do{__debugbreak();throw type("File: " __FILE__ "\nLine: " TL_STRINGA(__LINE__) "\n", __VA_ARGS__);}while(0)

#define TL_ASSERT(x) if(!(x))TL_THROW(AssertionFailedException,#x)
#define TL_ASSERT_MSG(x, ...) if(!(x))TL_THROW(AssertionFailedException,#x, __VA_ARGS__)

#endif /* TL_ALLOW_THROW */

#endif
