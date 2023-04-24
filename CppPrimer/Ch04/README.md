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