#include <algorithm>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  // Given a binary tree, determine if it is height-balanced.
  //
  // A height-balanced binary tree is a binary tree in which the depth of the
  // two subtrees of every node never differs by more than one.
  bool isBalanced(const TreeNode* root) const {
    if (root == nullptr) {
      return true;
    }

    auto balance = getHeightBalance(root);
    return balance != -1;
  }

 private:
  // -1 in case it's unbalanced.
  //
  int getHeightBalance(const TreeNode* node) const {
    if (node == nullptr) {
      return 0;
    }

    auto left = getHeightBalance(node->left);
    if (left < 0) {
      return left;
    }

    auto right = getHeightBalance(node->right);
    if (right < 0) {
      return right;
    }

    if (std ::abs(left - right) > 1) {
      return -1;
    }

    return std::max(left, right) + 1;
  }
};
