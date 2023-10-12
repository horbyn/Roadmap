# CH4

## 4.1

> What is the value returned by 5 + 10 * 20/2?

- 105

<br></br>

## 4.2

> Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
> ```cpp
> (a) *vec.begin()
> (b) *vec.begin() + 1
> ```

- `*(vec.begin())`
- ~~`*(vec.begin()) + 1`~~ **`(*(vec.begin())) + 1`**

<br></br>

## 4.3

> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

- SKIP

<br></br>

## 4.4

> Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.
> `12 / 3 * 4 + 5 * 15 + 24 % 4 / 2`

- `(((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2))`
    1. `((12 / 3) * 4)`
        1.1. `12 / 3 = 4`
        1.2. `4 * 4 = 16`
    2. `(5 * 15)`
        2.1. `5 * 15 = 75`
    3. `((24 % 4) / 2))`
        3.1. `24 % 4 = 0`
        3.2. `0 / 2 = 0`
    4. all
        4.1. `16 + 75 + 0 = 91`

[run exer4-4.sh](exer4-4.sh)

<br></br>

## 4.5

> Determine the result of the following expressions.
> ```cpp
> (a) -30 * 3 + 21 / 5
> (b) -30 + 3 * 21 / 5
> (c) 30 / 3 * 21 % 5
> (d) -30 / 3 * 21 % 4
> ```

- -86
- ~~-360~~ **-18**
- 0
- -2

<br></br>

## 4.6

> Write an expression to determine whether an int value is even or odd

- even: `if (val % 2 == 0)`
- odd: `else`

<br></br>

## 4.7

> What does overflow mean? Show three expressions that will overflow.

- overflow, that is a value out of the maximun value of the corresponding type
    + **suppose here is a 32 bit machine**
    + ~~`(~(unsigned char)0) + 1`~~ **int i = 2147483647 + 1**
    + ~~`(~(unsigned short)0) + 1`~~ **int j = -100000 * 300000**
    + ~~`(~(unsigned int)0) + 1`~~ **int k = 2015 * 2015 * 2015 * 2015**

<br></br>

## 4.8

> Explain when operands are evaluated in the logical AND, logical OR, and equality operators.

- ~~logical AND first, then is logical OR, and equality operators is the last~~ **logic AND/OR are evaluated the left operands first, then the right if the former result is unknown; the equality operators have no order**

<br></br>

## 4.9

> Explain the behavior of the condition in the following if:
> ```cpp
> const char *cp = "Hello World";
> if (cp && *cp)
> ```

- ~~check if `cp` is `nullptr` then the value `cp` pointed to~~ **check if `cp` is `nullptr` then if the value `cp` pointed to is null terminated**

<br></br>

## 4.10

> Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.

[run exer4-10.sh](exer4-10.sh)

<br></br>

## 4.11

> Write an expression that tests four values, `a`, `b`, `c`, and `d`, and ensures that a is greater than `b`, which is greater than `c`, which is greater than `d`

[run exer4-11.sh](exer4-11.sh)

<br></br>

## 4.12

>  Assuming `i`, `j`, and `k` are all ints, explain what `i != j < k` means.

- that execuates `j < k` fisrt and return the `bool` value `temp`
- then check `i != temp` which make `temp` to become the `int` value `1` or `0`; so check `i != 1` or `i != 0` finally

<br></br>

## 4.13

> What are the values of i and d after each assignment?
> ```cpp
> int i; double d;
> (a) d = i = 3.5;
> (b) i = d = 3.5;
> ```

- (a): `i` is 3 and `d` is 3.0
- (b): `d` is 3.5 and `i` is 3

<br></br>

## 4.14

> Explain what happens in each of the if tests:
> `if (42 = i) // ...`
> `if (i = 42) // ...`

- compilation error
- true forever

<br></br>

## 4.15

> The following assignment is illegal. Why? How would you correct it?
> ```cpp
> double dval; int ival; int *pi;
> dval = ival = pi = 0;
> ```

- `pi = 0`: it's illegal that a `int` value assigns to pointer
- `ival = pi`: a pointer assigns to `int` illegally too
- CORRENT:
    + `dval = ival = 0`
    + `pi = nullptr`

