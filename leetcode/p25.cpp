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
  ListNode* reverseKGroup(ListNode* head, int k) {
    auto tail = head;
    for (int i = 0; i < k; ++i) {
      if (!tail) return head;
      tail = tail->next;
    }

    auto new_head = reverse(head, tail);
    head->next = reverseKGroup(tail, k);
    return new_head;
  }

  ListNode* reverse(ListNode* first, ListNode* last) {
    ListNode* prev = last;
    while (first != last) {
      auto tmp = first->next;
      first->next = prev;
      prev = first;
      first = tmp;
    }
    return prev;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  auto p = Solution().reverseKGroup(head, 2);
  while (p) {
    cout << p->val << "\t";
    p = p->next;
  }
  cout << endl;
  return 0;
}