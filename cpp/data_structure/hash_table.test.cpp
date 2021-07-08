#include <cassert>
#include <iostream>

#include "hash_table.hpp"

using namespace std;

int main() {
  const int BUCKET = 5;
  HashTable<int> *hash = new HashTable<int>(BUCKET);

  hash->insertItem(1);
  hash->insertItem(2);
  hash->insertItem(3);
  hash->insertItem(11);
  hash->insertItem(21);
  hash->insertItem(22);

  cout << hash->toString() << endl;

  hash->deleteItem(50);
  hash->deleteItem(21);
  hash->deleteItem(22);
  hash->deleteItem(3);

  cout << hash->toString() << endl;

  cout << "Test passed" << endl;
  return 0;
}
