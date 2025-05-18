#include "solution.cpp"

#include <gtest/gtest.h>

TEST(RegexpMatching, Example1) {
  const std::string s = "aa";
  const std::string p = "a";
  const auto result = Solution{}.isMatch(s, p);
  ASSERT_FALSE(result);
}

TEST(RegexpMatching, Example2) {
  const std::string s = "aa";
  const std::string p = "a*";
  const auto result = Solution{}.isMatch(s, p);
  ASSERT_TRUE(result);
}

TEST(RegexpMatching, Example3) {
  const std::string s = "ab";
  const std::string p = ".*";
  const auto result = Solution{}.isMatch(s, p);
  ASSERT_TRUE(result);
}
