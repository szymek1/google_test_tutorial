#include "stack_utils.hpp"

/*
char* StackUtils::getReversed(StackImpl& stack, const char* word, int size) {
    char result[size];
    
    for (int i = 0; i < size; i++) {
        const char w = word[i];
        stack.push(w);
    }

    int j = 0;
    while (!stack.isEmpty()) {
        result[j] = stack.top();
        stack.pop();
        j++;
    }
    return result;
}
*/

std::string StackUtils::getReversed(StackImpl& stack, const char* word, int size) {
  std::string reversed;

  for (int i = 0; i < size; i++) {
    stack.push(word[i]); 
  }

  while (!stack.isEmpty()) {
    reversed += stack.top(); 
    stack.pop();              
  }

  return reversed;
}


bool StackUtils::checkParentheses(StackImpl& stack, char (&sentence)[], int size) {
    char open_bracket_01 = '(';
    char open_bracket_02 = '[';
    char open_bracket_03 = '{';

    char closed_bracket_01 = ')';
    char closed_bracket_02 = ']';
    char closed_bracket_03 = '}';

    for (int i = 0; i < size; i++) {
        const char s = sentence[i];
        if (s == open_bracket_01 || s == open_bracket_02 ||
        s == open_bracket_03) {
            stack.push(s);
        }
        if (s == closed_bracket_01) {
            if (stack.top() == open_bracket_01) {
                stack.pop();
            } else
                return false;
        } else if (s == closed_bracket_02) {
            if (stack.top() == open_bracket_02) {
                stack.pop();
            } else
                return false;
        } else if (s == closed_bracket_03) {
            if (stack.top() == open_bracket_03) {
                stack.pop();
            } else
                return false;
        }
    }
    return stack.isEmpty();
}