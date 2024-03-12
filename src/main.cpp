#include "linked-list.hpp"
#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {
  LinkedList<int> list;

  list.push_front(2);
  std::cout << list << std::endl;

  list.push_back(3);
  std::cout << list << std::endl;

  list.push_front(1);
  std::cout << list << std::endl;

  list.pop_back();
  std::cout << list << std::endl;

  list.pop_front();
  std::cout << list << std::endl;

  list.pop_front();
  std::cout << list << std::endl;

  list.pop_front();
  std::cout << list << std::endl;

  return 0;
}

