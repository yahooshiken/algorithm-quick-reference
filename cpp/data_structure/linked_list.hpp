#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include <iostream>

#include "node.hpp"

using namespace std;

template <typename T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  LinkedList() : head(NULL), tail(NULL), size(0){};
  ~LinkedList(){};

  bool isEmpty() { return size == 0; }
  Node<T> *getHead() { return head; }
  void setHead(Node<T> *node) { head = node; }
  Node<T> *getTail() { return tail; }
  void setTail(Node<T> *node) { tail = node; }
  int getSize() { return size; }
  void incrementSize() { size++; }
  void decrementSize() { size--; }

  void push(T val);
  T pop();
};

template <typename T> void LinkedList<T>::push(T val) {
  if (val == NULL) {
    throw "Illegal Argument Exception: Unable to append";
  }

  Node<T> *node = new Node<T>(val);

  if (getHead() == NULL) {
    setHead(node);
    setTail(node);
  } else {
    tail->setNext(node);
    setTail(tail->getNext());
  }
  incrementSize();
}

template <typename T> T LinkedList<T>::pop() {
  if (tail == NULL) {
    throw "No Such Element Exception: Nothing in List";
  }

  T value = head->getValue();

  if (head == tail) {
    setHead(NULL);
    setTail(NULL);
  } else {
    setHead(head->getNext());
  }

  decrementSize();
  return value;
}

#endif