<br></br>

## 4.16

> Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
> ```cpp
> (a) if (p = getPtr() != 0)
> (b) if (i = 1024)
> ```

- `p` will be reassigned
    + CORRENT: `if (p = getPtr() != 0)`
- true forever
    + CORRENT: `if (i == 1024)`

<br></br>

## 4.17

> Explain the difference between prefix and postfix increment.

- prefix increment changes the operands first, then uses the changed objects to be the result
- postfix increment uses the object duplication to be the result to return, then changes the original objects

<br></br>

## 4.18

> What would happen if the while loop on page 148 that prints the elements from a vector used the prefix increment operator?

- That will skip the first element and print the first negative element

<br></br>

## 4.19

> Given that `ptr` points to an `int`, that `vec` is a `vector<int>`, and that `ival` is an `int`, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?
> (a) `ptr != 0 && *ptr++`
> (b) `ival++ && ival`
> (c) `vec[ival++] <= vec[ival]`

- a. ~~dereference the `ptr` if not null, then its value plus one~~ **Check whether `ptr` is not null first. If true check whether the value pointed to is not zero secondly. The last, if both true, move `ptr` backward that maybe is not valid if `ptr` is a individual integer**
- b. check whether `ival` is not equal of zero, then plus one, and then checks whether not zero again
- c. check if `vec[ival]` is not great of `vec[ival + 1]`

<br></br>

## 4.20

> Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.
> (a) `*iter++;`
> (b) `(*iter)++;`
> (c) `*iter.empty()`
> (d) `iter->empty();`
> (e) `++*iter;`
> (f) `iter++->empty();`

- a. legal, it dereferences `iter` which gains a character and ~~plus its value~~ **moves the iterator `iter` to next**
- b. ~~legal, like (a)~~ **illegal, the `std::string` object the iterator dereferenced has no member of post-plus operator**
- c. ~~illegal, the character the iterator dereferenced has no member of `empty()`~~ **illegal, `iter` combines with `empty()` because the privilege of dot is higher than the dereference, in result a complitation error that iterator object has no member of `empty()`**
- d. legal, it checks the current iterator `iter` is that a empty string
- e. ~~legal, like (a)~~ **illegal, like (b)**
- f. maybe not legal, it does such a thing that check `iter` is that empty first, then make `iter` points to the next. But it is illegal if `iter` is the last iterator which cannot move backward

<br></br>

## 4.21

> Write a program to use a conditional operator to find the elements in a `vector<int>` that have odd value and double the value of each such element.

[run exer4-21.sh](exer4-21.sh)

<br></br>

## 4.22

> Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more if statements. Which version do you think is easier to understand and why?

[run exer4-22.sh](exer4-22.sh)

<br></br>

## 4.23

> The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
> ```cpp
> string s = "word";
> string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
> ```

- **the string object combines with another string object first, then the new one compares with the character 's' which is illegal. Fix it as following**
  ```cpp
  string s = "word";
  string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
  ```

<br></br>

## 4.24

> Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.

- **the code `std::string finalgrade = (grade < 60) ? "fail" : (60 <= grade && grade <= 75) ? "low pass" : "pass";` is equal of the next one if it is left associative**
- **`std::string finalgrade = ((grade < 60) ? "fail" : (60 <= grade && grade <= 75)) ? "low pass" : "pass";`**

<br></br>

## 4.25

> What is the value of `~'q' << 6` on a machine with 32-bit `int`s and 8 bit `char`s, that uses Latin-1 character set in which 'q' has the bit pattern `01110001`?

- first the not operation is `1000_1110`
- then the extension of the 8 bit is `1111_1111 1111_1111 1111_1111 1000_1110`
- the last is left-shift operation, which is `1111_1111 1111_1111 1110_0011 1000_0000`
- **translation to 2's complement forgotten: `1000_0000 0000_0000 0001_1100 1000_0000`**

<br></br>

## 4.26

> In our grading example in this section, what would happen if we used `unsigned int` as the type for `quiz1`?

- ~~it is ok~~ **it is wrong in some machine used 16-bit to define `int`**

<br></br>

## 4.27

