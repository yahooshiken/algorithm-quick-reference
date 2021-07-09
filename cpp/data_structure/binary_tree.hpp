#include "binary_tree_node.hpp"

using namespace std;

template <typename T> class BinaryTree {
private:
  BinaryTreeNode<T> *root;
  int size;

public:
  BinaryTree() : root(NULL), size(0){};
  ~BinaryTree();
  BinaryTreeNode<T> *getRoot() { return root; };
  void add(T val);
  bool contains(T target);
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
