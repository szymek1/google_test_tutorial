#ifndef MESSAGE_CONTENT_HPP
#define MESSAGE_CONTENT_HPP

#include <string>
#include <regex>


class Message {
public:
    explicit Message(const std::string& message_content);
    ~Message() = default;

    std::string getMessage() const;
    bool isMessageHTML() const;
    
private:
    std::string _message_content;
};

#endif
