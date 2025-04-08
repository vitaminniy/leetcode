#include "solution.cpp"

#include <gtest/gtest.h>

// - The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
// - The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
TEST(MinimumPairRemoval, Example1) {
  std::vector<int> nums = {5, 2, 3, 1};
  auto want = 2;

  auto got = Solution{}.minimumPairRemoval(nums);

  ASSERT_EQ(want, got);
}

// The array nums is already sorted.
TEST(MinimumPairRemoval, Example2) {
  std::vector<int> nums = {1, 2, 2};
  auto want = 0;

  auto got = Solution{}.minimumPairRemoval(nums);

  ASSERT_EQ(want, got);
}
