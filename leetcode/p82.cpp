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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    ListNode* cur = head;
    int dup = 0;
    while (cur && cur->next) {
      ListNode* next = cur->next;
      if (cur->val != next->val) {
        if (dup) {
          prev->next = next;
          dup = 0;
        } else {
          prev = prev->next;
        }
      } else {
        dup++;
      }
      cur = next;
    }

    if (dup) {
      prev->next = nullptr;
    }
    return dummy.next;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(3);
  auto p = Solution().deleteDuplicates(head);
  while (p) {
    cout << p->val << "\t";
    p = p->next;
  }
  cout << endl;
  return 0;
}