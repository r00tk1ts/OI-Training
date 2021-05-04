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

/*
// 暴力解法，时间爆炸
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
*/
class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    ListNode *slow, *fast, *prev = nullptr;
    slow = fast = head;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;
    ListNode dummy(0), *cur = &dummy;
    ListNode* back = reverse(slow);
    while (head && back) {
      cur->next = head;
      head = head->next;
      cur = cur->next;
      cur->next = back;
      back = back->next;
      cur = cur->next;
    }
    if (head) cur->next = head;
    if (back) cur->next = back;
  }

  ListNode* reverse(ListNode* head) {
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
  Solution().reorderList(head);
  auto ptr = head;
  while (ptr) {
    cout << ptr->val << "\t";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}