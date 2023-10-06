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
    List();
    List(T value);
    ~List();
    List(const List& aList);
    List(List& aList);
    // Copy assignement operator
    //Foo& operator=(const Foo& other);
    // Move assignment operator
    //Foo& operator=(Foo&& other);

    void assign(T size, T value);
    T back();
//    Node<T>::Iterator begin(); 
//    list::cbegin
//    list::cend
//    list::clear
//    list::crbegin
//    list::crend
//    list::emplace
//    list::emplace_back
//    list::emplace_front
//    list::empty
//    list::end
//    list::erase
    T front();
//    list::get_allocator
//    list::insert
//    list::max_size
//    list::merge
//    list::operator=
//    list::pop_back
//    list::pop_front
//    list::push_back
//    list::push_front
//    list::rbegin
//    list::remove
//    list::remove_if
//    list::rend
//    list::resize
//    list::reverse
    uint32_t size();
//    list::sort
//    list::splice
//    list::swap
//    list::unique
    
    void printList();
    Node<T>* getHeadNode();
    Node<T>* getTailNode();
      
  protected:
    Node<T> *head;
    Node<T> *tail;
    uint32_t length;
};

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

template <class T>
void assign(T size, T value)
{
}
template <class T>                                                                                                            
T List<T>::back()                                                                                                     
{                                                                                                                             
  return this->tail->value;                                                                                                   
}  



template <class T>
void List<T>::printList()
{
  Node<T> *temp = head;
  while (temp != nullptr)
  {
    std::cout << temp->value << std::endl;
    temp = temp->next;
  }
}

/* TODO: implement std::list functions
list::begin                                                                                                                   
list::cbegin                                                                                                                  
list::cend                                                                                                                    
list::clear                                                                                                                   
list::crbegin                                                                                                                 
list::crend                                                                                                                   
list::emplace                                                                                                                 
list::emplace_back                                                                                                            
list::emplace_front                                                                                                           
list::empty                                                                                                                   
list::end                                                                                                                     
list::erase                                                                                                                   
list::front                                                                                                                   
list::get_allocator                                                                                                           
list::insert                                                                                                                  
list::max_size                                                                                                                
list::merge                                                                                                                   
list::operator=                                                                                                               
list::pop_back                                                                                                                
list::pop_front                                                                                                               
list::push_back                                                                                                               
list::push_front                                                                                                              
list::rbegin                                                                                                                  
list::remove                                                                                                                  
list::remove_if                                                                                                               
list::rend                                                                                                                    
list::resize                                                                                                                  
list::reverse                                                                                                                 
list::size                                                                                                                    
list::sort                                                                                                                    
list::splice                                                                                                                  
list::swap                                                                                                                    
list::unique
*/

#endif /* LINKED_LIST_H */

