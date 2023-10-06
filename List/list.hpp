// linked_list.hpp
#ifndef LINKED_LIST_H // include guard
#define LINKED_LIST_H

#include <stdint.h>
#include <iostream>
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
    //insert();
    //insert_range();
    //emplace();
    //erase();
    void push_front(T value);
    void push_back(T value);
    //emplace_back();
    //append_range();
    //pop_back();
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
    //begin();
    //cbegin();
    //end();
    //cend();
    //rbegin();
    //crbegin();
    //rend();
    
    //custom functions
    void print(); 
          
  protected:
    Node<T> *head;
    Node<T> *tail;
    uint32_t length;
};

/*****************************************************************
 * ***************************************************************
 * standard functions
 * ***************************************************************
 * **************************************************************/

//----------------------------------------------------------------
// Constructor
template <class T>
List<T>::List()
{
  Node<T> *newNode = nullptr;
  head = newNode;
  tail = newNode;
  length = 0;
}

template <class T>
List<T>::List(T value)
{
  Node<T> *newNode = new Node<T>;
  newNode->value = value;
  newNode->next = nullptr;
  newNode->last = nullptr;
  head = newNode;
  tail = newNode;
  length = 1;
}

//----------------------------------------------------------------
// Destructor
template <class T>
List<T>::~List()
{
  Node<T> *temp = head;
  while (head)
  {
    head = head->next;
    delete temp;
    temp = head;
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
  return tail->value;                                                                                                   
}  

template <class T>
T List<T>::front()
{
  return head->value;
}

/* ***************************************************************
 * ***************************************************************
 * capacity  
 * ***************************************************************
 * **************************************************************/

template <class T>
bool List<T>::empty()
{
  return (0 == length);
}

template <class T>
uint32_t List<T>::size()
{
  return length;
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
  Node<T> *temp = tail;
  while (tail)
  {
    tail = tail->last;
    delete temp;
    temp = tail;
  }
  
  head = nullptr;
  tail = nullptr;
  length = 0;
}

template <class T>
void List<T>::push_front(T value)
{
  Node<T> *newNode = new Node<T>;

  newNode->value = value;
  newNode->next = head;
  newNode->last = nullptr;
  head->last = newNode; 
}

template <class T>
void List<T>::push_back(T value)
{
  Node<T> *newNode = new Node<T>;

  newNode->value = value;
  newNode->next = nullptr;
  newNode->last = tail;
  tail->next = newNode;  
}


//template <class T>
//iterator emplace(const_iterator position, Args args)
//{
//}



/* ***************************************************************
* ***************************************************************
* iterators  
* ***************************************************************
* **************************************************************/

//template <class T>
// void begin()
// {
// }

//template <class T>
// void cbegin()
// {
// }

//template <class T>
//void end()
//{
//}

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
// void rend()
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
  Node<T> *temp = head;
  while (temp != nullptr)
  {
    std::cout << temp->value << std::endl;
    temp = temp->next;
  }
}

#endif /* LINKED_LIST_H */

