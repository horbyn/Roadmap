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
