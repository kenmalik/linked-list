#ifndef NODE_ITERATOR_H
#define NODE_ITERATOR_H

#include "node.hpp"
#include <iterator>

template <typename T>
class NodeIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
public:
  NodeIterator();
  NodeIterator(Node<T> *current);

  // ++ prefix
  NodeIterator &operator++();

  // ++ postfix
  NodeIterator operator++(int);

  // -- prefix
  NodeIterator &operator--();

  // -- postfix
  NodeIterator operator--(int);

  // dereference
  T &operator*();

  // equal to
  template <typename U>
  friend bool operator==(const NodeIterator<U> &lhs,
                         const NodeIterator<U> &rhs);

  // not equal
  template <typename U>
  friend bool operator!=(const NodeIterator<U> &lhs,
                         const NodeIterator<U> &rhs);

private:
  Node<T> *current;
};

#include "node-iterator.cpp"

#endif // !NODE_ITERATOR_H
