#include <iostream>
#include "list.hpp"

int main(void)
{
  std::cout << "Hello, World!" <<std::endl;

  List<int> a_list(15);
  a_list.insert(a_list.begin(), 10);
  a_list.print();  
  return 0;
}
