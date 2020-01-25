

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
      Node* del = thisTemp;
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
List<Type>::List( List&& other )
{
    this->first  = other.first;
    this->last   = other.last;
    this->length = other.length;
    other.first = nullptr;
    other.last  = nullptr;
    other.length = 0;
}

template <class Type>
void List<Type>::push_back( Type value )
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

}

template <class Type>
void List<Type>::push_front( Type value )
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


template <class Type>
void List<Type>::print() const
{
  Node* temp = first;
  while( temp != nullptr )
  {
    std::cout << "Node:" << temp->data << std::endl;
    temp = temp->next;
  }
}