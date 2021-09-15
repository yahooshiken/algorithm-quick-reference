import 'dart:core';
import 'package:test/test.dart';

import 'package:algorithm/collections/priority_queue.dart';

void main() {
  test('Priority Queue', () {
    final pq = PriorityQueue();
    expect(pq.isEmpty(), true);

    pq.enqueue(Node(0, 10));
    pq.enqueue(Node(1, 5));
    expect(pq.isEmpty(), false);

    expect(pq.dequeue()?.value, 1);
    expect(pq.dequeue()?.value, 0);
    expect(pq.isEmpty(), true);

    pq.enqueue(Node(2, 9));
    pq.enqueue(Node(3, 2));
    pq.enqueue(Node(4, 15));
    pq.enqueue(Node(5, 11));
    pq.enqueue(Node(6, 1));

    expect(pq.dequeue()?.cast<int>(), equals(Node(6, 1)));
    expect(pq.dequeue()?.cast<int>(), equals(Node(3, 2)));
    pq.updatePriority(Node(4, 3));
    expect(pq.dequeue()?.cast<int>(), equals(Node(4, 3)));
    expect(pq.dequeue()?.cast<int>(), equals(Node(2, 9)));
    expect(pq.dequeue()?.cast<int>(), equals(Node(5, 11)));
  });
}
