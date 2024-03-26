#include "stack_impl.hpp"


StackImpl::StackImpl() : _head(nullptr) {}

StackImpl::~StackImpl() {
    Node* current = _head;

    while (current != nullptr) {
        Node* next_node = current->get_next();
        delete current;
        current = next_node;
    }
}

void StackImpl::push(char data) {
    Element* new_node = new Element(data);
    new_node->update_next(_head);
    _head = new_node;
}

void StackImpl::pop() {
    if (_head != nullptr) {
        Node* current = _head;
        Node* next_node = current->get_next();
        current->update_next(nullptr);
        delete current;
        _head = next_node;

    } else
        throw std::runtime_error("Stack is empty");
}

bool StackImpl::isEmpty() const {
    if (_head == nullptr) {
        return true;
    } else
        return false;
}

char StackImpl::top() const {
    if (!isEmpty()) { return _head->get_data(); } else {
        throw std::runtime_error("Cannot top empty stack");
    }
    
}