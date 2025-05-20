#include "solution.cpp"

#include <gtest/gtest.h>

TEST(LongestPalindrome, Example1) {
  const auto got = Solution{}.longestPalindrome("babad");
  const auto firstValid = "bab";
  const auto secondValid = "aba";

  ASSERT_TRUE(got == firstValid || got == secondValid);
}

TEST(LongestPalindrome, Example2) {
  const auto got = Solution{}.longestPalindrome("cbbd");

  ASSERT_EQ(got, "bb");
}
