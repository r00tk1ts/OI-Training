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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *prev = head, *cur = head->next;
    while (cur) {
      if (prev->val == cur->val) {
        cur = cur->next;
        prev->next = cur;
      } else {
        cur = cur->next;
        prev = prev->next;
      }
    }
    return head;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  auto p = Solution().deleteDuplicates(head);
  while (p) {
    cout << p->val << "\t";
    p = p->next;
  }
  cout << endl;
  return 0;
}