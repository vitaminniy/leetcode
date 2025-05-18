#include "solution.cpp"

#include <gtest/gtest.h>

static const Solution kSolution{};

TEST(IsPalindrome, Example1) { ASSERT_TRUE(kSolution.isPalindrome(121)); }

TEST(IsPalindrome, Example2) { ASSERT_FALSE(kSolution.isPalindrome(-121)); }

TEST(IsPalindrome, Example3) { ASSERT_FALSE(kSolution.isPalindrome(10)); }
