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
  // Given a binary tree, find its minimum depth.
  //
  // The minimum depth is the number of nodes along the shortest path from the
  // root node down to the nearest leaf node.
  //
  // Note: A leaf is a node with no children.
  int minDepth(const TreeNode* root) const {
    if (root == nullptr) {
      return 0;
    }

    if (root->left == nullptr) {
      return 1 + minDepth(root->right);
    }

    if (root->right == nullptr) {
      return 1 + minDepth(root->left);
    }

    auto left = minDepth(root->left);
    auto right = minDepth(root->right);

    return 1 + std::min(left, right);
  }
};
