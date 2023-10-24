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

## 7.33

> What would happen if we gave `Screen` a `size` member defined as follows? Fix any problems you identify.
> ```cpp
> pos Screen::size() const
> {
>     return height * width;
> }
> ```

- ~~return the copy of the product of these two~~ compilation error happened with non-visible scope

<br></br>

## 7.34

> What would happen if we put the `typedef` of `pos` in the `Screen` class on page 285 as the last line in the class?

- the member cannot see the `pos` type, which causes a compilation error

<br></br>

## 7.35

> Explain the following code, indicating which definition of `Type` or `initVal` is used for each use of those names. Say how you would fix any errors.
```cpp
typedef string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};
Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

- for `Type Exercise::setVal(Type parm);`, the parameter uses `double` type and the return value type uses `std::string`
- the first problem: `val = parm + initVal();` will truncate down the result
- the second problem: In `Type Exercise::setVal(Type parm)` function, the `val` is `int` in body then cast to `std::string` which is illeal

<br></br>

## 7.36

> The following initializer is in error. Identify and fix the problem.
> ```cpp
> struct X {
>     X (int i, int j): base(i), rem(base % j) { }
>     int rem, base;
> };
> ```

- the order of initialization is `rem` then `base`, so it is illegal that using `base` to assign to `rem` when the first initialization

> ```cpp
> struct X {
>     X (int i, int j): base(i), rem(base % j) { }
>     int base, rem;
> };
> ```

<br></br>

## 7.37

> Using the version of `Sales_data` from this section,
determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:
> ```cpp
> Sales_data first_item(cin);
> int main() {
>     Sales_data next;
>     Sales_data last("9-999-99999-9");
> }
> ```

- `Sales_data first_item(cin);` the third c'tor. ~~All member had the default~~ **depend on the user input on `std::cin`**
- `Sales_data next;`: the first c'tor. All member had the default
- `Sales_data last("9-999-99999-9")`: the first c'tor. Only the `bookNo` has the specified value, 9-999-99999-9

<br></br>

## 7.38

> We might want to supply `cin` as a default argument to the constructor that takes an `istream&`. Write the constructor declaration that uses `cin` as a default argument.

`T SOMECLASS(std::istream &is = {}) { is >> *this; }`

<br></br>

## 7.39

> Would it be legal for both the constructor that takes a
`string` and the one that takes an `istream&` to have default arguments? If not, why not?

- No, the compiler cannot find out the c'tor when the calling without any parameters

<br></br>

## 7.40

> Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.
> (a) Book
> (b) Date
> (c) Employee
> (d) Vehicle
> (e) Object
> (f) Tree

- SKIP

<br></br>

## 7.41

> Rewrite your own version of the `Sales_data` class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a `Sales_data` object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.

- SKIP

<br></br>

## 7.42

> For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

- SKIP

<br></br>

## 7.43

> Assume we have a class named `NoDefault` that has a constructor that takes an `int`, but has no default constructor. Define a class `C` that has a member of type `NoDefault`. Define the default constructor for `C`.

`C::C(int a = {}) : DnoDefault(a) {}`

<br></br>

## 7.44

> Is the following declaration legal? If not, why not?
> `vector<NoDefault> vec(10);`

- ~~Illegal, it seems to define a object, `vec`, which passes `10` as its parameter. But actually the right syntax is `vector<NoDefault> vec{10};`~~ **Illegal, its original meaning is to assign a vector with 10 elements, which each of them initializes default. But actually the `NoDefault` has no default c'tor**

<br></br>

## 7.45

> What if we defined the `vector` in the previous execercise to hold objects of type C?

- Yes

<br></br>

## 7.46

> Which, if any, of the following statements are untrue? Why?
> (a) A class must provide at least one constructor.
> (b) A default constructor is a constructor with an empty parameter list.
> (c) If there are no meaningful default values for a class, the class should not provide a default constructor.
> (d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.

- **A: wrong, compiler will provide if you do not**
- **B: wrong, some c'tor receiving default parameters could also act as default c'tor**
- ~~C is a little incorrent, the advantage of default c'tor is you don't need to specify values in initialization~~ **C: wrong, SHOULD provide a default because compiler may use for implicit initialization**
- **D: wrong, compiler will not provide default for the in-class data**

<br></br>

## 7.47

> Explain whether the `Sales_data` constructor that takes a `string` should be `explicit`. What are the constructor `explicit`? What are the drawbacks?

- Yes **Advantage is to avoid expection duration transferability while the drawback is fussy**

<br></br>

## 7.48

> Assuming the `Sales_data` constructors are not `explicit`, what operations happen during the following definitions
> ```cpp
> string null_isbn("9-999-99999-9");
> Sales_data item1(null_isbn);
> Sales_data item2("9-999-99999-9");
> ```
> What happens if the `Sales_data` constructors are `explicit`?

- not explicit: all of them is legal
- ~~explicit: only the first one legal~~ **explicit: like above**

<br></br>

## 7.49

> For each of the three following declarations of `combine`, explain what happens if we call `i.combine(s)`, where `i` is a `Sales_data` and `s` is a `string`:
> (a) `Sales_data &combine(Sales_data);`
> (b) `Sales_data &combine(Sales_data&);`
> (c) `Sales_data &combine(const Sales_data&) const;`

- a. construct a temp `Sales_data` object first, then passes to `combine()`
- b. error
- c. error

<br></br>

## 7.50

> Determine whether any of your `Person` class constructors should be `explicit`.

- SKIP

<br></br>

## 7.51

> Why do you think vector defines its single-argument constructor as explicit, but string does not?

- SKIP

<br></br>

## 7.52

> Using our first version of `Sales_data` from § 2.6.1 (p. 72), explain the following initialization. Identify and fix any problems.
> `Sales_data item = {"978-0590353403", 25, 15.99};`

- ~~No~~ **the previous definition of `Sales_data` which has in-class initialization will cause compilation error**

<br></br>

## 7.53

> Define your own version of `Debug`.

- SKIP

<br></br>

## 7.54

> Should the members of `Debug` that begin with `set_` be declared as `constexpr`? If not, why not?

- ~~Yes, should it the convention of literal type?~~ **No. the `set_` is use to setup the value of internal members; but `constexpr` function only includes `return` statement**

<br></br>

## 7.55

> Is the `Data` class from § 7.5.5 (p. 298) a literal class? If not, why not? If so, explain why it is literal.

- Yes, it is a aggregate class which is also a literal class

<br></br>

## 7.56

> What is a `static` class member? What are the advantages of `static` members? How do they differ from ordinary members?

- SKIP

<br></br>

## 7.57

> Write your own version of the `Account` class.

- SKIP

<br></br>

## 7.58

> Which, if any, of the following `static` data member declarations and definitions are errors? Explain why.
> ```cpp
> // example.h
> class Example {
> public:
>     static double rate = 6.5;
>     static const int vecSize = 20;
>     static vector<double> vec(vecSize);
> };
> // example.C 
> #include "example.h"
> double Example::rate;
> vector<double> Example::vec;
> ```

- Wrong, ~~`double Example::rate;` is redundant~~ **only static const members can in-class initialization; and must provide the initial value outside class initialization**

<br></br>
