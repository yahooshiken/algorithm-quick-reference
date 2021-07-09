#include <string>

using namespace std;

template <typename T> class Sort {
public:
  Sort(){};
  ~Sort(){};

  void swap(T *x, T *y);
  T *sort(T *arr, const int length);
  string toString(T *arr, const int length);
};
