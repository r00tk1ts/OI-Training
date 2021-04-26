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
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *p1 = head, *p2 = head->next, *prev = nullptr;
    head = p2;
    while (p2) {
      p1->next = p2->next;
      p2->next = p1;
      if (prev) prev->next = p2;
      prev = p1;
      p1 = p1->next;
      p2 = p1 ? p1->next : nullptr;
    }
    return head;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  auto ptr = Solution().swapPairs(head);
  while (ptr) {
    cout << ptr->val << "\t";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}