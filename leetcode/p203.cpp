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
  ListNode* removeElements(ListNode* head, int val) {
    if (!head) return head;
    ListNode dummy(-1, head);
    ListNode* cur = &dummy;
    while (cur->next) {
      if (cur->next->val == val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }
    return dummy.next;
  }
};

int main() {
  ListNode* head = new ListNode(
      1,
      new ListNode(
          2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
  auto ptr = Solution().removeElements(head, 6);
  while (ptr) {
    cout << ptr->val << "\t";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}