package algorithm.data_structure;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class LinkedList<E> implements Iterable<E> {
  private Node<E> head;
  private Node<E> tail;
  private int size;

  public LinkedList() {
    head = tail = null;
    size = 0;
  }

  public boolean isEmpty() {
    return size == 0;
  }

  public int size() {
    return size;
  }

  public Node<E> head() {
    return head;
  }

  public Node<E> tail() {
    return tail;
  }

  public void append(E e) {
    if (e == null) {
      throw new IllegalArgumentException("Unable to append");
    }

    Node<E> node = new Node<E>(e);

    if (head == null) {
      head = tail = node;
    } else {
      tail.setNext(node);
      tail = tail.getNext();
    }

    size++;
  }

  public E contains(E e) {
    if (head == null) {
      return null;
    }

    Node<E> n = head;
    while (n != null) {
      if (n.getValue().equals(e)) {
        return n.getValue();
      }

      n = n.getNext();
    }

    return null;
  }

  public E remove() {
    if (head == null) {
      throw new NoSuchElementException("Nothing in List");
    }

    E result = head.getValue();

    if (head == tail) {
      head = tail = null;
    } else {
      head = head.getNext();
    }

    size--;
    return result;
  }

  public void concat(LinkedList<E> list) {
    if (list == null || list.size == 0) {
      return;
    }

    if (head == null) {
      head = list.head;
      tail = list.tail;
      size += list.size;
      return;
    }

    Node<E> newTail = list.tail;
    tail.setNext(list.head);
    tail = newTail;

    size += list.size;
  }

  public String toString() {
    if (head == null) {
      return "List[0]";
    }
    return "List[" + size + "]: " + head.getValue().toString();
  }

  public Iterator<E> iterator() {
    return new LinkedListIterator<E>(this);
  }
}
