#include "solution.cpp"

#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {

struct RomanToIntTestCase {
  std::string name;
  std::string roman;
  int expected;
};

struct RomanToInt : public ::testing::TestWithParam<RomanToIntTestCase> {};

std::vector<RomanToIntTestCase> CreateRomanToIntTestCases() {
  return {
      {
          "Example_1",  // name
          "III",        // roman
          3,            // expected
      },
      {
          "Example_2",  // name
          "LVIII",      // roman
          58,           // expected
      },
      {
          "Example_3",  // name
          "MCMXCIV",    // roman
          1994,         // expected
      },
  };
}

}  // namespace

TEST_P(RomanToInt, Test) {
  const auto param = GetParam();

  const auto actual = Solution{}.romanToInt(param.roman);
  ASSERT_EQ(param.expected, actual);
}

INSTANTIATE_TEST_SUITE_P(RomanToInt, RomanToInt,
                         ::testing::ValuesIn(CreateRomanToIntTestCases()),
                         [](const auto& test_case) {
                           return test_case.param.name;
                         });
