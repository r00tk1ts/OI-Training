#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return head;
    // firstly each node insert itself by once
    Node* p = head;
    while (p) {
      Node* next = p->next;
      p->next = new Node(p->val);
      p = p->next;
      p->next = next;
      p = next;
    }
    // adjust the random pointer for each copied node
    Node* origin = head;
    while (origin) {
      Node* copied = origin->next;
      if (origin->random) {
        copied->random = origin->random->next;
      }
      origin = copied->next;
    }
    // drop off all the copied nodes
    Node origin_dummy(0);
    Node copied_dummy(0);
    Node* p1 = &origin_dummy;
    Node* p2 = &copied_dummy;
    while (head) {
      p1->next = head;
      p2->next = head->next;
      head = head->next->next;
      p1 = p1->next;
      p2 = p2->next;
    }
    p1->next = nullptr;
    p2->next = nullptr;
    return copied_dummy.next;
  }
};

int main() {
  Node* n1 = new Node(7);
  Node* n2 = new Node(13);
  Node* n3 = new Node(11);
  Node* n4 = new Node(10);
  Node* n5 = new Node(1);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  n2->random = n1;
  n3->random = n5;
  n4->random = n3;
  n5->random = n1;

  Node* head = Solution().copyRandomList(n1);
  while (head) {
    cout << head->val << "\t" << (head->random ? head->random->val : -1) << endl;
    head = head->next;
  }
  return 0;
}