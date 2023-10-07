#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.hpp"

class Iterator 
{ 
  public: 
    Iterator() noexcept : 
        m_pCurrentNode (m_spRoot) { } 
  
    Iterator(const Node* pNode) noexcept : 
        m_pCurrentNode (pNode) { } 
  
    Iterator& operator=(Node* pNode) 
    { 
      this->m_pCurrentNode = pNode; 
      return *this; 
    } 
  
    // Prefix ++ overload 
    Iterator& operator++() 
    { 
      if (m_pCurrentNode) 
      m_pCurrentNode = m_pCurrentNode->pNext; 
      return *this; 
    } 
  
    // Postfix ++ overload 
    Iterator operator++(int) 
    { 
      Iterator iterator = *this; 
      ++*this; 
      return iterator; 
    } 
  
    bool operator!=(const Iterator& iterator) 
    { 
      return m_pCurrentNode != iterator.m_pCurrentNode; 
    } 
  
    int operator*() 
    { 
      return m_pCurrentNode->data; 
    } 
  
  private: 
    const Node* m_pCurrentNode; 
}; 

#endif /* ITERATOR_H */
