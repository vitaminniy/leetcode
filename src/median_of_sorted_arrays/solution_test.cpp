#include "solution.cpp"

#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {

namespace impl {

struct TestCase {
  std::vector<int> nums1{};
  std::vector<int> nums2{};
  double median{};
  std::string name{};
};

template <typename... Args>
TestCase MakeTestCase(std::string&& name, Args... args) {
  TestCase tc;
  tc.name = std::move(name);

  (args(tc), ...);

  return tc;
}

auto SetMedian(double median) {
  return [median](TestCase& tc) { tc.median = median; };
}

auto SetFirstNums(std::vector<int>&& nums) {
  return [nums](TestCase& tc) { tc.nums1 = nums; };
}

auto SetSecondNums(std::vector<int>&& nums) {
  return [nums](TestCase& tc) { tc.nums2 = nums; };
}

std::vector<TestCase> MakeTestCases() {
  return {
      MakeTestCase("empty_nums", SetMedian(0)),
      MakeTestCase("empty_second_nums_not_even", SetFirstNums({1, 2, 3}),
                   SetMedian(2)),
      MakeTestCase("empty_second_nums_even", SetFirstNums({1, 2, 3, 4}),
                   SetMedian(2.5)),
      MakeTestCase("empty_first_nums_not_even", SetSecondNums({1, 2, 3}),
                   SetMedian(2)),
      MakeTestCase("empty_first_nums_even", SetSecondNums({1, 2, 3, 4}),
                   SetMedian(2.5)),
      MakeTestCase("even_not_even_arrays", SetFirstNums({1, 3}),
                   SetSecondNums({2}), SetMedian(2.0)),
      MakeTestCase("double_even", SetFirstNums({1, 2}), SetSecondNums({3, 4}),
                   SetMedian(2.5)),
      MakeTestCase("all_zeros_even", SetFirstNums({0, 0}),
                   SetSecondNums({0, 0}), SetMedian(0)),
      MakeTestCase("all_zeros_not_event", SetFirstNums({0, 0}),
                   SetSecondNums({0}), SetMedian(0)),
  };
}

}  // namespace impl

class TestFindMedian : public ::testing::TestWithParam<impl::TestCase> {
 protected:
  impl::TestCase test_case;
};

TEST_P(TestFindMedian, Test) {
  const auto param = GetParam();

  const auto actual =
      Solution{}.findMedianSortedArrays(param.nums1, param.nums2);
  ASSERT_EQ(actual, param.median);
}

INSTANTIATE_TEST_SUITE_P(TestFindMedian, TestFindMedian,
                         ::testing::ValuesIn(impl::MakeTestCases()),
                         [](const auto& info) { return info.param.name; });

}  // namespace
