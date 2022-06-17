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
  // 合并完的新list和下一个继续合并，简单粗暴，但是要合并n次，太蠢了，不卡时间能过
  /*
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    ListNode* head = lists[0];
    for (int i = 1; i < lists.size(); ++i) {
      head = mergeTwoLists(head, lists[i]);
    }
    return head;
  }
  */
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy, *p = &dummy;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }
    if (l1) {
      p->next = l1;
    } else if (l2) {
      p->next = l2;
    }
    return dummy.next;
  }

  // 分治：divide and conquer，合并lgn次
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    return helper(0, lists.size() - 1, lists);
  }

  ListNode* helper(int left, int right, vector<ListNode*>& lists) {
    if (left == right) return lists[left];
    if (left + 1 == right) {
      return mergeTwoLists(lists[left], lists[right]);
    }
    int mid = left + (right - left) / 2;
    auto h1 = helper(left, mid, lists);
    auto h2 = helper(mid + 1, right, lists);
    return mergeTwoLists(h1, h2);
  }
};

int main() {
  vector<ListNode*> lists;
  ListNode* p1 = new ListNode(1);
  p1->next = new ListNode(4);
  p1->next->next = new ListNode(5);

  ListNode* p2 = new ListNode(1);
  p2->next = new ListNode(3);
  p2->next->next = new ListNode(4);

  ListNode* p3 = new ListNode(2);
  p3->next = new ListNode(6);

  lists.push_back(p1);
  lists.push_back(p2);
  lists.push_back(p3);

  auto head = Solution().mergeKLists(lists);
  while (head) {
    cout << head->val << "\t";
    head = head->next;
  }
  cout << endl;
  return 0;
}