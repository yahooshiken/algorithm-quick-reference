#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

#ifdef REPORT
#define INC_SMALL _numSmallest++
#define INC_COMP _numComparisons++
#define INC_SWAP _numSwaps++
#define INC_INSERT _numInsert++
#define INC_DECREASE _numDecrease++
#else
#define INC_SMALL
#define INC_COMP
#define INC_SWAP
#define INC_INSERT
#define INC_DECREASE
#endif /* REPORT */

typedef struct elt {
  int id;
  int priority;
} ELEMENT, *ELEMENT_PTR;

class BinaryHeap {
public:
  BinaryHeap(int);
  ~BinaryHeap();

  bool isEmpty() { return _n == 0; }
  int smallest();
  void insert(int, int);
  void decreaseKey(int, int);

private:
  int _n;
  ELEMENT_PTR _elements;
  int *_pos;
  long _numComparisons;
  long _numInsert;
  long _numSwaps;
  long _numSmallest;
  long _numDecrease;
};

#endif /* _BINARY_HEAP_H_ */
