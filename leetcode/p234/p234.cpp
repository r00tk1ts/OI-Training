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
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // even
    if (!fast) {
      auto h2 = reverseList(slow);
      auto h1 = head;
      while (h2) {
        if (h1->val != h2->val) return false;
        h1 = h1->next;
        h2 = h2->next;
      }
      return true;
    } else {
      auto h2 = reverseList(slow->next);
      auto h1 = head;
      while (h2) {
        if (h1->val != h2->val) return false;
        h1 = h1->next;
        h2 = h2->next;
      }
      return true;
    }
  }

 private:
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
  ListNode* h1 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
  cout << boolalpha << Solution().isPalindrome(h1) << endl;
  ListNode* h2 =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1)))));
  cout << boolalpha << Solution().isPalindrome(h2) << endl;
  return 0;
}