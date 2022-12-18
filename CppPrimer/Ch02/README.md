# CH2

## Exer 2.1

> What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?

- Difference between `int`, `long`, `long long` and `short`: The length
- Difference between `unsigned` and `signed`: Whether the topest bit belong to the data itself
- Difference between `float` and `double`: The precision

<br></br>

## Exer 2.2

>  To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

- Double. I need higer precision.

<br></br>

## Exer 2.3

> What output will the following code produce?
> unsigned u = 10, u2 = 42;
> std::cout << u2 - u << std::endl;
> std::cout << u - u2 << std::endl;
> int i = 10, i2 = 42;
> std::cout << i2 - i << std::endl;
> std::cout << i - i2 << std::endl;
> std::cout << i - u << std::endl;
> std::cout << u - i << std::endl; 

- Logically
    + `u2 - u`: 32
    + `u - u2`: 4,294,967,264
    + `i2 - i`: 32
    + `i - i2`: -32
    + `i - u`: 0
    + `u - i`: 0
- Actually ([run exer2-4.sh](./exer2-4.sh))
    + `u2 - u`: 32
    + `u - u2`: 4294967264
    + `i2 - i`: 32
    + `i - i2`: -32
    + `i - u`: 0
    + `u - i`: 0

<br></br>

## Exer 2.4

> Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.

[run exer2-4.sh](exer2-4.sh)

<br></br>

## Exer 2.5

> Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:
> (a) 'a', L'a', "a", L"a"
> (b) 10, 10u, 10L, 10uL, 012, 0xC
> (c) 3.14, 3.14f, 3.14L
> (d) 10, 10u, 10., 10e-2

- **group 1**: `'a'` is a character while `L'a'` is a wide character; `"a"` is a character array which ending with 0, and `L"a"` is the wide version
- **group 2**: `10` is a decimal `int`, `10u` is a decimal `unsigned int`, `10L` is a decimal `long`, `10uL` is a decimal `unsigned long`, `012` is a octal `int`, and `0xC` is a hex `int`
- **group 3**: `3.14` is a `double`, `3.14f` is a `float`, and `3.14L` is a `long double`
- **group 4**: `10` is a decimal `int`, `10u` is a decimal `unsigned int`, `10.` is a `double`, and `10e-2` is a `double`

<br></br>

## Exer 2.6

> What, if any, are the differences between the following definitions:
> int month = 9, day = 7;
> int month = 09, day = 07;

- line 1 defines two decimal `int` while line 2 two octal `int` which the `09` exceeding range of octal is incorrently


<br></br>

## Exer 2.7

> What values do these literals represent? What type does each have?
> (a) "Who goes with F\145rgus?\012"
> (b) 3.14e1L
> (c) 1024f
> (d) 3.14L

- **a**: ~~a string printed *"Who goes with F101rgus?10"*~~**(`\145` is `'e'` and `\012` is `'LF'`, so the string is *"Who goes with Fergus?"*)**, and its type is char array
- **b**: a `double long` with value 3.14 * 10<sup>1</sup>
- **c**: ~~a `float` witch value 1024.0~~**(an integer cannot follow by suffix `f`, hence, that changing to `1024.f` is corrent)**
- **d**: a `double long` with value 3.14

<br></br>

## Exer 2.8

> Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.

[run exer2-8.sh](exer2-8.sh)

<br></br>

## Exer 2.9

> Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.
> (a) std::cin >> int input_value;
> (b) int i = { 3.14 };
> (c) double salary = wage = 9999.99;
> (d) int i = 3.14

- **a**: incorrently, the operand at the right side of `>>` must be a object. Correct version is:
    + ```cpp
      int input_value;
      std::cin >> input_value;
      ```
- **b**: ~~incorrently, the compiler will report an error that it is not allow to convert a `double` to `int`~~**(warnning, to do so will cause all the decimals miss)**. Corrent version is:
    + ```cpp
      int i = { 3 };
      ```
