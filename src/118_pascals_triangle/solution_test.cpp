#include "solution.cpp"

#include <gtest/gtest.h>

TEST(Generate, Example1) {
  constexpr auto kNumRows = 5;

  const std::vector<std::vector<int>> want = {
      {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1},
  };

  const auto got = Solution{}.generate(kNumRows);

  ASSERT_EQ(want, got);
}

TEST(Generate, Example2) {
  constexpr auto kNumRows = 1;

  const std::vector<std::vector<int>> want = {
      {1},
  };

  const auto got = Solution{}.generate(kNumRows);

  ASSERT_EQ(want, got);
}
