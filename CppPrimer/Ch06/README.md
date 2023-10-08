## 6.1

> What is the difference between a parameter and an argument?

- ~~I DO NOT KNOW~~ **parameters happen in function definition, while arguments in the calling of this function**

<br></br>

## 6.2

> Indicate which of the following functions are in error and why. Suggest how you might correct the problems.
> ```cpp
> (a) int f() {
>         string s;
>         // ...
>         return s;
>     }
> (b) f2(int i) { /* ... */ }
> (c) int calc(int v1, int v1) /* ... */ }
> (d) double square(double x) return x * x;
> ```

- (a) the return value's type is not match the function return type
- (b) no return type
- (c) no left bracket
- (d) no brackets

<br></br>

## 6.3

> Write and test your own version of fact.

- SKIP

<br></br>

## 6.4

> Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from `main`.

- SKIP

<br></br>

## 6.5

> Write a function to return the absolute value of its argument

[run exer6-5.sh](./exer6-5.sh)

<br></br>

## 6.6

> Explain the differences between a parameter, a local variable, and a local `static` variable. Give an example of a function in which each might be useful.

- SKIP

<br></br>

## 6.7

> Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.

- SKIP

<br></br>

## 6.8

> Write a header file named Chapter6.h that contains declarations for the functions you wrote for the exercises in § 6.1 (p. 205).

- SKIP

<br></br>

## 6.9

> Write your own versions of the `fact.cc` and `factMain.cc` files. These files should include your `Chapter6.h` from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

- SKIP

<br></br>

## 6.10

> Using pointers, write a function to swap the values of two `int`s. Test the function by calling it and printing the swapped values.

[run exer6-10.sh](./exer6-10.sh)

<br></br>

## 6.11

> Write and test your own version of `reset` that takes a reference.

- SKIP

<br></br>

## 6.12

> Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use references instead of pointers to swap the value of two `int`s. Which version do you think would be easier to use and why?

- SKIP

<br></br>

## 6.13

> Assuming `T` is the name of a type, explain the difference between a function declared as `void f(T)` and `void f(T&)`.

- `void f(T)`: arguments will not be changed in execution
- `void f(T&)`: arguments may be changed

<br></br>

## 6.14

> Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

- reference: when we will change some value such as the function of change two value
- non-reference: when we read only some value

<br></br>

## 6.15

> Explain the rationale for the type of each of `find_char`’s parameters In particular, why is `s` a reference to `const` but `occurs` is a plain reference? Why are these parameters references, but the `char` parameter `c` is not? What would happen if we made `s` a plain reference? What if we made `occurs` a reference to `const`?

- `s` is `const` because we use only to read its length; `char` and `c` is not because they are return value actually

<br></br>

## 6.16

> The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:
> `bool is_empty(string& s) { return s.empty(); }`

- change to `bool is_empty(const string& s) { return s.empty(); }`

<br></br>

## 6.17

> Write a function to determine whether a `string` contains any capital letters. Write a function to change a `string` to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?

- No. The former read only is ok while the latter must be revised

<br></br>

## 6.18

> Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.
> (a) A function named `compare` that returns a `bool` and has two parameters that are references to a class named `matrix`.
> (b) A function named `change_val` that returns a `vector<int>` iterator and takes two parameters: One is an int and the other is an iterator for a `vector<int>`.

- (a) ~~`bool compare(matrix &, matrix &);`~~ **`bool compare(const matrix &, const matrix &); // compare is read-only`**
- (b) ~~`std::vector<int > change_val(int, const std::vector<int >::iterator);`~~ **`std::vector<int > change_val(int, std::vector<int >::iterator); // change must be referenced`**

<br></br>

## 6.19

> Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.
> ```cpp
> double calc(double);
> int count(const string &, char);
> int sum(vector<int>::iterator, vector<int>::iterator, int);
> vector<int> vec(10);
> ```
> (a) `calc(23.4, 55.1)`;
> (b) `count("abcda", 'a')`;
> (c) `calc(66)`;
> (d) `sum(vec.begin(), vec.end(), 3.8)`;

- (a) illegal, because arguments amount is not match
- (b) legal
- (c) legal
- (d) ~~illegal, because the last argument is const that cannot be assigned to non-const~~ **legal**

<br></br>

## 6.20

> When should reference parameters be references to `const`? What happens if we make a parameter a plain reference when it could be a reference to `const`?

- when the reference parameters will not be revised in the function execution; That will narrow the function usage, which the const argument cannot be passed but before it can

<br></br>

## 6.21

> Write a function that takes an `int` and a pointer to an `int` and returns the larger of the `int` value or the value to which the pointer points. What type should you use for the pointer?

```cpp
int f(int, const int *); // we do not need to revise
```

<br></br>

## 6.22

> Write a function to swap two `int` pointers.

```cpp
void
swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

<br></br>

## 6.23

> Write your own versions of each of the `print` functions presented in this section. Call each of these functions to print `i` and `j` defined as follows:
> `int i = 0, j[2] = {0, 1};`

- SKIP

<br></br>

## 6.24

> Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.
> ```cpp
> void print(const int ia[10])
> {
>     for (size_t i = 0; i != 10; ++i)
>         cout << ia[i] << endl;
> }
> ```

- behavior: print all ten elements of the array
- problems: ~~maybe the array length is fixed?~~ **There parameter array's length is just a expected value which we want, while actually the array's length may not be catered 10, which will cause beyond the range**

<br></br>

## 6.25

> Write a `main` function that takes two arguments. Concatenate the supplied arguments and print the resulting `string`.

```cpp
int main(int argc, char **argv) {
    std::string str{};
    for (size_t i = 1; argv[i]; ++i) {
        str += argv[i];
    }
    std::cout << str << std::endl;

    return 0;
}
```

<br></br>

## 6.26

> Write a program that accepts the options presented in this section. Print the values of the arguments passed to `main`.

[run exer6-26.sh](./exer6-26.sh)

<br></br>

## 6.27

> Write a function that takes an `initializer_list<int>` and produces the sum of the elements in the list.

```cpp
int
get_sum(initializer_list<int > ls) {
    int sum = 0;
    for (auto it = ls.begin(); it != ls.end(); ++it)
        sum += *it;
    return sum;
}
```

<br></br>

## 6.28

> In the second version of `error_msg` that has an `ErrCode` parameter, what is the type of `elem` in the `for` loop?

- `const std::string &`

<br></br>

## 6.29

> When you use an `initializer_list` in a range `for` would you ever use a reference as the loop control variable? If so, why? If not, why not?

- i think yes or no is ok

<br></br>

## 6.30

>
