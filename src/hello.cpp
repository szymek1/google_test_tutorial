#include "hello.hpp"


namespace utility {

Hello::Hello(const std::string& name, int age) : _name(name), _age(age) {}

std::string Hello::sayName() { return _name; }

int Hello::getAge() const { return _age; }

}