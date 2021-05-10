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
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* cur = &dummy;
    map<int, ListNode*> mp;
    int sum = 0;
    while (cur) {
      sum += cur->val;
      if (mp.find(sum) != mp.end()) {
        cur = mp[sum]->next;
        int p = sum + cur->val;
        while (p != sum) {
          mp.erase(p);
          cur = cur->next;
          p += cur->val;
        }
        mp[sum]->next = cur->next;
      } else {
        mp[sum] = cur;
      }
      cur = cur->next;
    }
    return dummy.next;
  }
};

int main() {
  ListNode* head =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(-3, new ListNode(-2)))));
  auto ptr = Solution().removeZeroSumSublists(head);
  while (ptr) {
    cout << ptr->val << "\t";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}