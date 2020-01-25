#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <initializer_list>

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
      data    ( tData     ),
      next    ( tNext     ),
      previous( tPrevious )
    {}

    ~Node() = default;
  };

  Node* first{ nullptr };
  Node* last{ nullptr };
  uint32_t length{ 0 };

public:

  class iterator
  {
  public:
    iterator();
    operator->();


  private:
     Node* data{ nullptr };

  };


public:

  List() = default;
  List( std::initializer_list<Type> init );
  List( const List& other );
  List( List&& other );
  //void operator=( const List& obj );
  //void operator=( List&& obj );
  //~List();
  void push_back( Type value );
  void push_front( Type value );
  void print() const;
};


#include "List.cpp"

#endif // _LIST_H
