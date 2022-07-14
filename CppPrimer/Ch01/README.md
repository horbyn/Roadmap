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

## Exer 1.13

>  Rewrite the exercises from § 1.4.1 (p. 13) using for loops

[run exer1-13.sh](exer1-13.sh)

<br></br>

## Exer 1.14

> Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?

- `for()` uses no temporary invarible while `while()` uses

<br></br>

## Exer 1.15

> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates

- skip

<br></br>

## Exer 1.16

> Write your own version of a program that prints the sum of a set of integers read from cin.

[run exer1-16.sh](exer1-16.sh)

<br></br>

## Exer 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

- All numbers are in one line. There are many lines with the count always 1.

<br></br>

## Exer 1.18

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

[run exer1-18.sh](exer1-18.sh)

<br></br>

## Exer 1.19

> Revise the program you wrote for the exercises in § 1.4.1 (p.13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

[run exer1-19.sh](exer1-19.sh)

<br></br>

## Exer 1.20

> http://www.informit.com/title/032174113 contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

[run exer1-20.sh](exer1-20.sh)

```shell
# input: 
0-201-70353-x 4 24.99
```

<br></br>

## Exer 1.21

> Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

[run exer1-21.sh](exer1-21.sh)

```shell
# input: 
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
```

<br></br>

## Exer 1.22

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

[run exer1-22.sh](exer1-22.sh)

```shell
# input: 
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
```

<br></br>

## Exer 1.23

> Write a program that reads several transactions and counts how many transactions occur for each ISBN.

[run exer1-23.sh](exer1-23.sh)

```shell
# input: 
0-201-78345-X occurs 3
0-201-78325-X occurs 6
0-201-78315-X occurs 3
0-201-78346-X occurs 2
0-201-78347-X occurs 1
0-201-79345-X occurs 1
```

<br></br>

## Exer 1.24

> Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

[run exer1-24.sh](exer1-24.sh)

```shell
# input: 
0-201-70353-X occurs 1
0-201-82470-1 occurs 1
0-201-88954-4 occurs 4
0-399-82477-1 occurs 2
0-201-78345-X occurs 2
```

<br></br>

## Exer 1.25

> Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this section

[run exer1-25.sh](exer1-25.sh)

```shell
# input: 
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22
```

<br></br>
