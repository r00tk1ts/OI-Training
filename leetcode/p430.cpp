#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
 public:
  Node(int v) : val(v), prev(nullptr), next(nullptr), child(nullptr) {}

 public:
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

class Solution {
 public:
  Node* flatten(Node* head) {
    helper(head);
    return head;
  }

  Node* helper(Node* head) {
    Node* prev = nullptr;
    while (head) {
      if (head->child) {
        Node* next = head->next;
        head->next = head->child;
        head->child->prev = head;
        Node* tail = helper(head->child);
        head->child = nullptr;
        tail->next = next;
        if (next) next->prev = tail;

        prev = tail;
        head = next;
      } else {
        prev = head;
        head = head->next;
      }
    }
    return prev;
  }
};

int main() {
  Node n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
  Node n7(7), n8(8), n9(9), n10(10);
  Node n11(11), n12(12);
  n1.next = &n2;
  n2.prev = &n1;
  n2.next = &n3;
  n3.prev = &n2;
  n3.next = &n4;
  n4.prev = &n3;
  n4.next = &n5;
  n5.prev = &n4;
  n5.next = &n6;
  n6.prev = &n5;

  n3.child = &n7;
  n7.next = &n8;
  n8.prev = &n7;
  n8.next = &n9;
  n9.prev = &n8;
  n9.next = &n10;
  n10.prev = &n9;

  n8.child = &n11;
  n11.next = &n12;
  n12.prev = &n11;

  auto head = Solution().flatten(&n1);
  cout << "addr\tval\tprev\tnext\n";
  while (head) {
    cout << head << "\t" << head->val << "\t" << head->prev << "\t" << head->next << "\n";
    head = head->next;
  }
  cout << endl;
  return 0;
}