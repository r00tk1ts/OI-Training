#include <bits/stdc++.h>

using namespace std;

/*
class FrontMiddleBackQueue {
  deque<int> a, b;
  void a2b() {
    if (a.size() <= b.size()) return;
    b.push_front(a.back());
    a.pop_back();
  }
  void b2a() {
    if (b.size() <= a.size() + 1) return;
    a.push_back(b.front());
    b.pop_front();
  }

 public:
  FrontMiddleBackQueue() {}
  void pushFront(int val) {
    a.push_front(val);
    a2b();
  }
  void pushMiddle(int val) {
    a.push_back(val);
    a2b();
  }
  void pushBack(int val) {
    b.push_back(val);
    b2a();
  }
  int popFront() {
    if (a.empty() && b.empty()) return -1;
    int ans;
    if (a.empty()) {
      ans = b.front();
      b.pop_front();
    } else {
      ans = a.front();
      a.pop_front();
      b2a();
    }
    return ans;
  }
  int popMiddle() {
    if (a.empty() && b.empty()) return -1;
    int ans;
    if (a.size() == b.size()) {
      ans = a.back();
      a.pop_back();
    } else {
      ans = b.front();
      b.pop_front();
    }
    return ans;
  }
  int popBack() {
    if (a.empty() && b.empty()) return -1;
    int ans = b.back();
    b.pop_back();
    a2b();
    return ans;
  }
};
*/

struct Node {
  int val;
  Node *prev, *next;
  Node() {
    val = 0, prev = next = NULL;
  }

  Node(int x) {
    val = x, prev = next = NULL;
  }

  Node(int x, Node* p, Node* n) {
    val = x, prev = p, next = n;
  }
};

class FrontMiddleBackQueue {
 public:
  FrontMiddleBackQueue() {
    head = nullptr;
    size = 0;
  }
  ~FrontMiddleBackQueue() {
    while (head) {
      auto ptr = head->next;
      delete head;
      head = ptr;
    }
  }
  void pushFront(int val) {
    head = new Node(val, nullptr, head);
    if (head->next) {
      head->next->prev = head;
    }
    size++;
  }

  void pushMiddle(int val) {
    if (size == 0) {
      head = new Node(val);
      size++;
      return;
    }

    if (size == 1) {
      return pushFront(val);
    }

    Node* ptr = nullptr;
    int n = size / 2;
    while (n--) {
      if (ptr == nullptr)
        ptr = head;
      else
        ptr = ptr->next;
    }

    Node* next = ptr->next;
    ptr->next = new Node(val, ptr, next);
    if (next) next->prev = ptr->next;
    size++;
  }

  void pushBack(int val) {
    Node* ptr = head;
    if (!ptr) {
      head = new Node(val);
    } else {
      while (ptr->next) {
        ptr = ptr->next;
      }
      ptr->next = new Node(val, ptr, nullptr);
    }
    size++;
  }

  int popFront() {
    if (size == 0) return -1;
    int val = head->val;
    auto tmp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete tmp;
    size--;
    return val;
  }

  int popMiddle() {
    if (size == 0) return -1;
    if (size == 1) {
      int val = head->val;
      size--;
      delete head;
      head = nullptr;
      return val;
    }

    int n = size / 2;
    Node* ptr = nullptr;
    while (n--) {
      if (!ptr)
        ptr = head;
      else
        ptr = ptr->next;
    }

    int val = -1;
    Node* tmp = nullptr;
    if (size & 1) {
      val = ptr->next->val;
      tmp = ptr->next->next;
      delete ptr->next;
      ptr->next = tmp;
      if (tmp) tmp->prev = ptr;
    } else {
      if (ptr == head) {
        val = popFront();
        size++;
      } else {
        val = ptr->val;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
      }
    }
    size--;
    return val;
  }

  int popBack() {
    if (size == 0) return -1;
    if (size == 1) {
      int val = head->val;
      delete head;
      head = nullptr;
      size--;
      return val;
    }

    Node* ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
    }
    if (ptr->prev) ptr->prev->next = nullptr;
    size--;
    int val = ptr->val;
    delete ptr;
    return val;
  }

 private:
  Node* head;
  int size;
};
/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

int main() {
  return 0;
}