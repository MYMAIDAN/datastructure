#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <initializer_list>
#include <type_traits>

template <class Type>
class List
{
private:

  struct Node
  {
    Type  data;
    Node* next;
    Node* previous;

    Node( const Type& tData, Node* tNext = nullptr, Node* tPrevious = nullptr ):
      data    ( tData     ),
      next    ( tNext     ),
      previous( tPrevious )
    {}

    Node( Type&& tData, Node* tNext = nullptr, Node* tPrevious = nullptr ):
      data    ( std::forward<Type>( tData ) ),
      next    ( tNext ),
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
  class iterator;
  List() = default;
  List( std::initializer_list<Type> init );
  List( const List& other );
  List( List&& other );
  List< Type >& operator=( const List& obj );
  List< Type >& operator=( List&& obj );
  ~List();
  //void push_back( const Type& value );
  template< class ParamType >
  void push_back( ParamType&& value );
  void push_front( const Type& value );
  void push_front( Type&& value );
  template< class ... Args >
  void emplace_back( Args&&... args );
  template< class... Args >
  void emplace_front( Args&&... args );
  void print() const;
  bool empty() const;

  // Access methods
  Type& front();
  const Type& front() const;
  Type& back();
  const Type& back() const;

  size_t size() const noexcept;
  size_t max_size() const noexcept;

  iterator begin();
  iterator end();

private:
  void copy( const List& other );
  void move( List && other );

public:
  class iterator: public std::iterator<std::bidirectional_iterator_tag,List<Type>>
  {
    private:
      List<Type>::Node* ptr{ nullptr };

    public:
      iterator( List<Type>::Node* obj );
      //iterator( const List< Type > other );
      iterator operator++();
      iterator operator++(int);
      iterator operator--();
      iterator operator--(int);
      Type& operator*();
      Type* operator->();
      bool operator!=( const iterator& other );

  };
};


#include "List.cpp"

#endif // _LIST_H
