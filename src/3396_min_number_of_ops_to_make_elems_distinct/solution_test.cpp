#include "solution.cpp"

#include <gtest/gtest.h>

TEST(MinimumOperations, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 2, 3, 3, 5, 7};
  auto want = 2;

  auto got = Solution{}.minimumOperations(nums);

  ASSERT_EQ(want, got);
}

TEST(MinimumOperations, Example2) {
  std::vector<int> nums = {4, 5, 6, 4, 4};
  auto want = 2;

  auto got = Solution{}.minimumOperations(nums);

  ASSERT_EQ(want, got);
}

TEST(MinimumOperations, Example3) {
  std::vector<int> nums = {6, 7, 8, 9};
  auto want = 0;

  auto got = Solution{}.minimumOperations(nums);

  ASSERT_EQ(want, got);
}
