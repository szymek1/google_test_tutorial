#ifndef NODE_HPP
#define NODE_HPP

class Node {
public:
	virtual ~Node() = default;
	virtual Node* get_next() const = 0;
	virtual char get_data() const = 0;
	virtual void update_next(Node* new_next) = 0;

private:
	char _data;
	Node* _next;
};

#endif
