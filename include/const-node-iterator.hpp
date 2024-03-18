#ifndef CONST_NODE_ITERATOR_H
#define CONST_NODE_ITERATOR_H

#include "node.hpp"
#include <iterator>

template <typename T>
class ConstNodeIterator
    : public std::iterator<std::bidirectional_iterator_tag, T> {
public:
  ConstNodeIterator();
  ConstNodeIterator(Node<T> *current);

  // ++ prefix
  const ConstNodeIterator &operator++();

  // ++ postfix
  const ConstNodeIterator operator++(int);

  // -- prefix
  const ConstNodeIterator &operator--();

  // -- postfix
  const ConstNodeIterator operator--(int);

  // dereference
  const T &operator*();

  // equal to
  template <typename U>
  friend bool operator==(const ConstNodeIterator<U> &lhs,
                         const ConstNodeIterator<U> &rhs);

  // not equal
  template <typename U>
  friend bool operator!=(const ConstNodeIterator<U> &lhs,
                         const ConstNodeIterator<U> &rhs);

private:
  const Node<T> *current;
};

#include "const-node-iterator.cpp"

#endif // !CONST_NODE_ITERATOR_H
