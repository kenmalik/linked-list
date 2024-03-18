#include "linked-list.hpp"
#include <iostream>
#include <ostream>

void f(const LinkedList<int> &l) {
  for (auto i = l.cbegin(); i != l.cend(); ++i) {
    std::cout << *i << " ";
  }
}

int main() {
  LinkedList<int> list;
  for (int i = 0; i < 10; i++)
    list += i;

  LinkedList<int> list2(list);

  std::cout << "\nIterator Test\n";
  for (auto i : list)
    std::cout << i;
  std::cout << "\n\nConst Iterator Test\n";
  for (auto i = list.cbegin(); i != list.cend(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << "\n\nreverse Iterator Test\n";
  for (auto i = list.rbegin(); i != list.rend(); ++i) {
    std::cout << *i << " ";
  }

  list.pop_front();
  list.pop_back();
  LinkedList<int> list3 = list;

  std::cout << "\n\nList 1: " << list << std::endl;
  std::cout << "List 2: " << list2 << std::endl;
  std::cout << "List 3: " << list3 << std::endl;

  return 0;
}
