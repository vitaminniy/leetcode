#include "solution.cpp"

#include <gtest/gtest.h>

TEST(MaxTaxiEarnings, Case1) {
  auto n = 5;
  std::vector<std::vector<int>> rides = {
      {2, 5, 4},
      {1, 5, 1},
  };

  auto result = Solution{}.maxTaxiEarnings(n, rides);
  ASSERT_EQ(7, result);
}

TEST(MaxTaxiEarnings, Case2) {
  auto n = 20;
  std::vector<std::vector<int>> rides = {{1, 6, 1},   {3, 10, 2},  {10, 12, 3},
                                         {11, 12, 2}, {12, 15, 2}, {13, 18, 1}};

  auto result = Solution{}.maxTaxiEarnings(n, rides);
  ASSERT_EQ(20, result);
}
