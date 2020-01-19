#include <iostream>

template <class Type>
class List
{
private:

  struct Node
  {
    Type  data;
    Node* next;
    Node* previous;
    Node( Type tData, Node* tNext, Node* tPrevious ):
      data    ( pData     ),
      next    ( tNext     ),
      previous( tPrevious )
    {}
  };

  Node* firt{ nullptr };
  Node* last{ nullptr };

public:
  void push_back( Type tData )
  {
    if( first == nullptr )
    {
      first = new Node( tData, nullptr, nullptr );
      last = firts;
    }
    else
    {
      last->next = new Node( tData, nullptr, last );
      last = last->next;
    }
  }

  void push_front( Type tData )
  {
    if( first == nullptr )
    {
      firt = new Node( tData, nullptr, nullptr );
      last = first;
    }
    else
    {
      first->previous = new Node( tData, first, nullptr );
      first = firts->previous;
    }
  }
}
