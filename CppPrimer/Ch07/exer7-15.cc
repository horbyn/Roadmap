#include <string>
#include <iostream>

class Person {
private:
    std::string name_;
    std::string addr_;

public:
    Person() = default;
    Person(const std::string &name, const std::string &addr)
        : name_(name), addr_(addr) {}
    std::string get_name() const { return this->name_; }
    std::string get_addr() const { return this->addr_; }
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
    Person p1{};
    Person p2{ "Bob", "City A" };
    std::cout << "p1 info:" << std::endl;
    print(std::cout, p1);
    std::cout << std::endl << std::endl;
    std::cout << "p2 info:" << std::endl;
    print(std::cout, p2);
    std::cout << std::endl;

    return 0;
}
