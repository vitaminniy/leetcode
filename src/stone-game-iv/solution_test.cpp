#include "solution.cpp"

#include <string>

#include <gtest/gtest.h>

namespace {

/// @struct Stone Game solution test case.
struct SolutionTestCase {
  /// @property Initial number of stones.
  int stones{};
  /// @property Expected result of Alice winning the game.
  bool expected{};
  /// @property Test case name.
  std::string name{};
};

class TestSolution : public ::testing::TestWithParam<SolutionTestCase> {};

TEST_P(TestSolution, Test) {
  const auto param = GetParam();
  const auto actual = Solution{}.winnerSquareGame(param.stones);

  ASSERT_EQ(param.expected, actual);
}

std::vector<SolutionTestCase> CreateSolutionTestCases() {
  return {
      {
          1,               // stones
          true,            // expected,
          "single stone",  // name
      },
      {
          2,             // stones
          false,         // expected,
          "two stones",  // name
      },
      {
          4,                         // stones
          true,                      // expected,
          "initial perfect square",  // name
      },
      {
          3,               // stones
          true,            // expected,
          "three stones",  // name
      },
      {
          15,                 // stones
          false,              // expected,
          "fiveteen stones",  // name
      },
  };
}

std::string GetTestName(const std::string& name) {
  auto result = name;
  for (auto it = result.begin(); it != result.end(); ++it) {
    switch (*it) {
      case ' ':
      case '-':
      case ',':
      case '(':
      case ')':
      case '=':
        *it = '_';
    }
  }

  return result;
}

}  // namespace

INSTANTIATE_TEST_SUITE_P(Solution, TestSolution,
                         ::testing::ValuesIn(CreateSolutionTestCases()),
                         [](const auto& test_case) {
                           return GetTestName(test_case.param.name);
                         });
