#ifndef STACK_HPP
#define STACK_HPP

#include "node.hpp"

class Stack {
public:
    virtual ~Stack() = default;
    virtual void push(char data) = 0;
    virtual void pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual char top() const = 0;

private:
    Node* _head;
};

#endif