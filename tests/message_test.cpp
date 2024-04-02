#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "message_content.hpp"


class MessageTest : public testing::TestWithParam<std::string> {
protected:
    MessageTest() : mess(GetParam()) {}
    Message mess;
};


TEST_P(MessageTest, is_message_html_test) {

  bool is_html = mess.isMessageHTML();
  
  EXPECT_THAT(is_html, testing::Eq(true));
}

INSTANTIATE_TEST_SUITE_P(
  isHTML,
  MessageTest,
  testing::Values(
    std::string("https://www.example.com"),
    std::string("This is plain text, no HTML."),              
    std::string("http://www.example.com")      
  ),
  [](const testing::TestParamInfo<std::string>& info) {
    std::string valid_name = testing::PrintToString(info.param);
    valid_name.erase(std::remove_if(valid_name.begin(), valid_name.end(),
      [](char c) { return !std::isalnum(c) && c != '_'; }), valid_name.end());
    return valid_name;
  }
);

