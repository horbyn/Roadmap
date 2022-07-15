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
