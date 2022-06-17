#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int v) : val(v) {}
  ListNode(int v, ListNode* n) : val(v), next(n) {}
};

class MyLinkedList {
 public:
  /** Initialize your data structure here. */
  MyLinkedList() {
    dummy = new ListNode();
  }

  ~MyLinkedList() {
    ListNode* pos = dummy;
    while (pos) {
      ListNode* next = pos->next;
      delete pos;
      pos = next;
    }
  }
  /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
  int get(int index) {
    index++;
    ListNode* pos = dummy;
    while (index-- && pos) {
      pos = pos->next;
    }
    if (!pos)
      return -1;
    else
      return pos->val;
  }

  /** Add a node of value val before the first element of the linked list. After the insertion, the
   * new node will be the first node of the linked list. */
  void addAtHead(int val) {
    ListNode* node = new ListNode(val, dummy->next);
    dummy->next = node;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    ListNode* last = dummy;
    while (last->next) {
      last = last->next;
    }
    last->next = new ListNode(val);
  }

  /** Add a node of value val before the index-th node in the linked list. If index equals to the
   * length of linked list, the node will be appended to the end of linked list. If index is greater
   * than the length, the node will not be inserted. */
  void addAtIndex(int index, int val) {
    ListNode* pos = dummy;
    while (index-- && pos) {
      pos = pos->next;
    }
    if (!pos) return;
    pos->next = new ListNode(val, pos->next);
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    index++;
    ListNode *pos = dummy, *prev = nullptr;
    while (index-- && pos) {
      prev = pos;
      pos = pos->next;
    }
    if (!pos) return;
    prev->next = pos->next;
    delete pos;
  }

 private:
  ListNode* dummy = nullptr;
};

int main() {
  MyLinkedList ls;
  ls.addAtHead(1);
  ls.addAtTail(3);
  ls.addAtIndex(1, 2);
  cout << ls.get(1) << endl;
  ls.deleteAtIndex(1);
  cout << ls.get(1) << endl;
  return 0;
}