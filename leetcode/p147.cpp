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
  ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode dummy(-5001, head);
    ListNode* cur = head->next;
    head->next = nullptr;

    while (cur) {
      ListNode *compare = dummy.next, *prev = &dummy;
      while (compare && cur->val >= compare->val) {
        prev = compare;
        compare = compare->next;
      }
      prev->next = cur;
      cur = cur->next;
      prev->next->next = compare;
    }
    return dummy.next;
  }
};

int main() {
  ListNode* head =
      new ListNode(3, new ListNode(5, new ListNode(6, new ListNode(1, new ListNode(8)))));
  auto ptr = Solution().insertionSortList(head);
  while (ptr) {
    cout << ptr->val << "\t";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}