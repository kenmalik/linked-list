#ifndef CONST_NODE_ITERATOR_CPP
#define CONST_NODE_ITERATOR_CPP

#include "const-node-iterator.hpp"

template <typename T> ConstNodeIterator<T>::ConstNodeIterator() {}

template <typename T>
ConstNodeIterator<T>::ConstNodeIterator(Node<T> *current) {
  this->current = current;
}

// ++ prefix
template <typename T>
const ConstNodeIterator<T> &ConstNodeIterator<T>::operator++() {
  current = current->next;
  return *this;
}

// ++ postfix
template <typename T>
const ConstNodeIterator<T> ConstNodeIterator<T>::operator++(int) {
  const ConstNodeIterator<T> temp = current;
  if (current != nullptr) {
    current = current->next;
  }
  return temp;
}

// -- prefix
template <typename T>
const ConstNodeIterator<T> &ConstNodeIterator<T>::operator--() {
  current = current->prev;
  return *this;
}

// -- postfix
template <typename T>
const ConstNodeIterator<T> ConstNodeIterator<T>::operator--(int) {
  ConstNodeIterator<T> temp = current;
  if (current != nullptr) {
    current = current->prev;
  }
  return temp;
}

// dereference
template <typename T> const T &ConstNodeIterator<T>::operator*() {
  return current->data;
}

// equal to
template <typename U>
bool operator==(const ConstNodeIterator<U> &lhs,
                const ConstNodeIterator<U> &rhs) {
  return lhs.current == rhs.current;
}

// not equal
template <typename U>
bool operator!=(const ConstNodeIterator<U> &lhs,
                const ConstNodeIterator<U> &rhs) {
  return lhs.current != rhs.current;
}

#endif // !CONST_NODE_ITERATOR_CPP
