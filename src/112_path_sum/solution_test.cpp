#include "solution.cpp"

#include <gtest/gtest.h>

TEST(HasPathSum, Example1) {
  // [5,4,8,11,null,13,4,7,2,null,null,null,1]
  auto* root = new TreeNode(
      /*val*/ 5,
      /*left*/
      new TreeNode(
          /*val*/ 4,
          /*left*/
          new TreeNode(
              /*val*/ 11,
              /*left*/ new TreeNode(7),
              /*right*/ new TreeNode(2)),
          /*right*/ nullptr),
      /*right*/
      new TreeNode(
          /*val*/ 8,
          /*left*/ new TreeNode(13),
          /*right*/
          new TreeNode(
              /*val*/ 4,
              /*left*/ nullptr,
              /*right*/ new TreeNode(1))));

  const int target = 22;

  const auto result = Solution{}.hasPathSum(root, target);

  ASSERT_TRUE(result);
}

TEST(HasPathSum, Example2) {
  // [1,2,3]
  auto* root = new TreeNode(
      /*val*/ 1,
      /*left*/ new TreeNode(2),
      /*right*/ new TreeNode(3));

  const int target = 5;

  const auto result = Solution{}.hasPathSum(root, target);

  ASSERT_FALSE(result);
}

TEST(HasPathSum, Example3) {
  // []
  TreeNode* root = nullptr;

  const int target = 0;

  const auto result = Solution{}.hasPathSum(root, target);

  ASSERT_FALSE(result);
}
