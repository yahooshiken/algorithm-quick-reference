#include <chrono>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "sort.hpp"

using namespace std;

template <typename T> class PerfMeasurer {
private:
  const Sort<T> *sorter;

public:
  PerfMeasurer(const Sort<T> &sort) { sorter = &sort; };
  ~PerfMeasurer(){};
  string reportPerf();
};

template <typename T> string PerfMeasurer<T>::reportPerf() {
  stringstream ss;
  int sizes[] = {100, 200, 500, 1000, 2000, 5000, 10000, 20000};

  for (int size : sizes) {
    vector<T> v(size);

    const int seed = 0;
    iota(v.begin(), v.end(), 0);
    shuffle(v.begin(), v.end(), default_random_engine(seed));

    chrono::time_point<chrono::high_resolution_clock> start =
        chrono::high_resolution_clock::now();

    int arr[size];
    for (int i = 0; i < size; i++) {
      arr[i] = v[i];
    }
    sorter->sort(arr, size);

    chrono::time_point<chrono::high_resolution_clock> end =
        chrono::high_resolution_clock::now();

    chrono::duration<double> diff = end - start;

    ss << "Time to sort an array of size " << size << " is " << diff.count()
       << " sec" << endl;
  }
  return ss.str();
};
