#include <cassert>
#include <iostream>

#include "naive_search.hpp"

using namespace std;

int main() {

  NaiveSearch naiveSearch = NaiveSearch();

  string text = "ABAACAADAABAAABAA";
  string pattern = "AABA";

  int index = naiveSearch.search(text, pattern);
  if (index == -1) {
    cout << "Pattern(" << pattern << ") was not found in text(" << text << ")"
         << endl;
  } else {
    string space(index, ' ');
    assert(index == 8);

    cout << text << endl;
    cout << space << pattern << endl;
  }

  return 0;
}
