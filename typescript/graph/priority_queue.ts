interface IBinaryHeap<T> {
  elements: T[];

  isEmpty: () => boolean;
  insert: (element: T) => void;
  extractMin: () => T;
}

export interface INode<T> {
  value: T;
  priority: number;
}

interface IPriorityQueue<T> {
  elements: INode<T>[];

  isEmpty: () => boolean;
  enqueue: (element: INode<T>) => void;
  dequeue: () => INode<T> | undefined;
  swap: (i: number, j: number) => void;
  bubbleUp: () => void;
  bubbleDown: () => void;
  updatePriority: (element: INode<T>) => void;
}

class PriorityQueue<T> implements IPriorityQueue<T> {
  elements: INode<T>[];

  constructor() {
    this.elements = [];
  }

  isEmpty(): boolean {
    return this.elements.length === 0;
  }

  enqueue(element: INode<T>) {
    this.elements.push(element);
    this.bubbleUp();
  }

  dequeue(): INode<T> | undefined {
    this.swap(0, this.elements.length - 1);
    const element = this.elements.pop();
    this.bubbleDown();

    return element;
  }

  swap(i: number, j: number): void {
    const temp = this.elements[i];
    this.elements[i] = this.elements[j];
    this.elements[j] = temp;
  }

  updatePriority({ value, priority }: INode<T>) {
    const index = this.elements.findIndex((e) => e.value === value);
    this.elements.splice(index, 1);
    this.enqueue({ value, priority });
  }

  bubbleUp(): void {
    let index = this.elements.length - 1;

    while (index > 0) {
      const parentIndex = Math.floor((index - 1) / 2);
      const parentPriority = this.elements[parentIndex].priority;
      const childPriority = this.elements[index].priority;

      if (parentPriority > childPriority) {
        this.swap(index, parentIndex);
        index = parentIndex;
      } else {
        break;
      }
    }
  }

  bubbleDown(): void {
    let index = 0;
    const length = this.elements.length;
    if (length === 0) return;

    const priority = this.elements[index].priority;

    while (true) {
      let indexToSwap;
      const lChildIndex = 2 * index + 1;
      const rChildIndex = 2 * index + 2;

      const lChildPriority =
        lChildIndex < length ? this.elements[lChildIndex].priority : undefined;
      const rChildPriority =
        rChildIndex < length ? this.elements[rChildIndex].priority : undefined;

      if (lChildPriority && lChildPriority < priority) {
        indexToSwap = lChildIndex;
      }

      if (rChildPriority) {
        if (
          (!indexToSwap && rChildPriority < priority) ||
          (!!indexToSwap && lChildPriority && rChildPriority < lChildPriority)
        ) {
          indexToSwap = rChildIndex;
        }
      }

      if (!indexToSwap) break;

      this.swap(index, indexToSwap);
      index = indexToSwap;
    }
  }
}

export default PriorityQueue;
