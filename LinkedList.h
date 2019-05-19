#ifndef _TL_LINKED_LIST_H
#define _TL_LINKED_LIST_H

namespace TLib
{
   template<class T>
   class LinkedList
   {
   public:
      using ValueType = T;
      struct Node
      {
         ValueType value;
         Node* next;
      };
      LinkedList()
      {
      }
      ~LinkedList()
      {
         if (head)
            delete head;
      }
   private:
      Node* head = nullptr;
   };
}

#endif