#ifndef _TL_FUNCTIONAL_H
#define _TL_FUNCTIONAL_H

namespace TLib
{
   template<class ReturnType = void, class ...Args>
   class Function
   {
   public:
      using FunctionType = ReturnType( * )( Args... );
      Function() : m_Func( nullptr )
      {
      }
      template<class Fn>
      Function( Fn fn ) : m_Func( fn )
      {
      }
      ~Function() = default;
      Function( const Function& ) = default;
      Function( Function&& ) = default;
      Function& operator=( const Function& ) = default;
      Function& operator=( Function&& ) = default;
      ReturnType operator()( Args... args )
      {
         if ( m_Func )
            return m_Func( args... );
      }
   private:
      FunctionType m_Func;
   };
}

#endif