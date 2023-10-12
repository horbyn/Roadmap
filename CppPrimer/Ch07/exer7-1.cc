#include <iostream>
#include <string>

class Sales_data {
private:
    std::string bookNo_;
    unsigned units_sold_;
    double revenue_;

public:
    friend std::istream &operator>>(std::istream &in, Sales_data &sd) {
        in >> sd.bookNo_ >> sd.units_sold_ >> sd.revenue_;
        return in;
    }
    std::string bookNo() const {
        return this->bookNo_;
    }
    void operator+=(const Sales_data &sd) {
        this->units_sold_ += sd.units_sold_;
        this->revenue_ += sd.revenue_;
    }
    friend std::ostream &operator<<(std::ostream &out, const Sales_data &sd) {
        out << "book no.: " << sd.bookNo_
            << "\nunits sold: " << sd.units_sold_
            << "\nrevenue: " << sd.revenue_;
        return out;
    }
};

int
main(void) {
    Sales_data total;
    if (std::cin >> total) {
        Sales_data trans;
        while (std::cin >> trans) {
            if (total.bookNo() == trans.bookNo())
                total += trans;
            else {
                std::cout << total << std::endl;
                total = trans;
            }
        } // end while()
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}
