#include <vector>
#include <tuple>
#include <map>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "message_content.hpp"


std::vector<std::tuple<std::string, std::pair<std::string, bool>>> test_data = {
  {"Correct", {"https://www.example.com", true}},
  {"Plain", {"Plain text", false}},
  {"Incorrect", {"http example", false}}
};

std::map<std::string, std::pair<std::string, bool>> input_data = {
  {"Correct", {"https://www.example.com", true}},
  {"Plain", {"Plain text", false}},
  {"Incorrect", {"http example", false}}
};

// using vector
class MessageTest : public testing::TestWithParam<
  std::tuple<std::string, std::pair<std::string, bool>>> {};

/*
// using map
class MessageTest : public testing::TestWithParam<
  std::pair<std::string, std::pair<std::string, bool>>> {};
*/

INSTANTIATE_TEST_SUITE_P(
    isHTML,
    MessageTest,
    testing::ValuesIn(test_data), // ew. input_data for map
    [](const testing::TestParamInfo<MessageTest::ParamType> &info) {
      return std::get<0>(info.param);
    }
);

TEST_P(MessageTest, is_message_html_test) {
  auto p = GetParam();
  Message mess = Message(std::get<1>(p).first);

  bool is_html = mess.isMessageHTML();

  ASSERT_THAT(mess.getMessage(), testing::TypedEq<std::string>(std::get<1>(p).first));
  // EXPECT_THAT(mess.getMessage(), testing::AllOf(testing::HasSubstr("https"), testing::HasSubstr("//")));
  EXPECT_THAT(is_html, testing::Eq(std::get<1>(p).second));
}

/*
TEST_P(MessageTest, get_message_test) {
  auto p = GetParam();
  Message mess = Message(std::get<1>(p).first);

  std::vector<Message> mess_vec = {
    Message(std::get<1>(p).first),
    Message(std::get<1>(p).first),
    Message(std::get<1>(p).first)
  };

  std::string mess_cnt = mess.getMessage();

  EXPECT_THAT(mess_vec, testing::UnorderedElementsAre(
    testing::Field(&Message::message_cnt, mess_cnt),
    testing::Field(&Message::message_cnt, mess_cnt),
    testing::Field(&Message::message_cnt, mess_cnt)
  ));
}
*/

TEST_P(MessageTest, get_message_test) {
  auto p = GetParam();
  Message mess = Message(std::get<1>(p).first);

  std::vector<Message> mess_vec = {
    Message(std::get<1>(p).first),
    Message(std::get<1>(p).first),
    Message(std::get<1>(p).first)
  };

  std::string mess_cnt = mess.getMessage();

  /*
  Allows to check what lays inside a property that is a particular method
  */
  EXPECT_THAT(mess_vec, testing::UnorderedElementsAre(
    testing::Property(&Message::getMessage, mess_cnt),
    testing::Property(&Message::getMessage, mess_cnt),
    testing::Property(&Message::getMessage, mess_cnt)
  ));
}
