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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy, *p = &dummy;
    int add = 0;
    while (l1 && l2) {
      p->next = new ListNode((l1->val + l2->val + add) % 10);
      add = (l1->val + l2->val + add) / 10;
      p = p->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    if (l1) {
      while (l1) {
        p->next = new ListNode((l1->val + add) % 10);
        add = (l1->val + add) / 10;
        l1 = l1->next;
        p = p->next;
      }
    } else if (l2) {
      while (l2) {
        p->next = new ListNode((l2->val + add) % 10);
        add = (l2->val + add) / 10;
        l2 = l2->next;
        p = p->next;
      }
    }
    if (add) {
      p->next = new ListNode(add);
    }
    return dummy.next;
  }
};

int main() {
  ListNode *l1, *l2;
  l1 = new ListNode(9);
  l1->next = new ListNode(9);
  l1->next->next = new ListNode(9);
  l1->next->next->next = new ListNode(9);
  l1->next->next->next->next = new ListNode(9);
  l1->next->next->next->next->next = new ListNode(9);
  l1->next->next->next->next->next->next = new ListNode(9);

  l2 = new ListNode(9);
  l2->next = new ListNode(9);
  l2->next->next = new ListNode(9);
  l2->next->next->next = new ListNode(9);

  Solution s;
  auto head = s.addTwoNumbers(l1, l2);
  while (head) {
    cout << head->val << "\t";
    head = head->next;
  }
  cout << endl;
  return 0;
}