#ifndef NODE_IMPL_HPP
#define NODE_IMPL_HPP

#include "node.hpp"

class Element : public Node {
public:
    explicit Element(char data);
	~Element() override;
	Node* get_next() const override;
	char get_data() const override;
	void update_next(Node* new_next) override;

private:
	char _data;
	Node* _next;
};

#endif