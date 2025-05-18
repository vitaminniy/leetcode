#include <vector>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}

  int val{0};
  TreeNode* left{nullptr};
  TreeNode* right{nullptr};
};

class Solution {
 public:
  std::vector<int> postorderTraversal(const TreeNode* root) const {
    std::vector<int> result;

    traverse(root, result);

    return result;
  }

 private:
  void traverse(const TreeNode* node, std::vector<int>& acc) const {
    if (node == nullptr) {
      return;
    }

    traverse(node->left, acc);
    traverse(node->right, acc);

    acc.push_back(node->val);
  }
};
