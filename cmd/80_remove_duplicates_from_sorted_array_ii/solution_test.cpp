#include "solution.cpp"

#include <gtest/gtest.h>

TEST(RemoveDuplicates, Example1) {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};

  const std::vector<int> result = {1, 1, 2, 2, 3};

  auto k = Solution{}.removeDuplicates(nums);

  ASSERT_EQ(result.size(), k);
  ASSERT_EQ(result, nums);
}

TEST(RemoveDuplicates, Example2) {
  std::vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

  const std::vector<int> result = {0, 0, 1, 1, 2, 3, 3};

  auto k = Solution{}.removeDuplicates(nums);

  ASSERT_EQ(result.size(), k);
  ASSERT_EQ(result, nums);
}

TEST(RemoveDuplicates, Empty) {
  std::vector<int> nums = {};

  const std::vector<int> result = {};

  auto k = Solution{}.removeDuplicates(nums);

  ASSERT_EQ(result.size(), k);
  ASSERT_EQ(result, nums);
}

TEST(RemoveDuplicates, Single) {
  std::vector<int> nums = {1};

  const std::vector<int> result = {1};

  auto k = Solution{}.removeDuplicates(nums);

  ASSERT_EQ(result.size(), k);
  ASSERT_EQ(result, nums);
}
