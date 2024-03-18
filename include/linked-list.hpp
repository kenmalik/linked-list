#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "const-node-iterator.hpp"
#include "node-iterator.hpp"
#include "reverse-node-iterator.hpp"
#include <iostream>
#include <ostream>

template <typename T> class LinkedList {
public:
  typedef NodeIterator<T> iterator;
  typedef ConstNodeIterator<T> const_iterator;
  typedef ReverseNodeIterator<T> reverse_iterator;

  LinkedList();
  LinkedList(const LinkedList &from);
  ~LinkedList();

  const Node<T> *getHead() const;
  const Node<T> *getTail() const;
  Node<T> *getHead();
  Node<T> *getTail();
  const size_t size() const;
  const bool empty() const;
  const T &front() const;
  const T &back() const;

  void push_front(const T &item);
  void push_back(const T &item);

  void pop_front();
  void pop_back();
  void clear();

  void insert_after(Node<T> *node, const T &item);
  void insert_before(Node<T> *node, const T &item);

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);

  void operator+=(const T &item);

  iterator begin();
  iterator end();

  reverse_iterator rbegin();
  reverse_iterator rend();

  const_iterator cbegin() const;
  const_iterator cend() const;

private:
  Node<T> *head;
  Node<T> *tail;

  size_t length;

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
