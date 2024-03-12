#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "node.hpp"
#include <iostream>
#include <ostream>

template <typename T> class LinkedList {
public:
  LinkedList();

  const Node<T> *getHead() const;
  const Node<T> *getTail() const;

  void push_front(const T &item);
  void push_back(const T &item);

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);

  // TODO: Move these to private
  void remove(Node<T> *node);
  void pop_front();
  void pop_back();

private:
  Node<T> *head;
  Node<T> *tail;

  Node<T> *createNode(const T &data);
  void add_first_node(Node<T> *&node);

  void push_front(Node<T> *&node);
  void push_back(Node<T> *&node);

  Node<T> *search(const T &data);

  void remove_node(Node<T> *node);
};

#include "linked-list.cpp"
#endif // !LINKED_LIST_HPP
