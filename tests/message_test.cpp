#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "message_content.hpp"


class MessageTest : public testing::TestWithParam<std::string> {
protected:
    Message mess;
};


TEST_P(MessageTest, is_message_html_test) {

  mess = Message(GetParam()); 
  bool is_html = mess.isMessageHTML();

  if (testing::HasSubstr(GetParam(), "https://")) {
    EXPECT_THAT(is_html, testing::Eq(true));
  } else {
    EXPECT_THAT(is_html, testing::Eq(false));
  }
}

INSTANTIATE_TEST_SUITE_P(
  isHTML,
  MessageTest,
  testing::Values(
    std::string("<a href=\"https://www.example.com\">Link</a>"),
    std::string("This is plain text, no HTML."),              
    std::string("<a href=\"http://www.example.com\">Link</a>"),   
    std::string("<a href=\"not a valid url\">Link</a>")     
  ),
  [](const testing::TestParamInfo<std::string>& info) {
    return info.param;
  }
);
