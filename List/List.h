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
    Node( const Type& tData, Node* tNext, Node* tPrevious ):
      data    ( tData     ),
      next    ( tNext     ),
      previous( tPrevious )
    {}    
    template<class... Args>
    Node( Args&&... args, Node* tNext, Node* tPrevious ) :
    data    ( std::forward<Args>( args )... ),
    next    ( tNext ),
    previous( tPrevious )
    {}

    ~Node() = default;
  };

  Node* first{ nullptr };
  Node* last{ nullptr };
  uint32_t length{ 0 };

public:
  List() = default;
  List( std::initializer_list<Type> init );
  List( const List& other );
  List( List&& other );
  List<Type>& operator=( const List& obj );
  List<Type>& operator=( List&& obj );
  ~List();
  void push_back( const Type& value );
  void push_front( const Type& value );
  template<class ... Args >
  void emplace_back( Args&&... args );
  template<class... Args>
  void emplace_front( Args&&... args );
  void print() const;

private:
  void copy( const List& other );
  void move( List && other );
};


#include "List.cpp"

#endif // _LIST_H
