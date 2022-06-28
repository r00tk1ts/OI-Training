#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
      if(s.size() != t.size()) return false;

      map<char, char> mp;
      set<char> uni;
      for(int i=0; i<s.size(); ++i) {
        if (mp.find(s[i]) == mp.end()) {
          if (uni.find(t[i]) != uni.end()) return false;
          uni.insert(t[i]);
          mp[s[i]] = t[i];
        } else if (mp.find(s[i])->second != t[i]) {
          return false;
        }
      }
      return true;
    }
};

class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        for(size_t index = 0;index<s.size();++index){
            auto iter = m.find(s[index]);
            if(iter != m.end()){
                if(iter->second != t[index])
                    return false;
            }else{
                m[s[index]] = t[index];
            }
        }
        
        m.clear();
        for(size_t index=0; index<s.size();++index){
            auto iter = m.find(t[index]);
            if(iter != m.end()){
                if(iter->second != s[index])
                    return false;
            }else{
                m[t[index]] = s[index];
            }
        }
        return true;
    }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  string s, t;
  cin >> s >> t;
  cout << boolalpha << Solution{}.isIsomorphic(s, t);
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}