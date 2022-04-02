#include "solution.cpp"

#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {

struct TwoSumSortedTestCase {
  std::string name{};
  std::vector<int> numbers{};
  int target{};
  std::vector<int> expected{};
};

struct TwoSumSortedTest
    : public ::testing::TestWithParam<TwoSumSortedTestCase> {};

std::vector<TwoSumSortedTestCase> MakeTwoSumSortedTestCases() {
  return {
      {
          "example_1",     // name
          {2, 7, 11, 15},  // numbers
          9,               // target
          {1, 2},          // expected
      },
      {
          "example_2",  // name
          {2, 3, 4},    // numbers
          6,            // target
          {1, 3},       // expected
      },
      {
          "example_3",  // name
          {-1, 0},      // numbers
          -1,           // target
          {1, 2},       // expected
      },
  };
}

}  // namespace

TEST_P(TwoSumSortedTest, Parametrized) {
  const auto param = GetParam();
  const auto actual = Solution{}.twoSum(param.numbers, param.target);

  ASSERT_EQ(param.expected, actual) << param.name;
}

INSTANTIATE_TEST_SUITE_P(TwoSumSorted, TwoSumSortedTest,
                         ::testing::ValuesIn(MakeTwoSumSortedTestCases()),
                         [](const auto& test_case) {
                           return test_case.param.name;
                         });
