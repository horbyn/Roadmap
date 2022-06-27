# CH1 Getting started

## Exer 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

**naming convention**: .cpp  
**compiling rule**: g++ -std=c++11 test.cpp -o test

<br></br>

## Exer 1.2

> Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

[run exer1-2.sh](exer1-2.sh)

<br></br>

## Exer 1.3

> Write a program to print Hello, World on the standard output.

[run exer1-3.sh](exer1-3.sh)

<br></br>

## Exer 1.4

> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

[run exer1-4.sh](exer1-4.sh)

<br></br>

## Exer 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand

[run exer1-5.sh](exer1-5.sh)

<br></br>

## Exer 1.6

> Explain whether the following program fragment is legal.
> ```cpp
> std::cout << "The sum of " << v1;
>           << " and " << v2;
>           << " is " << v1 + v2 << std::endl
> ```
> If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?

- ILLEGAL. There is no ostream object on the left of `<<` operator

<br></br>

## Exer 1.7

> Compile a program that has incorrectly nested comments

[run exer1-7.sh](exer1-7.sh)

<br></br>

## Exer 1.8

> Indicate which, if any, of the following output statements are legal:
> ```cpp
> std::cout << "/*";
> std::cout << "*/";
> std::cout << /* "*/" */;
> std::cout << /* "*/" /* "/*" */;
> ```
> After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.

- Line 1: correct
- Line 2: correct
- Line 3: incorrect
- Line 4: correct

[run exer1-8.sh](exer1-8.sh)

<br></br>

## Exer 1.9

> Write a program that uses a while to sum the numbers from 50 to 100.

[run exer1-9.sh](exer1-9.sh)

<br></br>

## Exer 1.10

> In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.

[run exer1-10.sh](exer1-10.sh)

<br></br>

## Exer 1.11

> Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

[run exer1-11.sh](exer1-11.sh)

<br></br>

## Exer 1.12

> What does the following for loop do? What is the final value of sum?
> ```cpp
> int sum = 0;
> for (int i = -100; i <= 100; ++i)
>     sum += i;
> ```

- accumulating the sum from -100 to 100, and the final is 0

<br></br>
