package algorithm.data_structure;

import java.util.Iterator;

public class LinkedListIterator<E> implements Iterator<E> {
  private Node<E> current;

  public LinkedListIterator(LinkedList<E> list) {
    current = list.head();
  }

  public E next() {
    E val = current.getValue();
    current = current.getNext();
    return val;
  }

  public boolean hasNext() {
    return current != null;
  }
}
