#ifndef _TL_ATTRIBUTES_H
#define _TL_ATTRIBUTES_H

#pragma region -----[ Operating systems ]-----

#if defined _WIN32
  #ifdef _WIN64
    #define TL_OS_IS_WINDOWS_64 1
    #define TL_OS_IS_WINDOWS_32 0
  #else
    #define TL_OS_IS_WINDOWS_64 0
    #define TL_OS_IS_WINDOWS_32 1
  #endif
  #define TL_OS_IS_LINUX 0
  #define TL_OS_IS_MAC 0
#elif defined LINUX || defined __linux__
  #define TL_OS TL_OS_LINUX
#else
  #error Unresolved OS
#endif

#define TL_OS_IS_WINDOWS (TL_OS_IS_WINDOWS_64 | TL_OS_IS_WINDOWS_32)

#pragma endregion

#pragma region -----[ Compilers ]-----

#define TL_COMPILER_MSVC  0x1
#define TL_COMPILER_GCC   0x2
#define TL_COMPILER_CLANG 0x4

#if defined __clang__
  #define TL_COMPILER TL_COMPILER_CLANG
#elif defined __GNUC__
  #define TL_COMPILER TL_COMPILER_GCC
#elif defined _MSC_VER
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

#if TL_COMPILER == TL_COMPILER_MSVC
  #define TL_HAS_CXX98 (_MSVC_LANG>=199711L)
  #define TL_HAS_CXX11 (_MSVC_LANG>=201103L)
  #define TL_HAS_CXX14 (_MSVC_LANG>=201402L)
  #define TL_HAS_CXX17 (_MSVC_LANG>=201703L)
#else
  #define TL_HAS_CXX98 (__cplusplus>=199711L)
  #define TL_HAS_CXX11 (__cplusplus>=201103L)
  #define TL_HAS_CXX14 (__cplusplus>=201402L)
  #define TL_HAS_CXX17 (__cplusplus>=201703L)
#endif

#if TL_HAS_CXX17
  #define TL_CXX_VERSION 2017
#elif TL_HAS_CXX14
  #define TL_CXX_VERSION 2014
#elif TL_HAS_CXX11
  #define TL_CXX_VERSION 2011
#elif TL_HAS_CXX98
  #define TL_CXX_VERSION 1998
#endif

#if TL_CXX_VERSION < 2017
  #define TL_NODISCARD
  #define TL_FALLTHROUGH
  #define TL_MAYBE_UNUSED
  #define TL_CONSTEXPR_IF if
#else
  #define TL_NODISCARD [[nodiscard]]
  #define TL_FALLTHROUGH [[fallthrough]]
  #define TL_MAYBE_UNUSED [[maybe_unused]]
  #define TL_CONSTEXPR_IF if constexpr
#endif

#if TL_CXX_VERSION < 2014
  #if TL_COMPILER  == TL_COMPILER_MSVC
    #define TL_DEPRECATED __declspec(deprecated)
    #define TL_DEPRECATED_MSG(str) __declspec(deprecated(str))
  #else
    #define TL_DEPRECATED 
    #define TL_DEPRECATED_MSG(str) 
  #endif
#else
  #define TL_DEPRECATED [[deprecated]]
  #define TL_DEPRECATED_MSG(str) [[deprecated(str)]]
#endif

#if TL_CXX_VERSION < 2011
  #define TL_NORETURN 
  #define TL_NOEXCEPT throw()
  #define TL_CONSTEXPR
  #define TL_STATIC_ASSERT(...)
#else
  #define TL_NORETURN [[noreturn]]
  #define TL_NOEXCEPT noexcept
  #define TL_CONSTEXPR constexpr
  #define TL_STATIC_ASSERT(...) static_assert(__VA_ARGS__)
#endif

#endif