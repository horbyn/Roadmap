# CH7

## 7.1

> Write a version of the transaction-processing program from § 1.6 (p. 24) using the `Sales_data` class you defined for the exercises in § 2.6.1 (p. 72).

[run exer7-1.sh](./exer7-1.sh)

<br></br>

## 7.2

> Add the `combine` and `isbn` members to the `Sales_data` class you wrote for the exercises in § 2.6.2 (p. 76).

[run exer7-2.sh](./exer7-2.sh)

<br></br>

## 7.3

> Revise your transaction-processing program from § 7.1.1 (p. 256) to use these members.

- SKIP

<br></br>

## 7.4

> Write a class named `Person` that represents the name and address of a person. Use a `string` to hold each of these elements. Subsequent exercises will incrementally add features to this class.

[run exer7-4.sh](./exer7-4.sh)

<br></br>

## 7.5

> Provide operations in your `Person` class to return the name and address. Should these functions be `const`? Explain your choice.

- Yes, because that needs not to revise the orignal data

<br></br>

## 7.6

> Define your own versions of the `add`, `read`, and `print` functions.

- SKIP

<br></br>

## 7.7

> Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new functions.

- SKIP

<br></br>

## 7.8

> Why does `read` define its `Sales_data` parameter as a plain reference and `print` define its parameter as a reference to `const`?

Because `read()` used to revise the context of the specific object while `print()` only for reading which need not to be changed

<br></br>

## 7.9

> Add operations to `read` and `print` `Person` objects to the code you wrote for the exercises in § 7.1.2 (p. 260).

[run exer7-9.sh](./exer7-9.sh)

<br></br>

## 7.10

> What does the condition in the following `if` statement do?
> `if (read(read(cin, data1), data2))`

first read data from `cin` and stores into `data1`. If it done reading data from `cin` to `data2`, or break. The last, checking whether the previous operation is done, and this condition passes if yes.

<br></br>

## 7.11

> Add constructors to your `Sales_data` class and write a program to use each of the constructors.

- SKIP

<br></br>

## 7.12

> Move the definition of the `Sales_data` constructor that takes an `istream` into the body of the `Sales_data` class.

```cpp
// something likes this
XXClass::XXClass(std::istream &is, XXClass &rhs) {
    /* ... */
}
```

<br></br>

## 7.13

> Rewrite the program from page 255 to use the istream constructor.

- SKIP

<br></br>

## 7.14

> Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.

```cpp
// something likes this
XXClass::XXClass(): xxmember_(/* .. */) {}
```

<br></br>

## 7.15

> Add appropriate constructors to your `Person` class.

[run exer7-15.sh](./exer7-15.sh)

<br></br>

## 7.16

> What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a `public` specifier? What kinds should be `private`?

- No; Constructor and friends; Concrete data

<br></br>

## 7.17

> What, if any, are the differences between using `class` or `struct`?

- Almost no except the default access control

<br></br>

## 7.18

> What is encapsulation? Why is it useful?

- SKIP

<br></br>

## 7.19

> Indicate which members of your `Person` class you would declare as `public` and which you would declare as `private`. Explain your choice.

- All are `private` because they need not to be sensed by user

<br></br>

## 7.20

> When are friends useful? Discuss the pros and cons of using friends.

- To let external object to access

<br></br>

## 7.21

> Update your `Sales_data` class to hide its implementation. The programs you’ve written to use `Sales_data` operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.

- SKIP

<br></br>

## 7.22

> Update your `Person` class to hide its implementation.

[run exer7-15.sh](./exer7-15.sh)

<br></br>

## 7.23

> Write your own version of the `Screen` class.

```cpp
class Screen {
private:
    size_t cursor_;
    size_t height_;
    size_t width_;
    std::string contents_;
};
```

<br></br>

## 7.24

> Give your Screen class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.

```cpp
class Screen {
private:
    size_t cursor_;
    size_t height_;
    size_t width_;
    std::string contents_;

public:
    Screen() {}
    Screen(size_t h, size_t w) : cursor_(0), height_(h), width_(w), contents_(h * w, ' ') {}
    Screen(size_t h, size_t w, const char ch) : cursor_(0), height_(h), width_(w), contents_(h * w, ch) {}
};
```

<br></br>

## 7.25

> Can `Screen` safely rely on the default versions of copy and assignment? If so, why? If not, why not?

- Yes, this version is not involve some type of dynamic resource allcation

<br></br>

## 7.26

> Define `Sales_data::avg_price` as an `inline` function.

```cpp
inline double
Sales_data::avg_price() {
    /* .. */
}
```

<br></br>

## 7.27

> Add the `move`, `set`, and `display` operations version of `Screen`. Test your class by executing the following code:
> ```cpp
> Screen myScreen(5, 5, 'X');
> myScreen.move(4,0).set('#').display(cout);
> cout << "\n";
> myScreen.display(cout);
> cout << "\n";
> ```

<br></br>

## 7.28

> What would happen in the previous exercise if the return type of `move`, `set`, and `display` was Screen rather than `Screen&`?

- It is no effect to the original object

<br></br>

## 7.29

> Revise your `Screen` class so that `move`, `set`, and `display` functions return `Screen` and check your prediction from the previous exercise.

- SKIP

<br></br>

## 7.30

> It is legal but redundant to refer to members through the `this` pointer. Discuss the pros and cons of explicitly using the `this` pointer to access members.

- SKIP

<br></br>

## 7.31

> Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.

```cpp
class Y;
class X {
    Y *y_;
}
class Y {
    X x_;
}
```

<br></br>

## 7.32

> Define your own versions of `Screen` and `Window_mgr` in which `clear` is a member of `Window_mgr` and a friend of `Screen`.

```cpp
void Window_mgr::clear();

class Screen {
    friend void Window_mgr::clear();
};
```

<br></br>
