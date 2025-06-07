#include "solution.cpp"

#include <gtest/gtest.h>

TEST(FindRelativeRanks, Example1) {
  std::vector<int> score = {5, 4, 3, 2, 1};
  std::vector<std::string> want = {"Gold Medal", "Silver Medal", "Bronze Medal",
                                   "4", "5"};

  auto got = Solution{}.findRelativeRanks(score);

  ASSERT_EQ(want, got);
}

TEST(FindRelativeRanks, Example2) {
  std::vector<int> score = {10, 3, 8, 9, 4};
  std::vector<std::string> want = {"Gold Medal", "5", "Bronze Medal",
                                   "Silver Medal", "4"};

  auto got = Solution{}.findRelativeRanks(score);

  ASSERT_EQ(want, got);
}

TEST(FindRelativeRanks, Empty) {
  std::vector<int> score = {};
  std::vector<std::string> want = {};

  auto got = Solution{}.findRelativeRanks(score);

  ASSERT_EQ(want, got);
}

TEST(FindRelativeRanks, Single) {
  std::vector<int> score = {1};
  std::vector<std::string> want = {"Gold Medal"};

  auto got = Solution{}.findRelativeRanks(score);

  ASSERT_EQ(want, got);
}
