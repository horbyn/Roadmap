#include <iostream>
#include <string>

class Screen {
private:
    size_t cursor_;
    size_t height_;
    size_t width_;
    std::string contents_;

public:
    Screen() {}
    Screen(size_t h, size_t w)
        : cursor_(0), height_(h), width_(w), contents_(h * w, ' ') {}
    Screen(size_t h, size_t w, const char ch)
        : cursor_(0), height_(h), width_(w), contents_(h * w, ch) {}

    Screen &move(size_t h, size_t w) {
        this->cursor_ = h * this->width_ + w;
        return *this;
    }

    Screen &set(const char ch) {
        this->contents_[this->cursor_] = ch;
        return *this;
    }

    const Screen &display(std::ostream &out) const {
        this->do_display(out);
        return *this;
    }

    Screen &dislpay(std::ostream &out) {
        this->do_display(out);
        return *this;
    }

private:
    void do_display(std::ostream &out) const {
        out << this->contents_;
    }
};

int
main(void) {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";

    return 0;
}
