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
  ListNode* partition(ListNode* head, int x) {
    // dummy->1->4->3->2->5->2
    ListNode d1(-1), d2(-1);
    ListNode *l1 = &d1, *l2 = &d2;
    while (head) {
      if (head->val < x) {
        l1->next = head;
        l1 = head;
      } else {
        l2->next = head;
        l2 = head;
      }
      head = head->next;
    }
    l1->next = d2.next;
    l2->next = nullptr;
    return d1.next;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(4);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(2);
  auto p = Solution().partition(head, 3);
  while (p) {
    cout << p->val << "\t";
    p = p->next;
  }
  cout << endl;
  return 0;
}