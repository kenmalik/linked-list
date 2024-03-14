#ifndef REVERSE_NODE_ITERATOR_CPP
#define REVERSE_NODE_ITERATOR_CPP

#include "reverse-node-iterator.hpp"

template <typename T> ReverseNodeIterator<T>::ReverseNodeIterator() {}

template <typename T> ReverseNodeIterator<T>::ReverseNodeIterator(Node<T> *current) {
  this->current = current;
}

// ++ prefix
template <typename T> ReverseNodeIterator<T> &ReverseNodeIterator<T>::operator++() {
  current = current->prev;
  return *this;
}

// ++ postfix
template <typename T> ReverseNodeIterator<T> ReverseNodeIterator<T>::operator++(int) {
  ReverseNodeIterator<T> temp = current;
  if (current != nullptr) {
    current = current->prev;
  }
  return temp;
}

// -- prefix
template <typename T> ReverseNodeIterator<T> &ReverseNodeIterator<T>::operator--() {
  current = current->next;
  return *this;
}

// -- postfix
template <typename T> ReverseNodeIterator<T> ReverseNodeIterator<T>::operator--(int) {
  ReverseNodeIterator<T> temp = current;
  if (current != nullptr) {
    current = current->next;
  }
  return temp;
}

// dereference
template <typename T> T &ReverseNodeIterator<T>::operator*() { return current->data; }

// equal to
template <typename U>
bool operator==(const ReverseNodeIterator<U> &lhs, const ReverseNodeIterator<U> &rhs) {
  return lhs.current == rhs.current;
}

// not equal
template <typename U>
bool operator!=(const ReverseNodeIterator<U> &lhs, const ReverseNodeIterator<U> &rhs) {
  return lhs.current != rhs.current;
}

#endif // !REVERSE_NODE_ITERATOR_CPP
