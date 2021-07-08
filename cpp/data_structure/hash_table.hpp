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
  int search();

  string toString();
};

template <typename T> void HashTable<T>::insertItem(T key) {
  int index = hashFunc(key);
  table[index].push_back(key);
}

template <typename T> void HashTable<T>::deleteItem(T key) {
  int index = hashFunc(key);

  list<int>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++) {
    if (*i == key) {
      break;
    }
  }

  if (i != table[index].end()) {
    table[index].erase(i);
  }
}

template <typename T> string HashTable<T>::toString() {
  stringstream ss;

  for (int i = 0; i < bucket; i++) {
    ss << i << ": ";
    for (auto x : table[i]) {
      ss << "-> " << x << ' ';
    }
    ss << endl;
  }

  return ss.str();
}