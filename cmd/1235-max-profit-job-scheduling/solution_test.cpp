#include "solution.cpp"

#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {

struct TestCase {
  std::string name;
  std::vector<int> start_time;
  std::vector<int> end_time;
  std::vector<int> profit;
  int expected;
};

class JobScheduling : public testing::TestWithParam<TestCase> {};

std::vector<TestCase> CreateTestCases() {
  return std::vector<TestCase>{
      {
          .name = "simple_one",
          .start_time = {1},
          .end_time = {3},
          .profit = {50},
          .expected = 50,
      },
      {
          .name = "simple_two",
          .start_time = {1, 1},
          .end_time = {2, 3},
          .profit = {50, 60},
          .expected = 60,
      },
      {
          .name = "simple_three",
          .start_time = {1, 1, 2},
          .end_time = {2, 3, 4},
          .profit = {50, 60, 20},
          .expected = 70,
      },
      {
          .name = "simple_three_second_profitable",
          .start_time = {1, 1, 2},
          .end_time = {2, 3, 4},
          .profit = {50, 80, 20},
          .expected = 80,
      },
      {
          .name = "case_1",
          .start_time = {1, 2, 3, 3},
          .end_time = {3, 4, 5, 6},
          .profit = {50, 10, 40, 70},
          .expected = 120,
      },
      {
          .name = "case_2",
          .start_time = {1, 2, 3, 4, 6},
          .end_time = {3, 5, 10, 6, 9},
          .profit = {20, 20, 100, 70, 60},
          .expected = 150,
      },
      {
          .name = "case_3",
          .start_time = {1, 1, 1},
          .end_time = {2, 3, 4},
          .profit = {5, 6, 4},
          .expected = 6,
      },
  };
}

}  // namespace

TEST_P(JobScheduling, GetMaxProfit) {
  const auto param = GetParam();
  const auto result =
      Solution{}.jobScheduling(param.start_time, param.end_time, param.profit);

  ASSERT_EQ(param.expected, result);
}

INSTANTIATE_TEST_SUITE_P(JobSchedulingGetMaxProfit, JobScheduling,
                         testing::ValuesIn(CreateTestCases()),
                         [](const auto& test_case) {
                           return test_case.param.name;
                         });
