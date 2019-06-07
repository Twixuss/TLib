#ifndef _TL_FILE_H
#define _TL_FILE_H

#include <fstream>
#include <vector>
#include <functional>
#include "String.h"
#include "Exceptions.h"
namespace TLib
{
   TL_CREATE_EXCEPTION( BadPath );
   template<class PathType>
   std::vector<char> ReadFileContents( PathType&& path ) noexcept
   {
      std::ifstream t(path, std::ios::binary);
      t.seekg(0, std::ios::end);
      size_t size = t.tellg();
      t.seekg(0);
      std::vector<char> buffer(size);
      t.read(buffer.data(), size);
      return buffer;
   }
   class TokenReader
   {
   public:
      static constexpr auto EndOfFileToken{ "$eof$" };
      static constexpr auto UnexpectedSymbolToken{ "$unexpected$" };
      template<class PathType, class SeparatorsType>
      TokenReader( const PathType& path, const SeparatorsType& sep, bool recognizeFloats = false ) :
         filename{ path },
         s{ path },
         separators{ sep },
         recognizeFloats{ recognizeFloats }
      {
         if ( !s.is_open() )
            throw BadPathException( "Bad path was passed to TLib::TokenReader: ", filename );
      }
      std::string NextToken()
      {
         isLiteral = false;
         charsToUnget = 0;
         int c = Get();
         if ( s.eof() )
            return EndOfFileToken;
         std::string result;
         while ( c == ' ' || c == '\n' )
         {
            if ( c == '\n' )
               NLCallBack();
            c = Get();
         }
         if ( IsSeparator( c ) )
         {
            result.push_back( c );
            return result;
         }
         const bool isNumber = isdigit( c );
         isLiteral = isNumber;
         bool secondPart = false;
         while ( 1 )
         {
            result.push_back( c );
            c = Get();
            if ( s.eof() )
               break;
            if ( secondPart )
            {
               if ( !isdigit( c ) )
               {
                  if ( IsSeparator( c ) )
                  {
                     Unget();
                     break;
                  }
                  if ( c != 'f' && c != ' ' && c != '\n' )
                     return UnexpectedSymbolToken;
                     //throw UnexpectedSymbolException(c, line, filename.c_str());
                  secondPart = false;
               }
               if ( IsSeparator( c ) )
               {
                  Unget();
                  break;
               }
            }
            else if ( isNumber && c == '.' )
               secondPart = true;
            else if ( IsSeparator( c ) )
            {
               Unget();
               break;
            }
            if ( c == ' ' || c == '\n' )
               break;
         }
         return result;
      }
      void UngetToken() noexcept
      {
         while ( charsToUnget-- )
            s.unget();

      }
      bool IsLastLiteral() noexcept
      {
         return isLiteral;
      }
      template<class Callback>
      void SetNewLineCallback( Callback c )
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
      bool IsSeparator( char c ) noexcept
      {
         for ( auto s : separators )
            if ( c == s )
               return true;
         return false;
      }
      void NLCallBack() noexcept
      {
         if ( nlcallback )
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