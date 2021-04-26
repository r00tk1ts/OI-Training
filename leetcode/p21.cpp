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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy, *p = &dummy;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }
    if (l1) {
      p->next = l1;
    } else if (l2) {
      p->next = l2;
    }
    return dummy.next;
  }
};

int main() {
  ListNode* l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

  ListNode* l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  auto head = Solution().mergeTwoLists(l1, l2);
  while (head) {
    cout << head->val << "\t";
    head = head->next;
  }
  cout << endl;
  return 0;
}