#include "List.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

class Test
{
  public:
  Test()
  {
    std::cout << "Constructor" << std::endl;

  }

  Test( const Test& other )
  {
    std::cout << "Copy Constructor" << std::endl;
  }

  Test( Test&& other )
  {
    std::cout << "Move Constructor" << std::endl;
  }

  Test& operator=(const Test& other )
  {
    std::cout << "Copy operator" << std::endl;
  }

  Test& operator=( Test&& other )
  {
    std::cout << "Move operator" << std::endl;
  }

  ~Test()
  {
    std::cout << "Destructor" << std::endl;
  }
};


int main()
{
  List<int> list2;
  list2.push_back(3);
  list2.push_back(54);
  list2.push_back(45);
  list2.push_back(43);

  List<Test> list;
  Test t;

  list.push_back(Test());
  list.push_back(Test());

  for( auto it: list2)
  {
    std::cout<< it << std::endl;
  }


  return 0;
}