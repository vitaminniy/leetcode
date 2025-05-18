#include "solution.cpp"

#include <gtest/gtest.h>

TEST(NextGreaterElement, Example1) {
  std::vector<int> left = {4, 1, 2};
  std::vector<int> right = {1, 3, 4, 2};
  std::vector<int> want = {-1, 3, -1};

  const auto got = Solution{}.nextGreaterElement(left, right);
  ASSERT_EQ(want, got);
}

TEST(NextGreaterElement, Example2) {
  std::vector<int> left = {2, 4};
  std::vector<int> right = {1, 2, 3, 4};
  std::vector<int> want = {3, -1};

  const auto got = Solution{}.nextGreaterElement(left, right);
  ASSERT_EQ(want, got);
}
