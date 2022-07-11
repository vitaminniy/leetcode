#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode* left, TreeNode* right);
};

class Solution {
 public:
  std::vector<int> rightSideView(TreeNode* root) const {
    if (root == nullptr) {
      return {};
    }

    std::vector<int> result;

    std::queue<TreeNode*> queue;
    queue.push(root);

    TreeNode* node = nullptr;
    while (!queue.empty()) {
      auto n = queue.size();
      for (std::size_t i = 0; i < n; i++) {
        node = queue.front();
        queue.pop();

        if (node->left) {
          queue.push(node->left);
        }
        if (node->right) {
          queue.push(node->right);
        }
      }

      result.push_back(node->val);
    }

    return result;
  }
};
