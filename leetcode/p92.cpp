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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head) return head;
    ListNode dummy(0, head);
    int step = 0;
    ListNode *tail = &dummy, *last = &dummy;
    while (step < right) {
      if (step + 1 < left) tail = tail->next;
      last = last->next;
      step++;
    }
    last = last->next;
    tail->next = reverse(tail->next, last);
    return dummy.next;
  }

  ListNode* reverse(ListNode* first, ListNode* last) {
    ListNode* new_head = last;
    while (first != last) {
      ListNode* next = first->next;
      first->next = new_head;
      new_head = first;
      first = next;
    }
    return new_head;
  }
};

int main() {
  ListNode* head =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  auto h = Solution().reverseBetween(head, 2, 4);
  while (h) {
    cout << h->val << "\t";
    h = h->next;
  }
  cout << endl;

  ListNode* head2 = new ListNode(3, new ListNode(5));
  h = Solution().reverseBetween(head2, 1, 2);
  while (h) {
    cout << h->val << "\t";
    h = h->next;
  }
  cout << endl;
  return 0;
}