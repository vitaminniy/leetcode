#include "solution.cpp"

#include <gtest/gtest.h>

namespace {

struct ConvertToTitleTestCase {
  std::string name;
  int column;
  std::string want;
};

ConvertToTitleTestCase new_case(std::string&& name, int column,
                                std::string&& want) {
  return ConvertToTitleTestCase{std::move(name), column, std::move(want)};
}

// clang-format off
const std::vector<ConvertToTitleTestCase> kTestCases = {
    new_case("example_1", 1, "A"),
    new_case("example_2", 28, "AB"),
    new_case("example_3", 701, "ZY"),

    new_case("custom_1", 1, "A"),
    new_case("custom_2", 2, "B"),
    new_case("custom_3", 3, "C"),
    new_case("custom_4", 4, "D"),
    new_case("custom_5", 5, "E"),
    new_case("custom_6", 6, "F"),
    new_case("custom_7", 7, "G"),
    new_case("custom_8", 8, "H"),
    new_case("custom_9", 9, "I"),
    new_case("custom_10", 10, "J"),
    new_case("custom_11", 11, "K"),
    new_case("custom_12", 12, "L"),
    new_case("custom_13", 13, "M"),
    new_case("custom_14", 14, "N"),
    new_case("custom_15", 15, "O"),
    new_case("custom_16", 16, "P"),
    new_case("custom_17", 17, "Q"),
    new_case("custom_18", 18, "R"),
    new_case("custom_19", 19, "S"),
    new_case("custom_20", 20, "T"),
    new_case("custom_21", 21, "U"),
    new_case("custom_22", 22, "V"),
    new_case("custom_23", 23, "W"),
    new_case("custom_24", 24, "X"),
    new_case("custom_25", 25, "Y"),
    new_case("custom_26", 26, "Z"),
    new_case("custom_27", 27, "AA"),
    new_case("custom_28", 29, "AC"),
};
// clang-format on

class ConvertToTitleTest
    : public testing::TestWithParam<ConvertToTitleTestCase> {};

}  // namespace

TEST_P(ConvertToTitleTest, DoesConversion) {
  const auto param = GetParam();

  const auto got = Solution{}.convertToTitle(param.column);

  ASSERT_EQ(param.want, got);
}

INSTANTIATE_TEST_SUITE_P(ConvertToTitle, ConvertToTitleTest,
                         testing::ValuesIn(kTestCases),
                         [](const auto& info) { return info.param.name; });
