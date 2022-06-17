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
  bool isSubPath(ListNode* head, TreeNode* root) {
    if (!head) return true;
    if (!root) return false;
    if (helper(head, root)) return true;
    return isSubPath(head, root->left) || isSubPath(head, root->right);
  }
  bool helper(ListNode* head, TreeNode* root) {
    if (!head) return true;
    if (!root) return false;
    if (head->val != root->val) return false;
    return helper(head->next, root->left) || helper(head->next, root->right);
  }
};

int main() {
  TreeNode* root = new TreeNode(1, new TreeNode(4), new TreeNode(4));
  TreeNode* ptr = root->left;
  ptr->right = new TreeNode(2, new TreeNode(1), nullptr);

  ptr = root->right;
  ptr->left = new TreeNode(2, new TreeNode(6), new TreeNode(8, new TreeNode(1), new TreeNode(3)));

  ListNode* head = new ListNode(4, new ListNode(2, new ListNode(8)));
  cout << boolalpha << Solution().isSubPath(head, root) << endl;
  return 0;
}