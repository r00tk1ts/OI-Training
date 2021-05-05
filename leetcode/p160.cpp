#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *p1 = headA, *p2 = headB;
    bool b1 = false, b2 = false;
    while (p1 != p2) {
      p1 = p1->next;
      p2 = p2->next;
      if (!b1 && !p1) {
        b1 = true;
        p1 = headB;
      }
      if (!b2 && !p2) {
        b2 = true;
        p2 = headA;
      }
    }
    return p1;
  }
};

int main() {
  ListNode* h1 =
      new ListNode(4, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5)))));
  ListNode* h2 = new ListNode(5, new ListNode(6, h1->next));
  auto ptr = Solution().getIntersectionNode(h1, h2);
  cout << ptr->val << endl;
  return 0;
}