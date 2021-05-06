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
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int size = getSize(root);
    int part_size = size / k;
    int high_num = size % k;
    int low_num = k - high_num;
    vector<ListNode*> ret;
    for (int i = 0; i < high_num; ++i) {
      ListNode dummy, *cur = &dummy;
      int size = 0;
      while (size < part_size + 1) {
        cur->next = root;
        cur = cur->next;
        size++;
        if (size == part_size + 1) {
          ListNode* tmp = root->next;
          root->next = nullptr;
          root = tmp;
        } else {
          root = root->next;
        }
      }
      ret.push_back(dummy.next);
    }
    if (part_size == 0) {
      for (int i = 0; i < low_num; ++i) ret.push_back(nullptr);
      return ret;
    }
    for (int i = 0; i < low_num; ++i) {
      ListNode dummy, *cur = &dummy;
      int size = 0;
      while (size < part_size) {
        cur->next = root;
        cur = cur->next;
        size++;
        if (size == part_size) {
          ListNode* tmp = root->next;
          root->next = nullptr;
          root = tmp;
        } else {
          root = root->next;
        }
      }
      ret.push_back(dummy.next);
    }
    return ret;
  }

  int getSize(ListNode* head) {
    int size = 0;
    while (head) {
      size++;
      head = head->next;
    }
    return size;
  }
};

int main() {
  ListNode head(
      1,
      new ListNode(
          2,
          new ListNode(
              3,
              new ListNode(
                  4,
                  new ListNode(
                      5,
                      new ListNode(
                          6,
                          new ListNode(7, new ListNode(8, new ListNode(9, new ListNode(10))))))))));
  auto ret = Solution().splitListToParts(&head, 3);
  for (auto ptr : ret) {
    while (ptr) {
      cout << ptr->val << "\t";
      ptr = ptr->next;
    }
    cout << endl;
  }
  return 0;
}