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
  ListNode* rotateRight(ListNode* head, int k) {
    int len = length(head);
    if (len == 0 || len == 1) return head;
    k %= len;
    if (k == 0) return head;
    ListNode dummy(0, head);
    ListNode *fast = &dummy, *slow = &dummy;
    while (k--) {
      fast = fast->next;
    }
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode* new_head = slow->next;
    slow->next = nullptr;
    fast->next = head;
    return new_head;
  }
  int length(ListNode* head) {
    int len = 0;
    while (head) {
      len++;
      head = head->next;
    }
    return len;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  auto p = Solution().rotateRight(head, 1);
  while (p) {
    cout << p->val << "\t";
    p = p->next;
  }
  cout << endl;
  return 0;
}
