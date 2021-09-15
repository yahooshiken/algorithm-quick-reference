class Node<T> {
  T value;
  int priority;

  Node(this.value, this.priority);

  Node<R>? cast<R>() => value is R ? Node(value as R, priority) : null;

  @override
  bool operator ==(Object other) =>
      other is Node && other.value == value && other.priority == priority;

  @override
  String toString() => 'Node<$value, $priority>';
}

class PriorityQueue<T> {
  List<Node<T>> elements = [];

  bool isEmpty() {
    return elements.isEmpty;
  }

  void enqueue(Node<T> element) {
    elements.add(element);
    bubbleUp();
  }

  Node<T>? dequeue() {
    swap(0, elements.length - 1);
    final element = elements.removeLast();
    bubbleDown();

    return element;
  }

  void updatePriority(Node<T> node) {
    final index = elements.indexWhere((e) => e.value == node.value);
    elements.removeAt(index);
    enqueue(node);
  }

  void bubbleUp() {
    var index = elements.length - 1;

    while (index > 0) {
      final parentIndex = (index - 1) ~/ 2;
      final parentPriority = elements[parentIndex].priority;
      final childPriority = elements[index].priority;

      if (parentPriority > childPriority) {
        swap(index, parentIndex);
        index = parentIndex;
      } else {
        break;
      }
    }
  }

  void bubbleDown() {
    if (elements.isEmpty) {
      return;
    }

    var index = 0;
    final length = elements.length;
    final priority = elements[index].priority;

    while (true) {
      var indexToSwap;
      final lIndex = 2 * index + 1;
      final rIndex = 2 * index + 2;
      final lPriority = lIndex < length ? elements[lIndex].priority : null;
      final rPriority = rIndex < length ? elements[rIndex].priority : null;

      if (lPriority != null && lPriority < priority) {
        indexToSwap = lIndex;
      }

      if (rPriority != null) {
        if ((indexToSwap == null && rPriority < priority) ||
            (indexToSwap != null &&
                lPriority != null &&
                rPriority < lPriority)) {
          indexToSwap = rIndex;
        }
      }

      if (indexToSwap == null) break;

      swap(index, indexToSwap);
      index = indexToSwap;
    }
  }

  void swap(int i, int j) {
    final tmp = elements[i];
    elements[i] = elements[j];
    elements[j] = tmp;
  }
}
