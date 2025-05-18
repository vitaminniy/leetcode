#include "solution.cpp"

#include <gtest/gtest.h>

TEST(LongestCommonPrefix, Example1) {
  std::vector<std::string> kStrings{
      "flower",
      "flow",
      "flight",
  };
  ASSERT_EQ("fl", Solution{}.longestCommonPrefix(kStrings));
}

TEST(LongestCommonPrefix, Example2) {
  std::vector<std::string> kStrings{
      "dog",
      "racecar",
      "car",
  };
  ASSERT_EQ("", Solution{}.longestCommonPrefix(kStrings));
}
