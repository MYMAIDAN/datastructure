#include <limits>

template <class Type>
List<Type>::List( std::initializer_list<Type> init )
{
  for( auto& listItem : init )
  {
    if( first == nullptr )
    {
      first = new Node( listItem, nullptr, nullptr );
      last = first;
    }
    else
    {
      last->next = new Node( listItem, nullptr, last );
      last = last->next;
    }
  }
}

template <class Type>
List<Type>::List( const List& other )
{
  copy( other );
}

template <class Type>
List<Type>::List( List&& other )
{
  move( std::forward<List>(other) );
}

template <class Type>
List<Type>& List<Type>::operator=( const List& other )
{
  if( this != &other )
  {
    copy( other );
  }
  return *this;
}

template <class Type>
List<Type>& List<Type>::operator=( List&& other )
{
  if( this != &other )
  {
    move( std::forward<List>( other ) );
  }
  return *this;
}

template<class Type>
List<Type>::~List()
{ 

  if( first != nullptr )
  {
    Node* temp{ nullptr };
    while( first->next != nullptr )
    {
      temp = first->next;;
      delete first;
      first = temp;
    }

  }


}

/*template<class Type>
void List<Type>::push_back( const Type& value )
{
  if( first == nullptr )
  {
    first = new Node( value, nullptr, nullptr );
    last = first;
  }
  else
  {
    last->next = new Node( value, nullptr, last );
    last = last->next;
  }
  length++;

}*/

template<class Type>
template<class ParamType>
void List<Type>::push_back( ParamType&& value )
{
  if( first == nullptr )
  {
    first = new Node( std::forward<ParamType>( value ), nullptr, nullptr );
    last = first;
  }
  else
  {
    last->next = new Node( std::forward<ParamType>( value ), nullptr, last );
    last = last->next;
  }
}

template<class Type>
void List<Type>::push_front( Type&& value )
{
  if( first == nullptr )
  {
    first = new Node( value, nullptr, nullptr );
    last = first;
  }
  else
  {
    first->previous = new Node( value, first, nullptr );
    first = first->previous;
  }
  length++;
}

template<class Type>
void List<Type>::push_front( const Type& value )
{
  if( first == nullptr )
  {
    first = new Node( value, nullptr, nullptr );
    last = first;
  }
  else
  {
    first->previous = new Node( value, first, nullptr );
    first = first->previous;
  }
  length++;
}

template<class Type>
template<class... Args>
void List<Type>::emplace_back( Args&&... args )
{
  if( first == nullptr )
  {
    first = new Node( std::forward<Args>( args )..., nullptr, nullptr );
    last = first;
  }
  else
  {
    last->next = new Node( std::forward<Args>( args )... , nullptr, last );
    last = last->next;
  }
  length++;
}

template<class Type>
template<class... Args>
void List<Type>::emplace_front( Args&&... args )
{
  if( first == nullptr )
  {
    first = new Node( std::forward<Args>( args )..., nullptr, nullptr );
    last = first;
  }
  else
  {
    last->next = new Node( std::forward<Args>( args )..., nullptr, last );
    last = last->next;
  }
  length++;
}


template<class Type>
void List<Type>::print() const
{
  Node* temp = first;
  while( temp != nullptr )
  {
    std::cout << "Node:" << temp->data << std::endl;
    temp = temp->next;
  }
}

template< class Type >
bool List< Type >::empty() const
{
  return (first == nullptr) && (length == 0);
}

template< class Type >
size_t List< Type >::size() const noexcept
{
  return length;
}

template< class Type >
size_t List< Type >::max_size() const noexcept
{
  std::numeric_limits< Type >::max();
}

template< class Type >
Type& List< Type >::front()
{
  return *first;
}

template< class Type >
const Type& List< Type >::front() const
{
  return *first;
}

template< class Type >
Type& List< Type >::back()
{
  return *last;
}

template< class Type >
const Type& List< Type >::back() const
{
  return *last;
}

template<class Type>
typename List<Type>::iterator List<Type>::begin()
{
  return iterator( this->first );
}

template<class Type>
typename List<Type>::iterator List<Type>::end()
{
  return iterator( this->last->next);
}

template<class Type>
void List<Type>::copy( const List& other )
{
  Node* otherTemp = other.first;
  Node* thisTemp = nullptr;

  if( this->first == nullptr )
  {
    this->first = new Node( otherTemp->data, nullptr, nullptr );
    otherTemp = otherTemp->next;
    this->last = this->first;
    while( otherTemp != nullptr )
    {
      last->next = new Node( otherTemp->data, nullptr, last );
      otherTemp = otherTemp->next;
      last = last->next;

    }
    this->length = other.length;
    last = thisTemp;

  }
  else
  {

    while( otherTemp->next != nullptr )
    {
      if( thisTemp->next == nullptr )
      {
        thisTemp->next = new Node( otherTemp->data, nullptr, thisTemp );
        thisTemp = thisTemp->next;
        otherTemp = otherTemp->next;
      }
      else
      {
        thisTemp->data = otherTemp->data;
        thisTemp       = thisTemp->next;
        otherTemp      = otherTemp->next;
      }
    }

    if( this->length < other.length )
    {
      this->last     = thisTemp;
      Node* del      = thisTemp;
      while( del != nullptr )
      {
        thisTemp = thisTemp->next;
        delete del;
        del = thisTemp;
      }
    }
  }
}

template <class Type>
void List<Type>::move( List&& other )
{
  this->first   = other.first;
  this->last    = other.last;
  this->length  = other.length;
  other.first   = nullptr;
  other.last    = nullptr;
  other.length  = 0;
}

template<class Type>
List<Type>::iterator::iterator( List<Type>::Node* pointer ):
  ptr( pointer )
  {
  }

template<class Type>
typename List<Type>::iterator List<Type>::iterator::operator++()
{
  iterator it( *this );
  ptr = ptr->next;
  return it;
}
template<class Type>
typename List<Type>::iterator List<Type>::iterator::operator++(int)
{
  ptr = ptr->next;
  return *this;
}

template<class Type>
typename List<Type>::iterator List<Type>::iterator::operator--()
{
  iterator it{ *this};
  ptr = ptr->previous;
  return it;
}

template<class Type>
typename List<Type>::iterator List<Type>::iterator ::operator--(int)
{
  ptr = ptr->previous;
  return *this;
}

template<class Type>
Type& List<Type>::iterator::operator*()
{
  return ptr->data;
}

template<class Type>
Type* List<Type>::iterator::operator->()
{
  return &ptr->data;
}

template<class Type>
bool List<Type>::iterator::operator!=( const List<Type>::iterator& other )
{
  return ptr != other.ptr;
}



