#include "solution.cpp"

#include <gtest/gtest.h>

TEST(StrStr, Example1) { ASSERT_EQ(2, Solution{}.strStr("hello", "ll")); }

TEST(StrStr, Example2) { ASSERT_EQ(-1, Solution{}.strStr("aaaaa", "bba")); }

TEST(StrStr, Empty) { ASSERT_EQ(0, Solution{}.strStr("aaaaa", "")); }

TEST(StrStr, issip) { ASSERT_EQ(4, Solution{}.strStr("mississipi", "issip")); }

TEST(StrStr, issi) { ASSERT_EQ(1, Solution{}.strStr("mississipi", "issi")); }
