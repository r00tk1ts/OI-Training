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
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode dummy(0, list1);
    ListNode* pos = &dummy;
    b -= a - 2;
    while (a--) {
      pos = pos->next;
    }
    ListNode* pre = pos;
    while (b--) {
      pos = pos->next;
    }
    ListNode* suc = pos;
    pre->next = list2;
    while (list2->next) {
      list2 = list2->next;
    }
    list2->next = suc;
    return dummy.next;
  }
};

int main() {
  ListNode* list1 = new ListNode(
      0, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))));
  ListNode* list2 = new ListNode(1000000, new ListNode(1000001, new ListNode(1000002)));
  auto ptr = Solution().mergeInBetween(list1, 3, 4, list2);
  while (ptr) {
    cout << ptr->val << "\t";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}