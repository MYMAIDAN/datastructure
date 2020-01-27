#include "List.h"

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
  List<Test> list;
  list.push_back(Test());
  list.emplace_back();
  list.emplace_front();
  return 0;
}