interface IQueue<T> {
  elements: T[];
  length: () => number;
  isEmpty: () => boolean;
  enqueue: (element: T) => void;
  dequeue: () => T | undefined;
  peek: () => T | undefined;
}

class Queue<T> implements IQueue<T> {
  elements: T[];

  constructor() {
    this.elements = [];
  }

  length(): number {
    return this.elements.length;
  }

  isEmpty(): boolean {
    return this.elements.length === 0;
  }

  enqueue(element: T): void {
    this.elements.push(element);
  }

  dequeue(): T | undefined {
    return this.elements.shift();
  }

  peek(): T | undefined {
    return !this.isEmpty() ? this.elements[0] : undefined;
  }
}

export default Queue;