- **c**: incorrently, `wage` is not exist when assign to `salary`. Corrent version is:
    + ```cpp
      double wage = 9999.99, salary = wage;
      ```
- **d**: ~~corrently~~**(warnning, as same as `b)` )**

<br></br>

## Exer 2.10

> What are the initial values, if any, of each of the following variables?
> ```cpp
> std::string global_str;
> int global_int;
> int main()
> {
>     int local_int;
>     std::string local_str;
> }
> ```

- **global_str** is null string(i.e. `""`)
- **global_int** is 0
- **local_int** is undefined
- **local_str** ~~is undefined~~**(is null string, because it is a STL class type which has its default value)**

<br></br>

## Exer 2.11

> Explain whether each of the following is a declaration or a definition:
> (a) extern int ix = 1024;
> (b) int iy;
> (c) extern int iz;

- **a**: definition
- **b**: definition
- **c**: declaration

<br></br>

## Exer 2.12

> Which, if any, of the following names are invalid?
> (a) int double = 3.14;
> (b) int _;
> (c) int catch-22;
> (d) int 1_or_2 = 1;
> (e) double Double = 3.14;

- (a), ~~(b)~~**(c, cannot appear `-`)**, (d) are invalid

<br></br>

## Exer 2.13

> What is the value of j in the following program?
> ```cpp
> int i = 42;
> int main()
> {
>     int i = 100; int j = i;
> }
> ```

- j is 100

<br></br>

## Exer 2.14

> Is the following program legal? If so, what values are printed?
> ```cpp
> int i = 100, sum = 0;
> for (int i = 0; i != 10; ++i)
>     sum += i;
> std::cout << i << " " << sum << std::endl;
> ```

- legally, and it will print `"100 45"`

<br></br>

## Exer 2.15

> Which of the following definitions, if any, are invalid? Why?
> (a) int ival = 1.01;
> (b) int &rval1 = 1.01;
> (c) int &rval2 = ival;
> (d) int &rval3;

- (b) invalid: must bound to an object
- (d) invalid: must be assigned during initialization

<br></br>

## Exer 2.16

> Which, if any, of the following assignments are invalid? If they are valid, explain what they do.
> `int i = 0, &r1 = i; double d = 0, &r2 = d;`
> (a) r2 = 3.14159;
> (b) r2 = r1;
> (c) i = r2;
> (d) r1 = d;

- **(a):** valid, assign `3.14159` to `r2` which is equal to assign to `d`
- **(b):** ~~invalid~~(**valid, that is equal to assign `i` to `d`**)
- **(c):** valid, assign `r2` to `i` that will lose precision
- **(d):** valid, assign `d` to `r1` which is equal to assign to `i`. But there will lose precision

<br></br>

## Exer 2.17

> What does the following code print?
> ```cpp
> int i, &ri = i;
> i = 5; ri = 10;
> std::cout << i << " " << ri << std::endl;
> ```

- `10 10`

<br></br>

## Exer 2.18

> Write code to change the value of a pointer. Write code to change the value to which the pointer points.

[run exer2-18.sh](exer2-18.sh)

<br></br>

## Exer 2.19

> Explain the key differences between pointers and references.

- Assignment: pointers can reassign but references cannot
- Initialization: pointers need not but references must

<br></br>

## Exer 2.20

> What does the following program do?
> ```cpp
> int i = 42;
> int *p1 = &i;
> *p1 = *p1 * *p1;
> ```

- `i` is `42` * `42`

<br></br>

## Exer 2.21

> Explain each of the following definitions. Indicate whether any are illegal and, if so, why.
> ```cpp
> int i = 0;
> ```
> (a) double* dp = &i;
> (b) int *ip = i;
> (c) int *p = &i;

- `(a)` illegal, a `double` pointer cannot be assigned with an `int` object
- `(b)` illegal, an `int` 0 cannot assign to any pointer
- `(c)` legal

<br></br>

## Exer 2.22

> Assuming p is a pointer to int, explain the following code:
> if (p) // ...
> if (*p) // ...

