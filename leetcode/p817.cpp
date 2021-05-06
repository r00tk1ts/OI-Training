#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  int numComponents(ListNode* head, vector<int>& G) {
    int ret = 0;
    bool consecutive = false;
    set<int> table(G.begin(), G.end());
    while (head) {
      if (table.find(head->val) == table.end()) {
        head = head->next;
        consecutive = false;
      } else {
        if (!consecutive) {
          ret++;
          consecutive = true;
        }
        head = head->next;
      }
    }
    return ret;
  }
};

int main() {
  ListNode* head =
      new ListNode(0, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4)))));
  vector<int> v{0, 3, 1, 4};
  cout << Solution().numComponents(head, v) << endl;
  return 0;
}