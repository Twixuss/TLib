#ifndef _TLIB_FILE_H
#define _TLIB_FILE_H

#include <fstream>
#include <vector>
#include <functional>
#include "String.h"

namespace TLib
{
   template<class PathType>
   std::string ReadFileContents(PathType&& path) noexcept
   {
      std::ifstream s(std::forward<PathType>(path));
      if ( !s.is_open( ) )
         return "";
      std::string contents;
      contents.reserve(256);
      while (1)
      {
         auto c = s.get();
         if (s.eof())
            break;
         contents.push_back(c);
      }
      return contents;
   }
   class TokenReader
   {
   public:
      class UnexpectedSymbolException : public std::exception
      {
      public:
         UnexpectedSymbolException(char c, unsigned line, const char* file) :
            exception(BuildString("Failed to read floating point number. Unexpected symbol: ", c, " on line ", line, " in file ", file).c_str())
         {
         }
      };
      static constexpr auto EndOfFileToken = "$eof$";
      static constexpr auto UnexpectedSymbolToken = "$unexpected$";
      template<class PathType, class SeparatorsType>
      TokenReader(const PathType& path, const SeparatorsType& sep, bool recognizeFloats = false) noexcept :
         filename(path),
         s(path),
         separators(sep),
         recognizeFloats(recognizeFloats)
      {
         if (!s.is_open())
            std::exception(("Bad path has been passed to TLib::TokenReader: " + filename).c_str());
      }
      std::string NextToken() noexcept
      {
         isLiteral = false;
         charsToUnget = 0;
         int c = Get();
         if (s.eof())
            return EndOfFileToken;
         std::string result;
         while (c == ' ' || c == '\n')
         {
            if (c == '\n')
               NLCallBack();
            c = Get();
         }
         if (IsSeparator(c))
         {
            result.push_back(c);
            return result;
         }
         const bool isNumber = isdigit(c);
         isLiteral = isNumber;
         bool secondPart = false;
         while (1)
         {
            result.push_back(c);
            c = Get();
            if (s.eof())
               break;
            if (secondPart)
            {
               if (!isdigit(c))
               {
                  if (IsSeparator(c))
                  {
                     Unget();
                     break;
                  }
                  if ( c != 'f' && c != ' ' && c != '\n' )
                     return UnexpectedSymbolToken;
                     //throw UnexpectedSymbolException(c, line, filename.c_str());
                  secondPart = false;
               }
               if (IsSeparator(c))
               {
                  Unget();
                  break;
               }
            }
            else if (isNumber && c == '.')
               secondPart = true;
            else if (IsSeparator(c))
            {
               Unget();
               break;
            }
            if (c == ' ' || c == '\n')
               break;
         }
         return result;
      }
      void UngetToken() noexcept
      {
         while (charsToUnget--)
            s.unget();

      }
      bool IsLastLiteral() noexcept
      {
         return isLiteral;
      }
      template<class Callback>
      void SetNewLineCallback(Callback c)
      {
         nlcallback = c;
      }
   private:
      int Get() noexcept
      {
         charsToUnget++;
         return s.get();
      }
      void Unget() noexcept
      {
         charsToUnget--;
         s.unget();
      }
      bool IsSeparator(char c) noexcept
      {
         for (auto s : separators)
            if (c == s)
               return true;
         return false;
      }
      void NLCallBack() noexcept
      {
         if (nlcallback)
            nlcallback();
      }
      std::function<void()> nlcallback = nullptr;
      bool isLiteral = false;
      int charsToUnget = 0;
      bool recognizeFloats;
      unsigned line = 0;
      std::string separators, filename;
      std::ifstream s;
   };
}

#endif