#include <cstddef>

using namespace std;

template <typename T> class BinaryTreeNode {
private:
  T value;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;

public:
  BinaryTreeNode(T val) : value(val), left(NULL), right(NULL){};
  ~BinaryTreeNode();

  BinaryTreeNode<T> *getLeft() { return left; };
  BinaryTreeNode<T> *getRight() { return right; };
  void setLeft(BinaryTreeNode<T> *n) { left = n; };
  void setRight(BinaryTreeNode<T> *n) { right = n; };
  T getValue() { return value; };
  void setValue(T val) { value = val; };

  void add(T val);
  void inorder();
};

template <typename T> void BinaryTreeNode<T>::add(T val) {
  if (val <= value) {
    if (left) {
      left->add(val);
    } else {
      left = new BinaryTreeNode(val);
    }
  } else {
    if (right) {
      right->add(val);
    } else {
      right = new BinaryTreeNode(val);
    }
  }
}
