#include "List.h"


int main()
{
  List<int> list;
  list.push_back(10);
  list.push_back(123);
  list.push_front(342);
  //list.print();

  List<int> list2 = list;

  list2.push_front(545);
    //list2.print();

  List<int> list3(std::move(list2));
  list3.print();

  return 0;
}