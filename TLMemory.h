#ifndef _TL_MEMORY_H
#define _TL_MEMORY_H
#include "TLSwitches.h"
#if !defined NDEBUG && TL_CHECK_LEAKS == 1
#include <stdlib.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
namespace TLib
{
#if !defined NDEBUG && TL_CHECK_LEAKS == 1
   struct MemoryLeakChecker
   {
      enum Output
      {
         StdOut, StdErr
      };
      _CrtMemState _ms;
      Output o;
      MemoryLeakChecker(Output mode = StdOut) : o(mode)
      {
         _CrtMemCheckpoint(&_ms);
      }
      ~MemoryLeakChecker()
      {
         _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
         switch (o)
         {
         case StdOut:
         default:
            _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
            break;
         case StdErr:
            _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
            break;
         }
         _CrtMemDumpAllObjectsSince(&_ms);
      }
   };
#else
   struct MemoryLeakChecker
   {
      enum Output
      {
         StdOut, StdErr
      };
      MemoryLeakChecker(Output mode = StdOut)
      {
      }
      ~MemoryLeakChecker()
      {
      }
   };
#endif
#pragma push_macro("new")
#undef new
   class Allocator
   {
   public:
      virtual ~Allocator() = default;
      virtual void* Allocate(size_t size) = 0;
      template<class T, class ...Args>
      T* Allocate(Args... args)
      {
         return new(Allocate(sizeof(T))) T(args...);
      }
      virtual void Deallocate(void* ptr) = 0;
   };
#pragma pop_macro("new")
}
#endif