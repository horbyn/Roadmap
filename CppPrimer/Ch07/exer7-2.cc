#include <iostream>
#include <string>

class Sales_data {
private:
    std::string bookNo_;
    unsigned units_sold_;   // saled amount
    double sellingprice_;   // original price
    double saleprice_;      // actual price
    double discount_;       // discount

public:
    friend std::istream &operator>>(std::istream &in, Sales_data &sd) {
        in >> sd.bookNo_ >> sd.units_sold_ >> sd.sellingprice_
            >> sd.saleprice_ >> sd.discount_;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const Sales_data &sd) {
        out << "book no.: " << sd.bookNo_
            << "\nunits sold: " << sd.units_sold_
            << "\nselling price: " << sd.sellingprice_
            << "\nsale price: " << sd.saleprice_
            << "\ndiscount: " << sd.discount_;
        return out;
    }
    std::string isbn() const { return this->bookNo_; }
    Sales_data &combine(const Sales_data &rhs) {
        this->units_sold_ += rhs.units_sold_;
        this->saleprice_ = (rhs.saleprice_ * rhs.units_sold_
            + this->saleprice_ * this->units_sold_)
            / (rhs.units_sold_ + this->units_sold_);

        if (this->sellingprice_ != 0)
            this->discount_ = this->saleprice_ / this->sellingprice_;
        return *this;
    }
};

int
main(void) {
    Sales_data data1, data2;
    std::cin >> data1 >> data2;

    if (data1.isbn() == data2.isbn()) {
        data1.combine(data2);
        std::cout << data1 << std::endl;
    }

    return 0;
}
