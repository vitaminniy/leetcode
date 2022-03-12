#include "solution.cpp"

#include <ios>
#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace isomorphic_strings {

namespace impl {

struct IsIsomorphicTestCase {
  std::string source{};
  std::string target{};
  bool expected{};

  inline std::string GetName() const {
    std::stringstream ss;
    ss << std::boolalpha << source << "_" << target << "_" << expected;
    return ss.str();
  }
};

}  // namespace impl

class IsIsomorphicTest
    : public ::testing::TestWithParam<impl::IsIsomorphicTestCase> {
 protected:
  impl::IsIsomorphicTestCase is_isomorphic_test_case;
};

std::vector<impl::IsIsomorphicTestCase> MakeTestCases() {
  return {
      {
          "egg",
          "add",
          true,
      },
      {
          "add",
          "egg",
          true,
      },
      {
          "foo",
          "bar",
          false,
      },
      {
          "paper",
          "title",
          true,
      },
  };
}

TEST_P(IsIsomorphicTest, IsIsomorphic) {
  const auto param = GetParam();
  const auto actual = Solution{}.isIsomorphic(param.source, param.target);

  EXPECT_EQ(actual, param.expected);
}

INSTANTIATE_TEST_SUITE_P(
    CheckIsIsomorphic, IsIsomorphicTest,
    ::testing::ValuesIn(isomorphic_strings::MakeTestCases()),
    [](const auto& info) { return info.param.GetName(); });

}  // namespace isomorphic_strings
