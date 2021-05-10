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
  /*
  // 暴力解法
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> res;
    ListNode* cur = head;
    while (cur) {
      ListNode* step = cur->next;
      while (step) {
        if (step->val > cur->val) {
          res.push_back(step->val);
          break;
        }
        step = step->next;
      }
      if (!step) {
        res.push_back(0);
      }
      cur = cur->next;
    }
    return res;
  }
  */
  // 单调栈解法:
  // 链表先反转，变成找左边第一个比它大的数，使用单调递增栈
  // 结果再反转一次即可
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> res;
    stack<int> stk;
    head = reverseList(head);
    while (head) {
      while (!stk.empty() && stk.top() <= head->val) {
        stk.pop();
      }
      if (stk.empty())
        res.push_back(0);
      else
        res.push_back(stk.top());
      stk.push(head->val);
      head = head->next;
    }
    reverse(res.begin(), res.end());
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
  ListNode* head =
      new ListNode(2, new ListNode(7, new ListNode(4, new ListNode(3, new ListNode(5)))));
  auto res = Solution().nextLargerNodes(head);
  for (auto elem : res) {
    cout << elem << "\t";
  }
  cout << endl;
  return 0;
}