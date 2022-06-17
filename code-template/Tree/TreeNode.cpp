#include "TreeNode.h"

#include <cmath>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

TreeNode* TreeHelper::BuildTree(const vector<int>& v) {
  if (v.empty() || v[0] == -101) {
    return nullptr;
  }

  auto* root = new TreeNode(v[0]);
  deque<TreeNode*> queue{root};
  int pos = 1;

  while (pos < v.size()) {
    auto* next = queue.front();
    queue.pop_front();
    if (v[pos] != -101) {
      next->left = new TreeNode(v[pos]);
      queue.emplace_back(next->left);
    }

    if (pos + 1 == v.size()) break;

    if (v[pos + 1] != -101) {
      next->right = new TreeNode(v[pos + 1]);
      queue.emplace_back(next->right);
    }

    pos += 2;
  }
  return root;
}

void TreeHelper::PrintTreeHorizontal(TreeNode* root) {
  cout << traversePreOrder(root) << endl;
}

void TreeHelper::traverseNodes(ostringstream& oss,
                               const string& padding,
                               const string& pointer,
                               TreeNode* node,
                               bool hasRightSibling) {
  if (node == nullptr) return;

  oss << "\n" << padding << pointer << node->val;

  ostringstream padding_oss;
  padding_oss << padding;
  if (hasRightSibling) {
    padding_oss << "│  ";
  } else {
    padding_oss << "   ";
  }
  string padding_both = padding_oss.str();
  string pointer_right = "└──";
  string pointer_left = (node->right != nullptr) ? "├──" : "└──";

  traverseNodes(oss, padding_both, pointer_left, node->left, node->right != nullptr);
  traverseNodes(oss, padding_both, pointer_right, node->right, false);
}

string TreeHelper::traversePreOrder(TreeNode* root) {
  if (root == nullptr) {
    return "";
  }

  ostringstream oss;
  oss << root->val;

  string pointer_right = "└──";
  string pointer_left = root->right != nullptr ? "├──" : "└──";

  traverseNodes(oss, "", pointer_left, root->left, root->right != nullptr);
  traverseNodes(oss, "", pointer_right, root->right, false);

  return oss.str();
}

int TreeHelper::getTreeDepth(TreeNode* root) {
  if (root == nullptr) return 0;
  return 1 + max(getTreeDepth(root->left), getTreeDepth(root->right));
}
