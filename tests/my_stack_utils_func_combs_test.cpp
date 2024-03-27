#include <vector>

#include <gtest/gtest.h>

#include "stack_utils.hpp"


class StackUtils2Test : public testing::TestWithParam<
                          std::tuple<
                            std::function<std::string(StackImpl&, const char*, int)>,
                            std::vector<std::string>
                          > > {
protected:
  StackImpl s;
};

TEST_P(StackUtils2Test, VariousCharArrReversals) {
  auto data = std::get<1>(GetParam());
  auto reverseMethod = std::get<0>(GetParam());

  std::string correctly_reversed = data[1];
  const char* word_to_reverse = data[0].c_str();
  int size = data[0].size();

  EXPECT_EQ(reverseMethod(s, word_to_reverse, size), correctly_reversed);
}

INSTANTIATE_TEST_SUITE_P(
  GetReversedDifferentApproaches, StackUtils2Test,
  testing::Combine(
    testing::Values(StackUtils::getReversed, StackUtils::getReversed2),
    testing::Values(
      std::vector<std::string>{"hello", "olleh"},
      std::vector<std::string>{"world", "dlrow"},
      std::vector<std::string>{"a", "a"}
    )
  ) // How to make for this case custom test case naming
);