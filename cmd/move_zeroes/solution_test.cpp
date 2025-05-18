#include "solution.cpp"

#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {

struct MoveZeroesTestCase {
  std::string name{};
  std::vector<int> source{};
  std::vector<int> expected{};
};

struct MoveZeroesTest : public ::testing::TestWithParam<MoveZeroesTestCase> {};

std::vector<MoveZeroesTestCase> MakeMoveZeroesTestCases() {
  return {
      {
          "example_1",       // name
          {0, 1, 0, 3, 12},  // source
          {1, 3, 12, 0, 0},  // expected
      },
      {
          "example_2",  // name
          {0},          // source
          {0},          // expected
      },
      {
          "no_zeroes_to_move",  // name
          {1, 2, 3, 4},         // source
          {1, 2, 3, 4},         // expected
      },
      {
          "move_from_top",  // name
          {0, 1, 2, 3, 4},  // source
          {1, 2, 3, 4, 0},  // expected
      },
  };
}

}  // namespace

TEST_P(MoveZeroesTest, Parametrized) {
  const auto param = GetParam();
  auto source = param.source;

  Solution{}.moveZeroes(source);

  ASSERT_EQ(param.expected, source) << param.name;
}

INSTANTIATE_TEST_SUITE_P(MoveZeroes, MoveZeroesTest,
                         ::testing::ValuesIn(MakeMoveZeroesTestCases()),
                         [](const auto& test_case) {
                           return test_case.param.name;
                         });
