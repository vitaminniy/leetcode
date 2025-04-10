#include "solution.cpp"

#include <gtest/gtest.h>

TEST(MaxDepth, Example1) {
  const auto want = 3;

  TreeNode left(9);

  TreeNode rightleft(15);
  TreeNode rightright(7);
  TreeNode right(20, &rightleft, &rightright);

  TreeNode root(3, &left, &right);

  const auto got = Solution{}.maxDepth(&root);

  ASSERT_EQ(want, got);
}

TEST(MaxDepth, Example2) {
  const auto want = 2;

  TreeNode right(2);

  TreeNode root(1, nullptr, &right);

  const auto got = Solution{}.maxDepth(&root);

  ASSERT_EQ(want, got);
}
