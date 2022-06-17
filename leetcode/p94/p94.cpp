#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

#include "TreeNode.h"

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    return vector<int>{};
  }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif

  string tree;
  cin >> tree;
  vector<int> vtree;
  size_t pos = 0;
  while ((pos = tree.find(",")) != std::string::npos) {
    auto tmp = tree.substr(0, pos);
    if (tmp == "null") {
      vtree.emplace_back(-101);
    } else {
      vtree.emplace_back(atoi(tmp.c_str()));
    }
    tree.erase(0, pos + 1);
  }
  vtree.emplace_back(atoi(tree.c_str()));

  TreeNode* root = TreeHelper::BuildTree(vtree);
  TreeHelper::PrintTreeHorizontal(root);
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}