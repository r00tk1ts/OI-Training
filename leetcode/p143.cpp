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
  void reorderList(ListNode* head) {
    head->next = helper(head->next);
  }
  ListNode* helper(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *tail = head, *prev = head;
    while (tail->next) {
      tail = tail->next;
      if (tail->next) prev = tail;
    }
    prev->next = nullptr;
    tail->next = head;
    head->next = helper(head->next);
    return tail;
  }
};

int main() {
  ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  Solution().reorderList(head);
  auto ptr = head;
  while (ptr) {
    cout << ptr->val << "\t";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}