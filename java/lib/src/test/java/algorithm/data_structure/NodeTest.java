package algorithm.data_structure;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNull;

import org.junit.jupiter.api.Test;

public class NodeTest {
  @Test
  void test_node() {
    Node<String> node = new Node<String>("test");
    Node<String> nextNode = new Node<String>("next");

    assertEquals("test", node.getValue());
    assertEquals("next", nextNode.getValue());
    assertNull(node.getNext());

    node.setNext(nextNode);
    assertEquals(nextNode, node.getNext());

    assertEquals("Node[test]", node.toString());
  }
}
