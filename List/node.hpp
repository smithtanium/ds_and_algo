// NODE.hpp
#ifndef NODE_H // include guard
#define NODE_H

#include <stdint.h>

template <class T>
class Node
{	
  template<typename> friend class List;
  template<typename> friend class Iterator;

  public:
    Node();
    Node(T data);
    ~Node();

    //node functions
    void unlink();
    Node<T>* get_next();
    void set_next(Node<T> *a_node);
    Node<T>* get_prev();
    void set_prev(Node<T> *a_node);

    //data functions
    void push_back(Node<T> *aNode);
    void push_front(Node<T> *aNode);
    void set_data(T data);
    T get_data();

  protected:
    T data_;
    Node *next_, *prev_;
};


template <class T>
Node<T>::Node() : next_(nullptr), prev_(nullptr) {}

template <class T>
Node<T>::Node(T data) : next_(nullptr), prev_(nullptr), data_(data) {}

template <class T>
Node<T>::~Node()
{
  unlink();
}

/* **************************************************************************
 * **************************************************************************
 * Node functions
 * **************************************************************************
 * *************************************************************************/

template <class T>
void Node<T>::unlink()
{
  Node<T> *next = next_, *prev = prev_;
  next->set_prev(prev_);
  prev->set_next(next_);
  next_ = nullptr;
  prev_ = nullptr;
}

template <class T>
Node<T>* Node<T>::get_next()
{
  return next_;
}

template <class T>
void Node<T>::set_next(Node<T> *a_node)
{
  next_ = a_node;
}

template <class T>
Node<T>* Node<T>::get_prev()
{
  return prev_;
}

template <class T>
void Node<T>::set_prev(Node<T> *a_node)
{
  prev_ = a_node;
}

/* **************************************************************************
 * **************************************************************************
 * data functions
 * **************************************************************************
 * *************************************************************************/

template <class T>
void Node<T>::push_back(Node<T>* a_node)
{
  a_node->set_next(next_);
  this->next_ = a_node;
  a_node->set_prev(this);
}

template <class T>
void Node<T>::push_front(Node<T>* a_node)
{
  a_node->set_prev(prev_);
  a_node->set_next(this);
  this->prev_ = a_node;
}

template <class T>
void Node<T>::set_data(T data)
{
  data_ = data;
}

template <class T>
T Node<T>::get_data()
{
  return data_;
}

#endif /* Node_H */

