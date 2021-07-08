#include <cassert>
#include <iostream>

#include "linked_list.hpp"

using namespace std;

int main() {
  LinkedList<int> list;
  list.push(3);
  list.push(5);
  list.push(1);

  assert(list.getSize() == 3);
  assert(list.getHead()->getValue() == 3);
  assert(list.getHead()->getNext()->getValue() == 5);
  assert(list.getTail()->getValue() == 1);

  assert(list.pop() == 3);
  assert(list.getHead()->getValue() == 5);
  assert(list.getTail()->getValue() == 1);
  assert(list.getSize() == 2);

  cout << "Test passed" << endl;

  return 0;
}
