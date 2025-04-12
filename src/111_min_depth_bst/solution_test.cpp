#include "solution.cpp"

#include <gtest/gtest.h>

TEST(MinDepth, Example1) {
  constexpr auto want = 2;

  // [3,9,20,null,null,15,7]
  const auto* root = new TreeNode(
      /*val*/ 3,
      /*left*/ new TreeNode(9),
      /*right*/
      new TreeNode(
          /*val*/ 20,
          /*left*/ new TreeNode(15),
          /*right*/ new TreeNode(7)));

  const auto got = Solution{}.minDepth(root);

  ASSERT_EQ(want, got);
}

TEST(MinDepth, Example2) {
  constexpr auto want = 5;

  // [2,null,3,null,4,null,5,null,6]
  const auto* root = new TreeNode(
      /*val*/ 2,
      /*left*/ nullptr,
      /*right*/
      new TreeNode(
          /*val*/ 3,
          /*left*/ nullptr,
          /*right*/
          new TreeNode(
              /*val*/ 4,
              /*left*/ nullptr,
              /*right*/
              new TreeNode(
                  /*val*/ 5,
                  /*left*/ nullptr,
                  /*right*/ new TreeNode(6)))));

  const auto got = Solution{}.minDepth(root);

  ASSERT_EQ(want, got);
}
