#include "linked-list.hpp"
#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {
  LinkedList<int> list;

  list.push_back(1);
  list.pop_back();
  std::cout << list << std::endl;

  for (int i = 0; i < 10; i++) {
    list.push_back(i);
  }

  for (auto x : list) {
    std::cout << x << std::endl;
  }

  LinkedList<int>::reverse_iterator reverse;
  for (reverse = list.rbegin(); reverse != list.rend(); reverse++) {
    std::cout << *reverse << std::endl;
  }

  std::cout << list << std::endl; // 0 1 2 3 4 5 6 7 8 9

  for (int i = 0; i < 10; i++) {
    list.push_front(i);
  }

  std::cout << list << std::endl; // 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
  for (int i = 0; i < 5; i++) {
    list.push_front(i);
    list.push_back(i + 10);
  }
  std::cout << list << std::endl; // 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6
                                  // 7 8 9 10 11 12 13 14
  return 0;
}
