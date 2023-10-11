#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.hpp"
template <class T>
class Iterator 
{ 
  public: 
    Iterator() : 
        node_ (nullptr) { } 
  
    Iterator(const Node<T>* a_Node) : 
        node_ (a_Node) { } 
  
    //~Iterator<T>=default;
    

    Iterator& operator=(Node<T>* a_Node) 
    { 
      this->node_ = a_Node; 
      return *this; 
    } 
  
    // Prefix ++ overload 
    Iterator& operator++() 
    { 
      if (node_) 
      node_ = node_->get_next(); 
      return *this; 
    } 
  
    // Postfix ++ overload 
    Iterator operator++(int) 
    { 
      Iterator iterator = *this; 
      ++*this; 
      return iterator; 
    }

    bool operator==(const Iterator& iterator)
    {
      return node_ == iterator.node_;
    }

    bool operator!=(const Iterator& iterator) 
    { 
      return node_ != iterator.node_; 
    } 
  
    T operator*() 
    { 
      return node_->data; 
    } 
  protected:
    Node<T>* node_;  
  private: 
}; 

#endif /* ITERATOR_H */
