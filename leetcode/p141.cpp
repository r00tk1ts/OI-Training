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
  bool hasCycle(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) return true;
    }
    return false;
  }
};

int main() {
  ListNode* head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;
  cout << boolalpha << Solution().hasCycle(head) << endl;
  return 0;
}