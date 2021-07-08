#include <cstddef>
#include <string>

using namespace std;

template <typename T> class Node {
private:
  T value;
  Node<T> *next;

public:
  Node(T val) : value(val) { next = NULL; };
  ~Node() { next = NULL; };
  T getValue() const { return value; };
  Node<T> *getNext() { return next; };
  void setNext(Node<T> node) { next = &node; };
  string toString() const { return "Node[" + to_string(value) + "]"; }
};
