#ifndef _NODE_HPP_
#define _NODE_HPP_

#include <cstddef>
#include <string>

using namespace std;

template <typename T> class Node {
private:
  T value;
  Node<T> *next;

public:
  Node(T val) : value(val) { next = NULL; };
  ~Node(){};
  T getValue() const { return value; };
  Node<T> *getNext() { return next; };
  void setNext(Node<T> *node) { next = node; };
  string toString() const { return "Node[" + to_string(value) + "]"; }
};

#endif
