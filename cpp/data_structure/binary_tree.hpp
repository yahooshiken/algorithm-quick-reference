#include <sstream>

#include "binary_tree_node.hpp"

using namespace std;

template <typename T> class BinaryTree {
private:
  BinaryTreeNode<T> *root;
  int size;

  BinaryTreeNode<T> *removeRecursively(BinaryTreeNode<T> *node, T val);

public:
  BinaryTree() : root(NULL), size(0){};
  ~BinaryTree();
  BinaryTreeNode<T> *getRoot() { return root; };
  T findMinValue(BinaryTreeNode<T> *node);
  void add(T val);
  bool contains(T target);
  BinaryTreeNode<T> *remove(T val);
  string inorder(BinaryTreeNode<T> *node);
  T pop();
};

template <typename T> void BinaryTree<T>::add(T val) {
  if (!root) {
    root = new BinaryTreeNode<T>(val);
  } else {
    root->add(val);
  }

  size++;
}

template <typename T> bool BinaryTree<T>::contains(T target) {
  BinaryTreeNode<T> *node = root;

  while (node) {
    if (target < node->value) {
      node = node->left;
    } else if (target > node->value) {
      node = node->right;
    } else {
      return true;
    }
  }

  return false;
}

template <typename T> BinaryTreeNode<T> *BinaryTree<T>::remove(T val) {
  root = removeRecursively(root, val);
  return root;
}

template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::removeRecursively(BinaryTreeNode<T> *node,
                                                    T val) {
  if (node == NULL) {
    return node;
  }

  if (val < node->getValue()) {
    node->setLeft(removeRecursively(node->getLeft(), val));
  } else if (val > node->getValue()) {
    node->setRight(removeRecursively(node->getRight(), val));
  } else {
    if (node->getLeft() == NULL) {
      return node->getRight();
    } else if (node->getRight() == NULL) {
      return node->getLeft();
    }

    node->setValue(findMinValue(node->getRight()));
    node->setRight(removeRecursively(node->getRight(), node->getValue()));
  }

  return node;
}

template <typename T> T BinaryTree<T>::findMinValue(BinaryTreeNode<T> *node) {
  while (node->getLeft() != NULL) {
    node = node->getLeft();
  }

  return node->getValue();
}

template <typename T> T BinaryTree<T>::pop() {
  if (root == NULL) {
    return NULL;
  }

  T minValue = findMinValue(root);
  remove(minValue);
  return minValue;
}

template <typename T> string BinaryTree<T>::inorder(BinaryTreeNode<T> *node) {
  string str;

  if (node == NULL) {
    return "";
  }

  str += inorder(node->getLeft());
  str += to_string(node->getValue()) + " ";
  str += inorder(node->getRight());
  return str;
}
