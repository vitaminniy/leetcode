#include "solution.cpp"

#include <gtest/gtest.h>

static Solution kSolution{};

TEST(NumberOfSubsequences, Example1) {
  std::vector<int> nums{2, 4, 6, 8, 10};
  auto output = kSolution.numberOfArithmeticSlices(nums);
  ASSERT_EQ(7, output);
}

TEST(NumberOfSubsequences, Example2) {
  std::vector<int> nums{7, 7, 7, 7, 7};
  auto output = kSolution.numberOfArithmeticSlices(nums);
  ASSERT_EQ(16, output);
}
