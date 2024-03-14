#ifndef NODE_ITERATOR_CPP
#define NODE_ITERATOR_CPP

#include "node-iterator.hpp"

template <typename T> NodeIterator<T>::NodeIterator() {}

template <typename T> NodeIterator<T>::NodeIterator(Node<T> *current) {
  this->current = current;
}

// ++ prefix
template <typename T> NodeIterator<T> &NodeIterator<T>::operator++() {
  current = current->next;
  return *this;
}

// ++ postfix
template <typename T> NodeIterator<T> NodeIterator<T>::operator++(int) {
  NodeIterator<T> temp = current;
  if (current != nullptr) {
    current = current->next;
  }
  return temp;
}

// -- prefix
template <typename T> NodeIterator<T> &NodeIterator<T>::operator--() {
  current = current->prev;
  return *this;
}

// -- postfix
template <typename T> NodeIterator<T> NodeIterator<T>::operator--(int) {
  NodeIterator<T> temp = current;
  if (current != nullptr) {
    current = current->prev;
  }
  return temp;
}

// dereference
template <typename T> T &NodeIterator<T>::operator*() { return current->data; }

// equal to
template <typename U>
bool operator==(const NodeIterator<U> &lhs, const NodeIterator<U> &rhs) {
  return lhs.current == rhs.current;
}

// not equal
template <typename U>
bool operator!=(const NodeIterator<U> &lhs, const NodeIterator<U> &rhs) {
  return lhs.current != rhs.current;
}

#endif // !NODE_ITERATOR_CPP
