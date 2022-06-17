#include <chrono>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int n = s.size();
    int k = words.size();
    int word_len = words[0].size();

    map<string, int> word_count;
    for (auto& word : words) {
      word_count[word] += 1;
    }

    vector<int> ret;
    for (int i = 0; i < n - k * word_len + 1; ++i) {
      if (match(s, i, k, word_len, word_count)) {
        ret.push_back(i);
      }
    }
    return ret;
  }

  bool match(const string& s, int pos, int k, int word_len, map<string, int> word_count) {
    int count = 0;
    for (int i = pos; i < pos + k * word_len; i += word_len) {
      auto iter = word_count.find(s.substr(i, word_len));
      if (iter != word_count.end() && iter->second != 0) {
        iter->second--;
        count++;
      } else {
        break;
      }
    }
    return count == k;
  }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  string s, t;
  vector<string> words;
  cin >> s >> t;
  size_t pos = 0;
  while ((pos = t.find(";")) != std::string::npos) {
    words.emplace_back(t.substr(0, pos));
    t.erase(0, pos + 1);
  }
  words.emplace_back(t);

  Solution sol;
  auto ret = sol.findSubstring(s, words);
  for (auto item : ret) {
    cout << item << ",";
  }

#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}