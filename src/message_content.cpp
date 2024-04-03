#include "message_content.hpp"


Message::Message(const std::string& message_content) : 
    _message_content(message_content) {}

std::string Message::getMessage() const { 
  return _message_content; 
  }

bool Message::isMessageHTML() const {
  static const std::regex https_prefix_regex(R"(^https://)", std::regex::icase);
  
  return std::regex_search(_message_content, https_prefix_regex);
}
