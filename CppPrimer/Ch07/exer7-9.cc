#include <string>
#include <iostream>

class Person {
public:
    std::string name_;
    std::string addr_;

    friend std::istream &read(std::istream &is, Person &p) {
        is >> p.name_ >> p.addr_;
        return is;
    }

    friend std::ostream &print(std::ostream &os, const Person &p) {
        os << "name: " << p.name_
            << "\naddr: " << p.addr_;
        return os;
    }
};

int
main(void) {
    Person p{};
    read(std::cin, p);
    std::cout << std::endl;
    print(std::cout, p);
    std::cout << std::endl;

    return 0;
}