- if pointer `p` is ~~not a empty pointer~~ **valid**
- if the object `p` pointed to is not zero

<br></br>

## Exer 2.23

> Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

- sure, `if (p)` can do so.

<br></br>

## Exer 2.24

> Why is the initialization of p legal but that of lp illegal?

- ~~type is not match~~ p is `void *` which accepts all type; while lp is `long *` that cannot accept `int`

<br></br>

## Exer 2.25

> Determine the types and values of each of the following variables.
> (a) int* ip, i, &r = ip;
> (b) int i, *ip = 0;
> (c) int* ip, ip2;

- pointer, `int` object, reference
- `int` object, pointer
- pointer, `int` object

<br></br>

## Exer 2.26

> Which of the following are legal? For those that are illegal, explain why.
> (a) const int buf;
> (b) int cnt = 0;
> (c) const int sz = cnt;
> (d) ++cnt; ++sz;

- `(a)` illegal, `const int` must be initialized
- `(b)` legal
- `(c)` legal
- `(d)` illegal, `sz` is not allowed to amend

<br></br>

## Exer 2.27

> Which of the following initializations are legal? Explain why.
> (a) int i = -1, &r = 0;
> (b) int *const p2 = &i2;
> (c) const int i = -1, &r = 0;
> (d) const int *const p3 = &i2;
> (e) const int *p1 = &i2;
> (f) const int &const r2;
> (g) const int i2 = i, &r = i;

- `(a)` illegal, `r` is a non-const variable that cannot be initialized with literal
- `(b)` legal, `p2` is const pointer that can be initialized with const
- `(c)` legal, `r` is a reference to const that can be initialized with literal
- `(d)` legal, `p3` is a const pointer to const that can be initialized with const
- `(e)` legal, `p1` is a reference to const that can be initialized with const
- `(f)` illegal, `r2` is a const that must be initialized
- `(g)` legal, `r` is a reference to const that can be initialized with non-const

<br></br>

## Exer 2.28

> Explain the following definitions. Identify any that are illegal.
> (a) int i, *const cp;
> (b) int *p1, *const p2;
> (c) const int ic, &r = ic;
> (d) const int *const p3;
> (e) const int *p;

- `(a)` illegal, `cp` is a const pointer, so it must be initialized
- `(b)` illegal, `p2` is a const pointer that must be initialized
- `(c)` ~~legal~~ **illegal, `ic` is const that must be initialized**
- `(d)` illegal, `p3` is a const pointer to const that must be initialized
- `(e)` legal, `p` is a reference to const

<br></br>

## Exer 2.29

> Uing the variables in the previous exercise, which of the following assignments are legal? Explain why.
> (a) i = ic;
> (b) p1 = p3;
> (c) p1 = &ic;
> (d) p3 = &ic;
> (e) p2 = p1;
> (f) ic = *p3;

- `(a)` legal, const can be assigned to non-const
- `(b)` ~~legal, const can be assigned to non-const~~ **illegal, non-const pointer is not allow to point to const**
- `(c)` illegal, non-const pointer cannot point to const
- `(d)` illegal, `p3` is const that cannot be reassigned
- `(e)` illegal, `p2` is const too
- `(f)` illegal, `ic` is const too

<br></br>

## Exer 2.30

> For each of the following declarations indicate whether the object being declared has top-level or low-level const.
> ```cpp
> const int v2 = 0; int v1 = v2;
> int *p1 = &v1, &r1 = v1;
> const int *p2 = &v2, *const p3 = &i, &r2 = v2;
> ```

- `v2`: top-level const
- `v1`/`p1`/`r1`: neither nor
- `p2`: low-level const
- `p3`: ~~low-level const~~ **top-level const**
- `r2`: low-level const

<br></br>

## Exer 2.31

> Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.
> ```cpp
> r1 = v2;
> p1 = p2; p2 = p1;
> p1 = p3; p2 = p3;
> ```

