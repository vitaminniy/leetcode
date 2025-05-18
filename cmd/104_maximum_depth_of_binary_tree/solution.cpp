#include <algorithm>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  // Given the root of a binary tree, return its maximum depth.
  //
  // A binary tree's maximum depth is the number of nodes along the longest
  // path from the root node down to the farthest leaf node.
  int maxDepth(const TreeNode* root) const {
    if (root == nullptr) {
      return 0;
    }

    auto left = maxDepth(root->left);
    auto right = maxDepth(root->right);

    return 1 + std::max(left, right);
  }
};
