#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
 public:
  void deleteNode(ListNode* node) {
    while (node->next) {
      node->val = node->next->val;
      if (!node->next->next) {
        node->next = nullptr;
        break;
      }
      node = node->next;
    }
  }
};

int main() {
  ListNode* h = new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(9))));
  Solution().deleteNode(h->next);
  while (h) {
    cout << h->val << "\t";
    h = h->next;
  }
  cout << endl;
  return 0;
}