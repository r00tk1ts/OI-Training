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
  int getDecimalValue(ListNode* head) {
    ListNode* new_head = reverseList(head);
    int res = 0;
    int pow = 0;
    while (new_head) {
      res += new_head->val << pow;
      pow++;
      new_head = new_head->next;
    }
    return res;
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
  ListNode* head = new ListNode(1, new ListNode(0, new ListNode(1)));
  cout << Solution().getDecimalValue(head) << endl;
  return 0;
}