#include <vector>

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
  // Given an integer array nums where the elements are sorted in ascending
  // order, convert it to a height-balanced binary search tree.
  TreeNode* sortedArrayToBST(const std::vector<int>& nums) const {
    return getNodes(0, static_cast<int>(nums.size() - 1), nums);
  }

 private:
  TreeNode* getNodes(int left, int right, const std::vector<int>& nums) const {
    if (left > right) {
      return nullptr;
    }

    const auto mid = (right - left) / 2 + left;

    auto* node = new TreeNode(nums[mid]);

    node->left = getNodes(left, mid - 1, nums);
    node->right = getNodes(mid + 1, right, nums);

    return node;
  }
};
