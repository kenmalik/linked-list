#ifndef NODE_HPP

template <typename T> struct Node {
  T data;
  Node *next = nullptr;
  Node *prev = nullptr;
};

#endif // !NODE_HPP
