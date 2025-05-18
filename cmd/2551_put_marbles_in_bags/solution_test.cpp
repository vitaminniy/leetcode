#include "solution.cpp"

#include <gtest/gtest.h>

TEST(PutMarbles, Example1) {
  std::vector<int> weights = {1, 3, 5, 1};
  constexpr int k = 2;
  constexpr int want = 4;

  const auto got = Solution{}.putMarbles(weights, k);
  ASSERT_EQ(want, got);
}

TEST(PutMarbles, Example2) {
  std::vector<int> weights = {1, 3};
  constexpr int k = 2;
  constexpr int want = 0;

  const auto got = Solution{}.putMarbles(weights, k);
  ASSERT_EQ(want, got);
}
