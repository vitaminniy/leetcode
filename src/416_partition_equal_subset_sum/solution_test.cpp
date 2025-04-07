#include "solution.cpp"

#include <gtest/gtest.h>

TEST(CanPartition, Example1) {
  std::vector<int> nums = {1, 5, 11, 5};
  auto want = true;

  auto got = Solution{}.canPartition(nums);

  ASSERT_EQ(want, got);
}

TEST(CanPartition, Example2) {
  std::vector<int> nums = {1,2,3,5};
  auto want = false;

  auto got = Solution{}.canPartition(nums);

  ASSERT_EQ(want, got);
}
