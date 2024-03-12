#include "linked-list.hpp"
#include <iostream>

void debugOut(LinkedList<int> &list, const char *message);

int main(int argc, char *argv[]) {
  LinkedList<int> list;

  debugOut(list, "No items");

  Node<int> node;
  node.data = 1;
  list.first_node(node);
  debugOut(list, "First node");

  list.push_back(node);
  debugOut(list, "Push back");

  list.push_front(node);
  debugOut(list, "Push front");

  return 0;
}

void debugOut(LinkedList<int> &list, const char *message) {
  std::cout << message << std::endl;

  std::cout << "Head: " << list.getHead() << std::endl;
  std::cout << "Tail: " << list.getTail() << std::endl;

  if (list.getHead()) {
    std::cout << "Head next: " << list.getHead()->next << std::endl;
    std::cout << "Head prev: " << list.getHead()->prev << std::endl;
    std::cout << "Head data: " << list.getHead()->data << std::endl;
  }

  if (list.getTail()) {
    std::cout << "Tail next: " << list.getTail()->next << std::endl;
    std::cout << "Tail prev: " << list.getTail()->prev << std::endl;
    std::cout << "Tail data: " << list.getTail()->data << std::endl;
  }

  std::cout << std::endl;
}
