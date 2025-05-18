#include "solution.cpp"

#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {

struct TestCase {
  std::string name;
  int w;
  int h;
  std::vector<int> horizontal_cuts;
  std::vector<int> vertical_cuts;
  int expected;
};

class MaxAreaOfCake : public testing::TestWithParam<TestCase> {};

std::vector<TestCase> CreateTestCases() {
  return {
      {
          "example_1",  // name
          5,            // w
          4,            // h
          {1, 2, 4},    // horizontal_cuts
          {1, 3},       // vertical_cuts
          4,            // expected
      },
      {
          "example_2",  // name
          5,            // w
          4,            // h
          {3, 1},       // horizontal_cuts
          {1},          // vertical_cuts
          6,            // expected
      },
      {
          "example_3",  // name
          5,            // w
          4,            // h
          {3},          // horizontal_cuts
          {3},          // vertical_cuts
          9,            // expected
      },
      {
          "failed_test_1",  // name
          1000000000,       // w
          1000000000,       // h
          {2},              // horizontal_cuts
          {2},              // vertical_cuts
          81,               // expected
      },
  };
}

}  // namespace

TEST_P(MaxAreaOfCake, Test) {
  auto param = GetParam();

  ASSERT_EQ(param.expected,
            Solution{}.maxArea(param.w, param.h, param.horizontal_cuts,
                               param.vertical_cuts));
}

INSTANTIATE_TEST_SUITE_P(MaxAreaOfCake, MaxAreaOfCake,
                         testing::ValuesIn(CreateTestCases()),
                         [](const auto& test_case) {
                           return test_case.param.name;
                         });
