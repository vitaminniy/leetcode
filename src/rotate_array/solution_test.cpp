#include "solution.cpp"

#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {

struct RotateTestCase final {
  std::string name{};
  int k{};
  std::vector<int> source{};
  std::vector<int> expected{};
};

struct RotateTest : public ::testing::TestWithParam<RotateTestCase> {};

std::vector<RotateTestCase> MakeRotateTestCases() {
  return {
      {
          "rotate_1",  // name
          1,           // k
          {1},         // source
          {1},         // expected
      },
      {
          "rotate_example_1",     // name
          3,                      // k
          {1, 2, 3, 4, 5, 6, 7},  // source
          {5, 6, 7, 1, 2, 3, 4},  // expected
      },
      {
          "rotate_example_2",  // name
          2,                   // k
          {-1, -100, 3, 99},   // source
          {3, 99, -1, -100},   // expected
      },
  };
}

}  // namespace

TEST_P(RotateTest, Parametrized) {
  const auto param = GetParam();

  auto source = param.source;
  Solution{}.rotate(source, param.k);

  ASSERT_EQ(param.expected, source) << param.name;
}

INSTANTIATE_TEST_SUITE_P(RotateArrayTest, RotateTest,
                         ::testing::ValuesIn(MakeRotateTestCases()),
                         [](const auto& test_case) {
                           return test_case.param.name;
                         });
