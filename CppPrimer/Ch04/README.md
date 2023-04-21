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


