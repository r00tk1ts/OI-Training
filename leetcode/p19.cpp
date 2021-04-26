#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *p1 = &dummy, *p2 = &dummy;
    while (n) {
      p1 = p1->next;
      n--;
    }
    while (p1->next) {
      p1 = p1->next;
      p2 = p2->next;
    }
    ListNode* tmp = p2->next;
    p2->next = p2->next->next;
    delete tmp;
    return dummy.next;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  auto h = Solution().removeNthFromEnd(head, 2);
  while (h) {
    cout << h->val << "\t";
    h = h->next;
  }
  cout << endl;
  return 0;
}