#include "solution.cpp"

#include <gtest/gtest.h>

TEST(IsBalanced, Example1) {
  const auto want = true;

  auto* root = new TreeNode(
      /*val*/ 3,
      /*left*/ new TreeNode(9),
      /*right*/
      new TreeNode(
          /*val*/ 20,
          /*left*/ new TreeNode(15),
          /*right*/ new TreeNode(7)));

  const auto got = Solution{}.isBalanced(root);

  ASSERT_EQ(want, got);
}

TEST(IsBalanced, Example2) {
  const auto want = false;

  auto* root = new TreeNode(
      /*val*/ 1,
      /*left*/
      new TreeNode(
          /*val*/ 2,
          /*left*/
          new TreeNode(
              /*val*/ 3,
              /*left*/ new TreeNode(4),
              /*right*/ new TreeNode(4)),
          /*right*/ new TreeNode(3)),
      /*right*/ new TreeNode(2));

  const auto got = Solution{}.isBalanced(root);

  ASSERT_EQ(want, got);
}

TEST(IsBalanced, Example3) {
  const auto want = true;

  TreeNode* root = nullptr;

  const auto got = Solution{}.isBalanced(root);

  ASSERT_EQ(want, got);
}
