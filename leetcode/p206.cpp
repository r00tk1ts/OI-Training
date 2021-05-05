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
  ListNode* reverseList(ListNode* head) {
    ListNode* new_head = nullptr;
    while (head) {
      ListNode* next = head->next;
      head->next = new_head;
      new_head = head;
      head = next;
    }
    return new_head;
  }
};

int main() {
  ListNode* head =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  auto ptr = Solution().reverseList(head);
  while (ptr) {
    cout << ptr->val << "\t";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}