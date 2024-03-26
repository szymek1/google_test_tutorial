#ifndef STACK_UTILS_HPP
#define STACK_UTILS_HPP

#include <string>

#include "stack_impl.hpp"

class StackUtils {
public:
    StackUtils() = default;
    ~StackUtils() = default;

    static std::string getReversed(StackImpl& stack, const char* word, int size);
    static bool checkParentheses(StackImpl& stack, char (&sentence)[], int size);
};

#endif