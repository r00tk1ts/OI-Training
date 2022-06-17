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
  ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *odd = head, *even = head->next, *even_h = head->next;
    ListNode* cur = head->next->next;
    while (cur) {
      odd->next = cur;
      even->next = cur->next;
      odd = odd->next;
      even = even->next;
      if (!cur->next) break;
      cur = cur->next->next;
    }
    odd->next = even_h;
    return head;
  }
};

int main() {
  ListNode* h = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  auto ptr = Solution().oddEvenList(h);
  while (ptr) {
    cout << ptr->val << "\t";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}