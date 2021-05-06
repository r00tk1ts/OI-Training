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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(-1);
    ListNode* cur = &dummy;
    auto h1 = reverseList(l1);
    auto h2 = reverseList(l2);
    int addition = 0;
    while (h1 && h2) {
      int val = (h1->val + h2->val + addition) % 10;
      cur->next = new ListNode(val);
      cur = cur->next;
      addition = (h1->val + h2->val + addition) >= 10 ? 1 : 0;
      h1 = h1->next;
      h2 = h2->next;
    }
    while (h1) {
      int val = (h1->val + addition) % 10;
      cur->next = new ListNode(val);
      cur = cur->next;
      addition = (h1->val + addition) >= 10 ? 1 : 0;
      h1 = h1->next;
    }
    while (h2) {
      int val = (h2->val + addition) % 10;
      cur->next = new ListNode(val);
      cur = cur->next;
      addition = (h2->val + addition) >= 10 ? 1 : 0;
      h2 = h2->next;
    }
    if (addition) {
      cur->next = new ListNode(addition);
    }
    return reverseList(dummy.next);
  }

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
  ListNode* l1 = new ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3))));
  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  auto ptr = Solution().addTwoNumbers(l1, l2);
  while (ptr) {
    cout << ptr->val << "\t";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}