#ifndef _TLIB_MEMORY_H
#define _TLIB_MEMORY_H
#ifndef NDEBUG
#include <stdlib.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
namespace TLib
{
   struct MemoryLeakChecker
   {
      enum Output
      {
         StdOut, StdErr
      };
      _CrtMemState _ms;
      Output o;
      MemoryLeakChecker(Output mode) : o(mode)
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
         system("pause");
      }
   };
}
#else
namespace TLib
{
   struct MemoryLeakChecker
   {
      enum Output
      {
         StdOut, StdErr
      };
      MemoryLeakChecker(Output mode)
      {
      }
      ~MemoryLeakChecker()
      {
      }
   };
}
#endif

#endif