> What is the result of each of these expressions?
> `unsigned long ul1 = 3, ul2 = 7;`
> (a) `ul1 & ul2`
> (b) `ul1 | ul2`
> (c) `ul1 && ul2`
> (d) `ul1 || ul2`

- a. 3
- b. 7
- c. true
- d. true

<br></br>

## 4.28

> Write a program to print the size of each of the built-in types.

[run exer4-28.sh](exer4-28.sh)

<br></br>

## 4.29

> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
>
> ```cpp
> int x[10];
> int *p = x;
> cout << sizeof(x)/sizeof(*x) << endl;
> cout << sizeof(p)/sizeof(*p) << endl;
> ```

- `sizeof(x)/sizeof(*x)` is ten
- `sizeof(p)/sizeof(*p)` is two

<br></br>

## 4.30

> Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:
> (a) `sizeof x + y`
> (b) `sizeof p->mem[i]`
> (c) `sizeof a < b`
> (d) `sizeof f()`

- ~~`sizeof (x) + y`~~ **`sizeof (x + y)`**
- `sizeof (p->mem[i])`
- ~~`sizeof (a) < b`~~ **`sizeof (a < b)`**
- `sizeof (f())`

<br></br>

## 4.31

> The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators

- no changes

<br></br>

## 4.32

> Explain the following loop.
> ```cpp
> constexpr int size = 5;
> int ia[size] = {1,2,3,4,5};
> for (int *ptr = ia, ix = 0;
>     ix != size && ptr != ia+size;
>     ++ix, ++ptr) { /* ... */ }
> ```

- travesal each element of the array

<br></br>

## 4.33

> Using Table 4.12 (p. 166) explain what the following expression does:
> `someValue ? ++x, ++y : --x, --y`

- ~~syntax error: `?:` is given priority over `,`, so `someValue ? ++x` first, then the `,` operator encounters syntax error~~ **equal of `(someValue ? ++x, ++y : --x), --y`**

<br></br>

## 4.34

> Given the variable definitions in this section, explain what conversions take place in the following expressions:
> (a) `if (fval)`
> (b) `dval = fval + ival;`
> (c) `dval + ival * cval;`
> Remember that you may need to consider the associativity of the operators.

- a. `float` to `bool`
- b. all to `double`
- c. `char` converts to `int` in multiplication first, then `int` to `double`

<br></br>

## 4.35

> Given the following definitions,
> ```cpp
> char cval; int ival; unsigned int ui;
> float fval; double dval;
> ```
> identify the implicit type conversions, if any, taking place:
> (a) cval = 'a' + 3;
> (b) fval = ui - ival * 1.0;
> (c) dval = ui * fval;
> (d) cval = ival + fval + dval;

- a. `char a` converts to `int` and plus 3, then `int` converts to char again
- b. `int ival` converts to `double` to complete the multiplication, then `unsigned int ui` to `double` too, they do subtraction and truncate down to `float`
- c. `unsigned int ui` converts to `float` first, then the result of multiplication converts to `double`
- d. right side of assignment converts to `double`, then the result to `char`

<br></br>

## 4.36

> Assuming `i` is an `int` and `d` is a `double` write the expression `i *= d` so that it does integral, rather than floating-point multiplication.

```cpp
int i = 1;
double d = 2.1;
int iresult = i * reinterpret_cast<int>(d);
```

<br></br>

## 4.37

> Rewrite each of the following old-style casts to use a named cast:
> `int i; double d; const string *ps; char *pc; void *pv;`
> (a) `pv = (void *)ps;`
> (b) `i = int(*pc);`
> (c) `pv = &d;`
> (d) `pc = (char *) pv;`

- ~~`pv = const_cast<void * >(ps)`~~ **pv = static_cast<void * >(const_cast<string *>(ps))**
- `i = static_cast<int >(*pc)` or `i = reinterpret_cast<int >(*pc)`
- `pv = static_cast<void * >(&d)` or `pv = reinterpret_cast<void * >(&d)`
- `pc = static_cast<char * >(pv)` or `pc = reinterpret_cast<char * >(pv)`

<br></br>

## 4.38

> Explain the following expression:
> `double slope = static_cast<double>(j/i);`

- the division type converts to `double`

<br></br>
