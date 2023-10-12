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
