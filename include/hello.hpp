#ifndef HELLO_HPP
#define HELLO_HPP

#include <string>

namespace utility {

class Hello {
public:
    explicit Hello(const std::string& name, int age);
    std::string sayName();
    int getAge() const;

private:
    std::string _name;
    int _age;
};

}

#endif