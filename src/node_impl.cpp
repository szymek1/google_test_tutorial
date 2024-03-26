#include "node_impl.hpp"


Element::Element(char data) : _data(data), _next(nullptr) {}

Element::~Element() {}

Node* Element::get_next() const {
    return _next;
}

char Element::get_data() const {
    return _data;
}

void Element::update_next(Node* new_next) {
    _next = new_next;
}