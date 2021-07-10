package algorithm.data_structure;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.Test;

public class LinkedListTest {
  @Test
  void test_linked_list() {

    LinkedList<Integer> list = new LinkedList<Integer>();
    assertTrue(list.isEmpty());

    list.append(3);
    list.append(5);
    list.append(1);

    assertEquals(3, list.size());
    assertEquals(3, list.head().getValue());
    assertEquals(5, list.head().getNext().getValue());
    assertEquals(1, list.tail().getValue());

    assertEquals(3, list.remove());
    assertEquals(5, list.head().getValue());
    assertEquals(1, list.tail().getValue());
    assertEquals(2, list.size());
  }
}
