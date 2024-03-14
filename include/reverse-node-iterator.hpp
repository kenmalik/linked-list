#ifndef REVERSE_NODE_ITERATOR_H
#define REVERSE_NODE_ITERATOR_H

#include "node.hpp"
#include <iterator>

template <typename T>
class ReverseNodeIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
public:
  ReverseNodeIterator();
  ReverseNodeIterator(Node<T> *current);

  // ++ prefix
  ReverseNodeIterator &operator++();

  // ++ postfix
  ReverseNodeIterator operator++(int);

  // -- prefix
  ReverseNodeIterator &operator--();

  // -- postfix
  ReverseNodeIterator operator--(int);

  // dereference
  T &operator*();

  // equal to
  template <typename U>
  friend bool operator==(const ReverseNodeIterator<U> &lhs,
                         const ReverseNodeIterator<U> &rhs);

  // not equal
  template <typename U>
  friend bool operator!=(const ReverseNodeIterator<U> &lhs,
                         const ReverseNodeIterator<U> &rhs);

private:
  Node<T> *current;
};

#include "reverse-node-iterator.cpp"

#endif // !REVERSE_NODE_ITERATOR_H
