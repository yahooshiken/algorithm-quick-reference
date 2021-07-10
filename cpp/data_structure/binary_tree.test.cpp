#include <cassert>
#include <iostream>

#include "binary_tree.hpp"

using namespace std;

int main() {
  BinaryTree<int> *binaryTree = new BinaryTree<int>();

  binaryTree->add(4);
  binaryTree->add(6);
  binaryTree->add(2);
  binaryTree->add(5);
  binaryTree->add(1);
  binaryTree->add(9);

  assert(binaryTree->getRoot()->getValue() == 4);
  assert(binaryTree->getRoot()->getLeft()->getValue() == 2);
  assert(binaryTree->getRoot()->getRight()->getValue() == 6);
  assert(binaryTree->getRoot()->getLeft()->getLeft()->getValue() == 1);
  assert(binaryTree->getRoot()->getRight()->getLeft()->getValue() == 5);
  assert(binaryTree->getRoot()->getRight()->getRight()->getValue() == 9);

  assert(binaryTree->inorder(binaryTree->getRoot()) == "1 2 4 5 6 9 ");
  assert(binaryTree->pop() == 1);
  assert(binaryTree->inorder(binaryTree->getRoot()) == "2 4 5 6 9 ");
  assert(binaryTree->pop() == 2);
  assert(binaryTree->inorder(binaryTree->getRoot()) == "4 5 6 9 ");
  assert(binaryTree->pop() == 4);
  assert(binaryTree->inorder(binaryTree->getRoot()) == "5 6 9 ");
  assert(binaryTree->pop() == 5);
  assert(binaryTree->inorder(binaryTree->getRoot()) == "6 9 ");
  assert(binaryTree->pop() == 6);
  assert(binaryTree->inorder(binaryTree->getRoot()) == "9 ");
  assert(binaryTree->pop() == 9);
  assert(binaryTree->inorder(binaryTree->getRoot()) == "");
  assert(binaryTree->pop() == 0);

  cout << "Test passed" << endl;
  return 0;
}
