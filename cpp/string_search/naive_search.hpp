#include <string>

using namespace std;

class NaiveSearch {
private:
public:
  NaiveSearch(){};
  ~NaiveSearch(){};

  int search(string text, string pattern);
};

int NaiveSearch::search(string text, string pattern) {
  const int N = text.length();
  const int M = pattern.length();

  int i = 0, j = 0;
  while (i < N && j < M) {
    if (text.c_str()[i] == pattern.c_str()[j]) {
      i++;
      j++;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }

  return j == M ? i - j : -1;
}