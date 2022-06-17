#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int main() {
  deque<int> queue;
  int words, size, sum = 0;
  cin >> size >> words;
  for (int i = 0; i < words; ++i) {
    int word;
    cin >> word;
    if (find(queue.begin(), queue.end(), word) == end(queue)) {
      ++sum;
      if (queue.size() == size) {
        queue.pop_front();
        queue.push_back(word);
      } else {
        queue.push_back(word);
      }
    }
  }
  cout << sum << endl;
  return 0;
}
