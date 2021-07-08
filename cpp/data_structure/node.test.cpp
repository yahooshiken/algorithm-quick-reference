#include <cassert>
#include <iostream>

#include "node.hpp"

using namespace std;

int main() {
  Node<int> node(100);
  Node<int> node2(101);

  assert(node.getValue() == 100);
  assert(node.toString() == "Node[100]");

  node.setNext(node2);
  assert(node.getNext()->getValue() == 101);

  cout << "Test passed" << endl;

  return 0;
}
