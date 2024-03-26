#ifndef STACK_IMPL_HPP
#define STACK_IMPL_HPP

#include <iostream>

#include "stack.hpp"
#include "node_impl.hpp"


class StackImpl : public Stack {
public:
    explicit StackImpl();
    ~StackImpl() override;
    void push(char data);
    void pop();
    bool isEmpty() const;
    char top() const;

private:
    Node* _head;
};

#endif