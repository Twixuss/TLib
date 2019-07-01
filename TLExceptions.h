#ifndef _TL_EXCEPTIONS_H
#define _TL_EXCEPTIONS_H

#include "TLSwitches.h"

#include <exception>

#if TL_ALLOW_THROW

#include "TLString.h"


#define TL_CREATE_EXCEPTION(name)                                                                 \
class name : public std::exception                                                     \
{                                                                                                 \
public:                                                                                           \
   template<class...T>                                                                            \
   name(T&&... t) noexcept : exception(BuildString(#name ":\n", t...).data()) \
   {                                                                                              \
   }                                                                                              \
}

namespace TLib
{
   TL_CREATE_EXCEPTION(AssertionFailedException);
   TL_CREATE_EXCEPTION(DivideByZeroException);
   TL_CREATE_EXCEPTION(ExcessActionException);
   TL_CREATE_EXCEPTION(FileNotFoundException);
   TL_CREATE_EXCEPTION(NotImplementedException);
   TL_CREATE_EXCEPTION(OutOfRangeException);
   TL_CREATE_EXCEPTION(OutOfMemoryException);
}

#define TL_THROW(type,...) do{__debugbreak();throw type("File: " __FILE__ "\nLine: " TL_STRINGA(__LINE__) "\n", __VA_ARGS__);}while(0)

#define TL_ASSERT(x) if(!(x))TL_THROW(AssertionFailedException,#x)
#define TL_ASSERT_MSG(x, ...) if(!(x))TL_THROW(AssertionFailedException,#x, __VA_ARGS__)

#endif /* TL_ALLOW_THROW */

#endif
