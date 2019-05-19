#ifndef _TL_EXCEPTIONS_H
#define _TL_EXCEPTIONS_H

#include "Switches.h"

#if TL_ALLOW_THROW

#include "String.h"

#include <exception>

#define TL_CREATE_EXCEPTION(name)                                                                  \
class name##Exception : public std::exception                                                      \
{                                                                                                  \
public:                                                                                            \
   template<class...T>                                                                             \
   name##Exception( T&& ... t ) noexcept : exception( BuildString( #name "Exception:\n\n" , std::forward<T>( t )... ).c_str() ) \
   {                                                                                               \
   }                                                                                               \
}

namespace TLib
{
   TL_CREATE_EXCEPTION( AssertionFailed );
   TL_CREATE_EXCEPTION( DivideByZero );
   TL_CREATE_EXCEPTION( ExcessAction );
   TL_CREATE_EXCEPTION( OutOfRange );
   TL_CREATE_EXCEPTION( OutOfMemory );
}

#define TL_ASSERT(x) if(!(x))throw AssertionFailedException(#x)
#define TL_ASSERT_MSG(x, ...) if(!(x))throw AssertionFailedException(#x, __VA_ARGS__)

#endif /* TL_ALLOW_THROW */

#endif
