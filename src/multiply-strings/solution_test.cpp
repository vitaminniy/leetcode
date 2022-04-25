#include "solution.cpp"

#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {

struct MultiplyTestCase {
  std::string name;
  std::string s1;
  std::string s2;
  std::string expected;
};

struct Multiply : public ::testing::TestWithParam<MultiplyTestCase> {};

std::vector<MultiplyTestCase> CreateMultiplyTestCases() {
  return {
      {
          "Example_1",  // name
          "2",          // s1
          "3",          // s2
          "6",          // expected
      },
      {
          "Example_2",  // name
          "123",        // s1
          "456",        // s2
          "56088",      // expected
      },
  };
}

}  // namespace

TEST_P(Multiply, Test) {
  const auto param = GetParam();

  const auto actual = Solution{}.multiply(param.s1, param.s2);
  ASSERT_EQ(param.expected, actual);
}

INSTANTIATE_TEST_SUITE_P(Multiply, Multiply,
                         ::testing::ValuesIn(CreateMultiplyTestCases()),
                         [](const auto& test_case) {
                           return test_case.param.name;
                         });
