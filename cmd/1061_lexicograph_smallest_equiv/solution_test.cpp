#include "solution.cpp"

#include <gtest/gtest.h>

TEST(smallestEquivalentString, Explain) {
  const auto s1 = "abc";
  const auto s2 = "cde";
  const auto base = "eed";

  const auto result = Solution{}.smallestEquivalentString(s1, s2, base);

  ASSERT_EQ(result, "aab");
}

TEST(smallestEquivalentString, Example1) {
  const auto s1 = "parker";
  const auto s2 = "morris";
  const auto base = "parser";

  const auto result = Solution{}.smallestEquivalentString(s1, s2, base);

  ASSERT_EQ(result, "makkek");
}

TEST(smallestEquivalentString, Example2) {
  const auto s1 = "hello";
  const auto s2 = "world";
  const auto base = "hold";

  const auto result = Solution{}.smallestEquivalentString(s1, s2, base);

  ASSERT_EQ(result, "hdld");
}

TEST(smallestEquivalentString, Example3) {
  const auto s1 = "leetcode";
  const auto s2 = "programs";
  const auto base = "sourcecode";

  const auto result = Solution{}.smallestEquivalentString(s1, s2, base);

  ASSERT_EQ(result, "aauaaaaada");
}
