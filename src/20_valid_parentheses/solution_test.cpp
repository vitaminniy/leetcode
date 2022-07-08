#include "solution.cpp"

#include <gtest/gtest.h>

TEST(IsValid, Example1) { ASSERT_TRUE(Solution{}.isValid("()")); }

TEST(IsValid, Example2) { ASSERT_TRUE(Solution{}.isValid("()[]{}")); }

TEST(IsValid, Example3) { ASSERT_FALSE(Solution{}.isValid("(]")); }

TEST(IsValid, Custom1) { ASSERT_TRUE(Solution{}.isValid("((()))[()]")); }
