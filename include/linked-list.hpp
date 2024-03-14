#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "node-iterator.hpp"
#include "reverse-node-iterator.hpp"
#include <iostream>
#include <ostream>

template <typename T>
class LinkedList {
public:
  typedef NodeIterator<T> iterator;
  typedef NodeIterator<T> const_iterator;
  typedef ReverseNodeIterator<T> reverse_iterator;

  LinkedList();

  const Node<T> *getHead() const;
  const Node<T> *getTail() const;
  Node<T> *getHead();
  Node<T> *getTail();

  void push_front(const T &item);
  void push_back(const T &item);

  void pop_front();
  void pop_back();

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);

  iterator begin();
  iterator end();

  reverse_iterator rbegin();
  reverse_iterator rend();

private:
  Node<T> *head;
  Node<T> *tail;

  Node<T> *createNode(const T &data);
  void add_first_node(Node<T> *&node);

  void push_front(Node<T> *&node);
  void push_back(Node<T> *&node);

  Node<T> *search(const T &data);
  void remove(Node<T> *node);
  void remove_node(Node<T> *&node);
  void remove_last_node();
};

#include "linked-list.cpp"
#endif // !LINKED_LIST_HPP
