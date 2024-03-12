#include "node.hpp"

template <typename T> class LinkedList {
public:
  LinkedList();
  void first_node(const Node<T> &node);
  void push_back(const Node<T> &node);

  const Node<T> *getHead() const;
  const Node<T> *getTail() const;

private:
  Node<T> *head;
  Node<T> *tail;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T> void LinkedList<T>::first_node(const Node<T> &node) {
  Node<T> *n = new Node<T>(node);
  n->next = nullptr;
  n->prev = nullptr;
  head = n;
  tail = n;
}

template <typename T> void LinkedList<T>::push_back(const Node<T> &node) {
  Node<T> *n = new Node<T>(node);
  tail->next = n;
  n->prev = tail;
  tail = n;
  n->next = nullptr;
}

template <typename T> const Node<T> *LinkedList<T>::getHead() const {
  return head;
}

template <typename T> const Node<T> *LinkedList<T>::getTail() const {
  return tail;
}
