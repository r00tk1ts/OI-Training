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
  ListNode* swapNodes(ListNode* head, int k) {
    if (!head || !head->next) return head;
    ListNode dummy(0, head);
    auto* first = &dummy;
    int step = 0;
    while (step < k) {
      first = first->next;
      step++;
      if (!first) return head;
    }

    auto* fast = &dummy;
    auto* slow = &dummy;
    while (k--) {
      fast = fast->next;
    }
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    if (first != slow) {
      first->val = slow->val ^ first->val;
      slow->val = slow->val ^ first->val;
      first->val = slow->val ^ first->val;
    }
    return head;
  }
};

int main() {
  return 0;
}