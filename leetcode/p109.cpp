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

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    return helper(head, nullptr);
  }

  TreeNode* helper(ListNode* head, ListNode* tail) {
    if (!head || head == tail) return nullptr;
    if (head->next == tail) return new TreeNode(head->val);

    ListNode *fast = head, *slow = head;
    while (fast != tail && fast->next != tail) {
      fast = fast->next->next;
      slow = slow->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->left = helper(head, slow);
    root->right = helper(slow->next, tail);
    return root;
  }
};

void bfs(TreeNode* root) {
  if (!root) return;
  TreeNode dummy(0);
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    auto ptr = q.front();
    q.pop();
    if (ptr == &dummy) {
      cout << "null\t";
    } else {
      cout << ptr->val << "\t";
      q.push(ptr->left ? ptr->left : &dummy);
      q.push(ptr->right ? ptr->right : &dummy);
    }
  }
  cout << endl;
}

int main() {
  ListNode* head =
      new ListNode(-10, new ListNode(-3, new ListNode(0, new ListNode(5, new ListNode(9)))));
  TreeNode* root = Solution().sortedListToBST(head);
  bfs(root);
  return 0;
}