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
  // Given the root of a binary tree and an integer target, return true if
  // the tree has a root-to-leaf path such that adding up all the values along
  // the path equals target.
  //
  // A leaf is a node with no children.
  bool hasPathSum(const TreeNode* root, int target) const {
    if (root == nullptr) {
      return false;
    }

    if (root->left == nullptr && root->right == nullptr) {
      return target == root->val;
    }

    if (hasPathSum(root->left, target - root->val)) {
      return true;
    }

    if (hasPathSum(root->right, target - root->val)) {
      return true;
    }

    return false;
  }
};
