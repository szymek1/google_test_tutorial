#include <vector>

#include <gtest/gtest.h>

#include "stack_utils.hpp"


class StackUtilsTest : public testing::TestWithParam<std::vector<std::string>> {
protected:
    StackImpl s;
};

TEST_P(StackUtilsTest, TestGetReversed) {
  auto in = GetParam();
  std::string correctly_reversed = in[1];

  const char* word_to_reverse = in[0].c_str();
  int size = in[0].size();

  EXPECT_EQ(
      StackUtils::getReversed(s, word_to_reverse, size),
      correctly_reversed
  );
}

INSTANTIATE_TEST_SUITE_P(
    GetReversed,
    StackUtilsTest,
    testing::Values(
    std::vector<std::string>{"hello", "olleh"},
    std::vector<std::string>{"world", "dlrow"},
    std::vector<std::string>{ "a", "a"}
  ),
    [](const testing::TestParamInfo<StackUtilsTest::ParamType>& info) {
        const std::string& first_string = info.param[0];
        return first_string;
    }
);