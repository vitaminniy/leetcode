#include "solution.cpp"

#include <gtest/gtest.h>

TEST(MaximumScore, Example1) {
  std::vector<int> nums = {8, 3, 9, 3, 8};
  const auto k = 2;

  const auto score = Solution{}.maximumScore(nums, k);
  ASSERT_EQ(81, score);
}

TEST(MaximumScore, Example2) {
  std::vector<int> nums = {19, 12, 14, 6, 10, 18};
  const auto k = 3;

  const auto score = Solution{}.maximumScore(nums, k);
  ASSERT_EQ(4788, score);
}
