package algorithm.data_structure;

public class Node<E> {
  private final E value;
  private Node<E> next;

  public Node(E e) {
    this.value = e;
  }

  public E getValue() {
    return value;
  }

  public Node<E> getNext() {
    return next;
  }

  public void setNext(Node<E> next) {
    this.next = next;
  }

  public String toString() {
    return "Node[" + value + "]";
  }
}
