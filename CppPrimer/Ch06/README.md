# CH6

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

> Compile the version of str_subrange as presented on page 223 to see what your compiler does with the indicated errors.

- `error: return-statement with no value, in function returning ‘bool’ [-fpermissive]`

<br></br>

## 6.31

> When is it valid to return a reference? A reference to `const`?

- returning a reference of local variable is invalid; **returning a reference to `const` when we do not want it be revised**

<br></br>

## 6.32

> Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.
> ```cpp
> int &get(int *arry, int index) { return arry[index]; }
> int main() {
>     int ia[10];
>     for (int i = 0; i != 10; ++i)
>         get(ia, i) = i;
> }
> ```

- legal, it assigns each element of the array

<br></br>

## 6.33

> Write a recursive function to print the contents of a `vector`.

```cpp
// `idx` begins with 0
void
print_vector_recursive(const std::vector<int > &v, int idx) {
    if (idx >= v.size())    return;

    std::cout << v[idx] << " ";
    print_vector_recursive(v, idx + 1);
}
```

<br></br>

## 6.34

> What would happen if the stopping condition in `factorial` were `if (val != 0)`

- ~~it's ok~~ **will cause bug if the parameter passed is negative**

<br></br>

## 6.35

> In the call to `fact`, why did we pass `val - 1` rather than `val--`?

- `val--` will use the previous value first then change

<br></br>

## 6.36

> Write the declaration for a function that returns a reference to
an array of ten `string`s, `decltype`, or a type alias.

`std::string (&(f(void)))[10];`

<br></br>

## 6.37

> Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use `decltype`. Which form do you prefer and why?

- type alias
    ```cpp
    using arrT = std::string (&)[10];
    arrT func(void);
    ```
- trailing return
    `auto func(void) -> std::string (&)[10];`
- ~~`decltype()`~~
    ```cpp
    std::string arrs[10] = { ... };
    std::string (&arr_rs)[10] = arrs;
    decltype(arr_rs) func(void);
    ```

- **`decltype()`**
    ```cpp
    std::string arrs[10] = { ... };
    decltype(arrs) &func();
    ```

<br></br>

## 6.38

> Revise the `arrPtr` function on to return a reference to the array.

- `decltype(odd) &arrPtr(int i);`

<br></br>

## 6.39

> Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
> ```cpp
> (a) int calc(int, int);
>     int calc(const int, const int);
> (b) int get();
>     double get();
> (c) int *reset(int *); 
>     double *reset(double *);
> ```

- (a) receive two `const int` parameters and return `int` object. it is illegal because `int` could convert to `const int` which compiler ignored the top-level const
- (b) return `double` object. it is illegal too because it cannot overload by only different return type
- (c) receive `double` pointer and return `double` pointer. it is legal.

<br></br>

## 6.40

> Which, if either, of the following declarations are errors? Why?
> (a) `int ff(int a, int b = 0, int c = 0);`
> (b) `char *init(int ht = 24, int wd, char bckgrnd);`

- (b): ONLY the latter parameter could hold the defaults

<br></br>

## 6.41

> Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer’s intent? Why?
> `char *init(int ht, int wd = 80, char bckgrnd = ' ');`
> (a) `init();`
> (b) `init(24,10);`
> (c) `init(14, '*');`

- ~~none is illegal~~ **the first is illegal because parameter amount is not match**, but (c) maybe not match the intent that (c) passed a character likely to used to initialize the last parameter but not

<br></br>

## 6.42

> Give the second parameter of `make_plural` (§ 6.3.2, p. 224) a default argument of `'s'`. Test your program by printing singular and plural versions of the words `success` and `failure`.

- ~~the second?~~ **`std::string make_plural(size_t ctr, const std::string &word, const std::string &ending = "s")`**

<br></br>

## 6.43

> Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.
> (a) `inline bool eq(const BigInt&, const BigInt&) {...}`
> (b) `void putValues(int *arr, int size);`

- (a) ~~put in a source file because it is a definition~~ **put in a header because it is a inline function**
- (b) put in a header because it is a declaration

<br></br>

## 6.44

> Rewrite the `isShorter` function from § 6.2.2 (p. 211) to be `inline`.

```cpp
inline bool
isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}
```

<br></br>

## 6.45

> Review the programs you’ve written for the earlier exercises and decide whether they should be defined as `inline`. If so, do so. If not, explain why they should not be `inline`.

- the previous one should do, because the program is short with simple feature

<br></br>

## 6.46

> Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

- no, because `s1` and `s2` ~~is variable not const~~ **cannot be merged with a `const` expression with `operator()` and `<` of the standard library**

<br></br>

## 6.47

> Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that used recursion to print the contents of a `vector` to conditionally print information about its execution. For example, you might print the size of the `vector` on each call. Compile and run the program with debugging turned on and again with it turned off.

- SKIP

<br></br>

## 6.48

> Explain what this loop does and whether it is a good use of `assert`:
> ```cpp
> string s;
> while (cin >> s && s != sought) { } // empty body
> assert(cin);
> ```

- not good. ~~Because `cin` is always null when break the `while()` loop~~ **There are two thing to let the control flow breaks the `while()` loop: the first is `cin` to be null and another is `s != sought`. The former happened by user's terminating, then program terminates by `assert()`, which is not reasonable**

<br></br>

## 6.49

> What is a candidate function? What is a viable function?

- SKIP

<br></br>

## 6.50

> Given the declarations for f from page 242, list the viable
functions, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.
> (a) `f(2.56, 42)`
> (b) `f(42)`
> (c) `f(42, 0)`
> (d) `f(2.56, 3.14)`

- (a) illegal, ambiguous
- (b) legal, call `void f(int);`
- (c) legal, call `void f(int, int);`
- (d) legal, call `void f(double, double = 3.14);`

<br></br>

## 6.51

> Write all four versions of f. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.

- SKIP

<br></br>

## 6.52

> Given the following declarations,
> ```cpp
> void manip(int, int);
> double dobj;
> ```
> what is the rank (§ 6.6.1, p. 245) of each conversion in the following calls?
> (a) `manip('a', 'z');`
> (b) `manip(55.4, dobj);`

- (a) ~~level 4~~ **level 3**
- (b) level 4

<br></br>

## 6.53

> Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
> (a) `int calc(int&, int&);`
>     `int calc(const int&, const int&);`
> (b) `int calc(char*, char*);`
>     `int calc(const char*, const char*);`
> (c) `int calc(char*, char*);`
>     `int calc(char* const, char* const);`

<br></br>

## 6.54

> Write a declaration for a function that takes two `int` parameters and returns an `int`, and declare a `vector` whose elements have this function pointer type.

```cpp
int f(int, int);
std::vector<int (*)(int, int) > v;
```

<br></br>

## 6.55

> Exercise 6.55: Write four functions that add, subtract, multiply, and divide two `int` values. Store pointers to these values in your `vector` from the previous exercise.

```cpp
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { return a / b; }

v.emplace_back(add);
v.emplace_back(sub);
v.emplace_back(mul);
v.emplace_back(divi);
```

<br></br>

## 6.56

> Call each element in the `vector` and print their result.

[run exer6-56.sh](./exer6-56.sh)

<br></br>