- `r1 = v2`: the left is `int &` while the right is `const int`, ~~illegal, low-level const cannot be assigned to non-const~~ **legal, the right is top-level const that can be assigned**
- `p1 = p2`: the left is `int *` and the right is `const int *`, illegal, low-level const cannot be assigned to non-const
- `p2 = p1`: the left is `const int *` and the right is `int *`, legal
- `p1 = p3`: the left is `int *` and the right is `const int *const`, illegal, low-level const cannot be assigned to non-const
- `p2 = p3`: the left is `const int *` and the right is `const int *const`, legal

<br></br>

## Exer 2.32

> Is the following code legal or not? If not, how might you make it legal?
> ```cpp
> int null = 0, *p = null;
> ```

- ~~legal~~ **illegal, `null` is a variable, `p` is a pointer, this should modify to `p = &null`**

<br></br>

## Exer 2.33

> Using the variable definitions from this section, determine what happens in each of these assignments:
> a = 42; b = 42; c = 42;
> d = 42; e = 42; g = 42;

- `a` is `int`, legal
- `b` is `int`, legal
- `c` is `int`, legal
- `d` is `int *`, illegal **, becanse d cannot be assigned with a literal**
- `e` is `const int *`, illegal**, becanse d cannot be assigned with a literal**
- `g` is `const int &`, ~~legal~~ **illegal, g binds to const which cannot be reassigned**

<br></br>

## Exer 2.34

> Write a program containing the variables and assignments from the previous exercise. Print the variables before and after the assignments to check whether your predictions in the previous exercise were correct. If not, study the examples until you can convince yourself you know what led you to the wrong conclusion.

- SKIP

<br></br>

## Exer 2.35

> Determine the types deduced in each of the following definitions. Once you’ve figured out the types, write a program to see whether you were correct.
> ```cpp
> const int i = 42;
> auto j = i; const auto &k = i; auto *p = &i;
> const auto j2 = i, &k2 = i;
> ```

**NOTE: I suspect the answer is wrong**

- `j`: int
- `k`: const int
- `p`: const int *
- `j2`: const int
- `k2`: const int

<br></br>

## Exer 2.36

> In the following code, determine the type of each variable and the value each variable has when the code finishes:
> ```cpp
> int a = 3, b = 4;
> decltype(a) c = a;
> decltype((b)) d = a;
> ++c;
> ++d;
> ```

- `a` is `int` that is 4
- `b` is `int` that is 4
- `c` is `int` that is 4
- `d` is `int &` that is 4 

<br></br>

## Exer 2.37

> Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if i is an int, then the type of the expression i = x is int&. Using that knowledge, determine the type and value of each variable in this code:
> ```cpp
> int a = 3, b = 4;
> decltype(a) c = a;
> decltype(a = b) d = a;
> ```

- `a` is `int` that is 3
- `b` is `int` that is 4
- `c` is `int` that is 3
- `d` is `int &` that is 3 

<br></br>

## Exer 2.38

> 2.38: Describe the differences in type deduction between decltype and auto. Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.

- Background:
    + `int i = 10;`
- Same(both are `int`):
    + `auto aa = i;`
    + `decltype(i) da;`
- Difference(`auto` is `int` while `decltype()` is `int &`)
    + `auto ab = (i);`
    + `decltype((i)) db;`

<br></br>

## Exer 2.39

> Compile the following program to see what happens when you forget the semicolon after a class definition. Remember the message for future reference.
> ```cpp
> struct Foo { /* empty */ } // Note: no semicolon
> int main()
> {
>  return 0;
> }
> ```

- SKIP

<br></br>

## Exer 2.40

> Write your own version of the Sales_data class.

- SKIP

<br></br>

## Exer 2.41

> Use your Sales_data class to rewrite the exercises in §1.5.1 (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your Sales_data class in the same file as your main function.

- SKIP

<br></br>

## Exer 2.42

> Write your own version of the Sales_data.h header and use it to rewrite the exercise from § 2.6.2 (p. 76).

- SKIP

<br></br>
