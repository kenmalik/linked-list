#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "linked-list.hpp"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), length(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &from)
    : head(nullptr), tail(nullptr), length(0) {
  *this = from;
}

template <typename T> LinkedList<T>::~LinkedList<T>() { clear(); }

template <typename T> Node<T> *LinkedList<T>::createNode(const T &data) {
  return new Node<T>({data});
}

template <typename T> void LinkedList<T>::add_first_node(Node<T> *&node) {
  head = node;
  tail = node;
  length++;
}

template <typename T> void LinkedList<T>::push_front(Node<T> *&node) {
  head->prev = node;
  node->next = head;
  head = node;
  length++;
}

template <typename T> void LinkedList<T>::push_front(const T &item) {
  Node<T> *node = createNode(item);
  if (head == nullptr) {
    add_first_node(node);
  } else {
    push_front(node);
  }
}

template <typename T> void LinkedList<T>::push_back(Node<T> *&node) {
  tail->next = node;
  node->prev = tail;
  tail = node;
  length++;
}

template <typename T> void LinkedList<T>::push_back(const T &item) {
  Node<T> *node = createNode(item);
  if (head == nullptr) {
    add_first_node(node);
  } else {
    push_back(node);
  }
}

template <typename T> Node<T> *LinkedList<T>::getHead() { return head; }

template <typename T> const Node<T> *LinkedList<T>::getHead() const {
  return head;
}

template <typename T> Node<T> *LinkedList<T>::getTail() { return tail; }

template <typename T> const Node<T> *LinkedList<T>::getTail() const {
  return tail;
}

template <typename U>
std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list) {
  Node<U> *w = list.head;
  std::cout << "[";
  while (w != nullptr) {
    std::cout << w->data;
    if (w->next != nullptr) {
      std::cout << ", ";
    }
    w = w->next;
  }
  std::cout << "]";
  return os;
}

template <typename T> void LinkedList<T>::operator+=(const T &item) {
  push_back(item);
}

template <typename T> void LinkedList<T>::operator=(const LinkedList<T> &from) {
  clear();
  if (from.empty()) {
    return;
  }
  Node<T> *n = from.head;
  while (n != nullptr) {
    push_back(n->data);
    n = n->next;
  }
}

template <typename T> Node<T> *LinkedList<T>::search(const T &data) {
  Node<T> *w = head;
  while (w != nullptr) {
    if (w->data == data) {
      return w;
    }
    w = w->next;
  }
  return nullptr;
}

template <typename T> void LinkedList<T>::remove(Node<T> *node) {
  Node<T> *w = head;
  while (w != nullptr) {
    if (w == node) {
      remove_node(node);
      return;
    }
    w = w->next;
  }
}

template <typename T> void LinkedList<T>::remove_node(Node<T> *&node) {
  if (node == head) {
    pop_front();
  } else if (node == tail) {
    pop_back();
  } else {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    delete node;
    length--;
  }
}

template <typename T> void LinkedList<T>::pop_front() {
  if (head == nullptr || tail == nullptr) {
    return;
  }
  if (head == tail) {
    remove_last_node();
  } else {
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    length--;
  }
}

template <typename T> void LinkedList<T>::pop_back() {
  if (head == nullptr || tail == nullptr) {
    return;
  }
  if (head == tail) {
    remove_last_node();
  } else {
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    length--;
  }
}

template <typename T> void LinkedList<T>::remove_last_node() {
  delete head;
  head = nullptr;
  tail = nullptr;
  length--;
}

template <typename T> typename LinkedList<T>::iterator LinkedList<T>::begin() {
  return NodeIterator<T>(head);
}

template <typename T> typename LinkedList<T>::iterator LinkedList<T>::end() {
  return NodeIterator<T>(nullptr);
}

template <typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rbegin() {
  return ReverseNodeIterator<T>(tail);
}

template <typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rend() {
  return ReverseNodeIterator<T>(nullptr);
}

template <typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::cbegin() const {
  return ConstNodeIterator<T>(head);
}

template <typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::cend() const {
  return ConstNodeIterator<T>(nullptr);
}

template <typename T>
void LinkedList<T>::insert_after(Node<T> *node, const T &item) {
  if (node == tail) {
    push_back(item);
    return;
  }
  Node<T> *n = createNode(item);
  n->prev = node;
  n->next = node->next;
  node->next->prev = n;
  node->next = n;
  length++;
}

template <typename T>
void LinkedList<T>::insert_before(Node<T> *node, const T &item) {
  if (node == head) {
    push_front(item);
    return;
  }
  insert_after(node->prev, item);
}

template <typename T> const size_t LinkedList<T>::size() const {
  return length;
}

template <typename T> const bool LinkedList<T>::empty() const {
  return length == 0;
}

template <typename T> const T &LinkedList<T>::front() const {
  return head->data;
}

template <typename T> const T &LinkedList<T>::back() const {
  return tail->data;
}

template <typename T> void LinkedList<T>::clear() {
  while (length > 0) {
    pop_back();
  }
}

#endif // !LINKED_LIST_CPP
