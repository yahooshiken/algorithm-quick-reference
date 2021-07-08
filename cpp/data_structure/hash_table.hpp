#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <typename T> class HashTable {
private:
  const int bucket;
  list<T> *table;

  int hashFunc(T x) { return x % bucket; }

public:
  HashTable(int bucketSize) : bucket(bucketSize) {
    table = new list<T>[bucketSize];
  };
  ~HashTable(){};

  void insertItem(T key);
  void deleteItem(T key);

  string toString();
};

template <typename T> void HashTable<T>::insertItem(T key) {
  int index = hashFunc(key);
  table[index].push_back(key);
}

template <typename T> void HashTable<T>::deleteItem(T key) {
  int index = hashFunc(key);

  list<int>::iterator it;
  for (it = table[index].begin(); it != table[index].end(); it++) {
    if (*it == key) {
      break;
    }
  }

  if (it != table[index].end()) {
    table[index].erase(it);
  }
}

template <typename T> string HashTable<T>::toString() {
  stringstream ss;

  for (int i = 0; i < bucket; i++) {
    ss << i << ": ";
    for (T val : table[i]) {
      ss << "-> " << val << ' ';
    }
    ss << endl;
  }

  return ss.str();
}