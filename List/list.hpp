// linked_list.hpp
#ifndef LINKED_LIST_H // include guard
#define LINKED_LIST_H

#include <stdint.h>
#include <iostream>

#include "iterator.hpp"
#include "node.hpp"

template <class T>
class List
{
  public:
    //standard functions	  
    List();
    List(T value);
    ~List();
    List(const List& aList);
    List(List& aList);
        
    //element access
    T back();
    T front();

    //capacity
    bool empty();
    uint32_t size();
    uint32_t max_size();

    //modifiers
    void clear();
    Iterator<T> insert(Iterator<T> positon, const T& data);
    //insert_range();
    //emplace();
    //erase();
    void push_front(T value);
    void push_back(T value);
    //emplace_back();
    //append_range();
    void pop_back();
    void pop_front();
    //resize();
    //swap();

    //operations
    //merge();
    //splice();
    //remove();
    //remove_if();
    //reverse();
    //unique();
    //sort();

    //iterators
    Iterator<T> begin();
    //cbegin();
    Iterator<T> end();
    //cend();
    //rbegin();
    //crbegin();
    //rend();
    
    //custom functions
    void print(); 
    Node<T>* get(uint32_t index); //return iterator?
    bool set(uint32_t index, uint32_t value);

  protected:
    Node<T> *head_;
    Node<T> *tail_;
    uint32_t length_;
};

/*****************************************************************
 * ***************************************************************
 * standard functions
 * ***************************************************************
 * **************************************************************/

//----------------------------------------------------------------
// Constructor
template <class T>
List<T>::List() : head_(nullptr), tail_(nullptr), length_(0) {}

template <class T>
List<T>::List(T data)
{
  Node<T> *newNode = new Node<T>(data);
  //newNode.set_data(data);
  head_ = newNode;
  tail_ = newNode;
  length_ = 1;
}

//----------------------------------------------------------------
// Destructor
template <class T>
List<T>::~List()
{
  Node<T> *temp = head_;
  while (head_)
  {
    head_ = head_->get_next();
    delete temp;
    temp = head_;
  }
}

//-----------------------------------------------------------------
// Move constructor
//List::List(List&& aListr) 
//{
//  *this = std::move(aList);
//}

//-----------------------------------------------------------------
// Copy assignement operator
//List& List::operator=(const List& aListr) {
//    this->value = aList.value;
//    return *this;
//}

//-----------------------------------------------------------------
// Move assignement operator
//List& List::operator=(List&& other) {
//    this->x = std::move(other.x);
//    return *this;
//}

//-----------------------------------------------------------------
// Some other operator
//int Foo::operator()() const {
//    return this->x;
//}

/* ***************************************************************
 * ***************************************************************
 * element access 
 * ***************************************************************
 * **************************************************************/

template <class T>                                                                                                            
T List<T>::back()
{
  return tail_.get_data();
}  

template <class T>
T List<T>::front()
{
  return head_.get_data();;
}

/* ***************************************************************
 * ***************************************************************
 * capacity  
 * ***************************************************************
 * **************************************************************/

template <class T>
bool List<T>::empty()
{
  return (0 == length_);
}

template <class T>
uint32_t List<T>::size()
{
  return length_;
}

template <class T>
uint32_t List<T>::max_size()
{
  return UINT32_MAX;
}

/* ***************************************************************
* ***************************************************************
* modifiers  
* ***************************************************************
* **************************************************************/

template <class T>
void List<T>::clear()
{
  Node<T> *temp = tail_;
  while (tail_)
  {
    tail_ = tail_->prev_;
    delete temp;
    temp = tail_;
  }
  
  head_= nullptr;
  tail_= nullptr;
  length_= 0;
}

template <class T>
Iterator<T> List<T>::insert(Iterator<T> position, const T& data)
{
  Node<T> *new_node = new Node<T>(data);
  Iterator<T> it = Iterator<T>(new_node);
  while (it != position)
  {
    it++;
  }

  it.node_->push_front(new_node);
  return it;
}

template <class T>
void List<T>::push_front(T data)
{
  Node<T> *newNode = new Node<T>(data);
  head_.push_front(newNode);

  //newNode.set(data);
  //newNode->next = head;
  //newNode->last = nullptr;
  //head->last = newNode; 
}

template <class T>
void List<T>::push_back(T data)
{
  Node<T> *newNode = new Node<T>(data);
  tail_.push_back(newNode);

  //newNode->value = value;
  //newNode->next = nullptr;
  //newNode->last = tail;
  //tail->next = newNode;  
}


//template <class T>
//iterator emplace(const_iterator position, Args args)
//{
//}

template <class T>
void List<T>::pop_back()
{
  Node<T> *temp = tail_;
  tail_ = tail_->prev;  
  temp.unlink();
  delete temp;
}

template <class T>
void List<T>::pop_front()
{
  Node<T> *temp = tail_; 	
  tail_ = tail_->prev;
  tail_->next = nullptr;
  delete temp;
}

/* ***************************************************************
* ***************************************************************
* iterators  
* ***************************************************************
* **************************************************************/

template <class T>
Iterator<T> List<T>::begin()
{
  Iterator<T> it = Iterator(this->head_);
  return it; 
}

//template <class T>
// void cbegin()
// {
// }

template <class T>
Iterator<T> List<T>::end()
{
  Iterator<T> it = Iterator(this->tail_);
  return it;
}

//template <class T>
// void cend()
// {
// }

//template <class T>
// void rbegin()
// {
// }

//template <class T>
// void crbegin()
// {
// }

//template <class T>
// void crend()
// {
// }

//template <class T>
// void crend()
// {
// }

/* ***************************************************************
* ***************************************************************
* operations  
* ***************************************************************
* **************************************************************/



/* ***************************************************************
* ***************************************************************
* custom functions  
* ***************************************************************
* **************************************************************/
	
template <class T>
void List<T>::print()
{
  Node<T> *temp = head_;
  while (temp != nullptr)
  {
    std::cout << temp->get_data() << std::endl;
    temp = temp->get_next();
  }
}

#endif /* LINKED_LIST_H */

