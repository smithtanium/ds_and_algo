// NODE.hpp
#ifndef NODE_H // include guard
#define NODE_H

#include <stdint.h>

template <typename T>
class Node
{	
  public:
    Node();
    Node(T value);
    ~Node();

  //protected:
    T value;
    Node* next;
    Node* last;
};


template <class T>
Node<T>::Node()
{
  
}
template <class T>
Node<T>::Node(T value)
{
  this->value = value;
  next = nullptr;
  last = nullptr;
}

template <class T>
Node<T>::~Node()
{
}
/*
template class Node<int>;
template class Node<unsigned int>;
template class Node<float>;
template class Node<double>;
template class Node<uint8_t>;
template class Node<int8_t>;
template class Node<uint16_t>;
template class Node<int16_t>;
template class Node<uint32_t>;
template class Node<int32_t>;
template class Node<uint64_t>;
template class Node<int64_t>;
*/
#endif /* Node_H */

