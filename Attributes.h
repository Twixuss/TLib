#ifndef _TLIB_ATTRIBUTES_H
#define _TLIB_ATTRIBUTES_H

#pragma region -----[ Operating systems ]-----

#define TL_OS_WINDOWS_32 0x0001
#define TL_OS_WINDOWS_64 0x0002
#define TL_OS_LINUX      0x0004
#define TL_OS_MAC        0x0008

#define TL_OS_WINDOWS    (TL_OS_WINDOWS_32 | TL_OS_WINDOWS_64)

#ifdef _WIN32
  #ifdef _WIN64
    #define TL_OS TL_OS_WINDOWS_64
  #else
    #define TL_OS TL_OS_WINDOWS_32
  #endif
#elif defined(LINUX) || defined(__linux__)
  #define TL_OS TL_OS_LINUX
#else
  #error Unresolved OS
#endif

#define TL_OS_IS(os) (TL_OS & os)
#define TL_IS_WINDOWS TL_OS_IS(TL_OS_WINDOWS)

#pragma endregion

#pragma region -----[ Compilers ]-----

#define TL_COMPILER_MSVC   0x0001
#define TL_COMPILER_GCC   0x0002
#define TL_COMPILER_CLANG 0x0004

#ifdef _MSC_VER
  #define TL_COMPILER TL_COMPILER_MSVC
#endif

#pragma endregion

#define _TL_STRINGA(x) #x
#define  TL_STRINGA(x) _TL_STRINGA(x)

#define _TL_STRINGW(x) L#x
#define  TL_STRINGW(x) _TL_STRINGW(x)

#if TL_COMPILER == TL_COMPILER_MSVC
#define TL_NOVTABLE __declspec(novtable)
#define TL_ALIGN(x) __declspec(align(x))
#elif TL_COMPILER == TL_COMPILER_GCC
#define TL_NOVTABLE 
#define TL_ALIGN(x) __attribute__((aligned(x)))
#elif TL_COMPILER == TL_COMPILER_CLANG
#else
#error Unresolved compiler
#endif

#endif