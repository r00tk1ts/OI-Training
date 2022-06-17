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
  ListNode* detectCycle(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) break;
    }
    if (!fast || !fast->next) return nullptr;

    ListNode* cur = head;
    while (cur != slow) {
      cur = cur->next;
      slow = slow->next;
    }
    return cur;
  }
};

int main() {
  ListNode* head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;
  auto ptr = Solution().detectCycle(head);
  cout << ptr->val << endl;
  return 0;
}