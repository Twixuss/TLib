#ifndef _TL_EXCEPTIONS_H
#define _TL_EXCEPTIONS_H

#include "Switches.h"

#if TL_ALLOW_THROW

#include "String.h"

#include <exception>

#define TL_EXCEPTION_CLASS(name)                                                   \
class name : public std::exception                                                 \
{                                                                                  \
public:                                                                            \
   template<class...T>                                                             \
   name( T&& ... t ) : exception( BuildString( std::forward<T>( t )... ).c_str() ) \
   {                                                                               \
   }                                                                               \
}

namespace TLib
{
   TL_EXCEPTION_CLASS( OutOfRangeException );
   TL_EXCEPTION_CLASS( OutOfMemoryException );
   TL_EXCEPTION_CLASS( ExcessActionException );
}

#undef TL_EXCEPTION_CLASS

#endif

#endif
