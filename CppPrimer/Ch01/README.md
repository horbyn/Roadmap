# Chapter 1. Getting Started

## Exercise 1.1
> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.
* [GCC and File Extensions](http://labor-liber.org/en/gnu-linux/development/index.php?diapo=extensions)

```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_1 ex1_1.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_1
root@localhost:/mnt/CppPrimer/Ch01$ 
```

## Exercise 1.2
> Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and return your program to see how your system treats a failure indicator from main.
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_2 ex1_2.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_2
root@localhost:/mnt/CppPrimer/Ch01$ echo $?
255
```

## Exercise 1.3
> Write a program to print *Hello, World* on the standard output.
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_3 ex1_3.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_3
Hello, World
```

## Exercise 1.4
> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_4 ex1_4.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_4
Enter two numbers:
3 7
The product of 3 and 7 is 21
```

## Exercise 1.5
> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_5 ex1_5.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_5
Enter two numbers:
3 7
The product of 3 and 7 is 21
```

## Exercise 1.6
> Explain whether the following program fragment is legal.  
&#8195;std::cout << "The sum of " << v1;  
&#8195;&#8195;&#8195;&#8195;&#8195;<< " and " << v2;  
&#8195;&#8195;&#8195;&#8195;&#8195;<< " is " << v1 + v2 << std::endl;  
If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?
```cpp
    //Illegal, the left-hand operand of the << operator is not ostream object
```

## Exercise 1.7
> Compile a program that has incorrectly nested comments.
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_7 ex1_7.cpp
ex1_7.cpp:2:27: error: ‘cannot’ does not name a type
  * comment pairs /*    */ cannot nest.
                           ^~~~~~
```

## Exercise 1.8
> Indicate which, if any, of the following output statements are legal:  
&#8195;std::cout << "/\*";  
&#8195;std::cout << "\*/";  
&#8195;std::cout << /\* "\*/" \*/;  
&#8195;std::cout << /\* "\*/" /\* "/\*" \*/;  
After you've predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.
```cpp
    //line 1: legal.
    //line 2: legal.
    //line 3: illegal, because the right-hand of the << operator is not integrated.
    //line 4: legal.
```
line 1 legal
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_8 ex1_8.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_8
/*
```
line 2 legal
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_8 ex1_8.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_8
*/
```
line 3 illegal
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_8 ex1_8.cpp
ex1_8.cpp:6:24: warning: missing terminating " character
     std::cout << /* "*/" */;
                        ^
ex1_8.cpp:6:24: error: missing terminating " character
     std::cout << /* "*/" */;
                        ^~~~~
ex1_8.cpp: In function ‘int main()’:
ex1_8.cpp:8:5: error: expected primary-expression before ‘return’
     return 0;
     ^~~~~~
```
line 4 legal
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_8 ex1_8.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_8
 /* 
```

## Exercise 1.9
> Write a program that uses a *while* to sum the numbers from 50 to 100.
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_9 ex1_9.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_9
The sum of 50 to 100 inclusive is 3825
```

## Exercise 1.10
> In addition to the ++ operator that adds 1 to its operand, there is a decrement operator(--) that substracts 1. Use the decrement operator to write a *while* that prints the numbers from ten down to zero.
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_10 ex1_10.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_10
10 9 8 7 6 5 4 3 2 1 0 
```

## Exercise 1.11
> Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_11 ex1_11.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_11
Please input two number in order to print each number in the range specified by these two integers: 1 100
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100
```

## Exercise 1.12
> What does the following *for* loop do? What is the final value of *sum*?  
&#8195;int sum = 0;  
&#8195;for(int i = -100; i <= 100; ++i)  
&#8195;&#8195;sum += i;
```cpp
    // sum is 0.
```
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_12 ex1_12.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_12
0
```

## Exercise 1.13
> Rewrite the exercises from $1.4.1 (p. 13) using *for* loops.
```cpp
    // Take Exercise 1.11 as an example
```
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_11 ex1_11.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_11
Please input two number in order to print each number in the range specified by these two integers: 1 50
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 
```

## Exercise 1.14
> Compare and contrast the loops that used a *for* with those using a *while*. Are these advantages or disadvantages to using either form?
```cpp
    // for() is used for explicit cycle; while() is used for unexplicit cycle
```

## Exercise 1.15
> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.
```cpp
    // Declaration errors: cout not defined
```
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_15 ex1_15.cpp
ex1_15.cpp: In function ‘int main()’:
ex1_15.cpp:7:5: error: ‘cout’ was not declared in this scope
     cout << v1 + v2 << std::endl;
     ^~~~
ex1_15.cpp:7:5: note: suggested alternative:
In file included from ex1_15.cpp:1:0:
/usr/include/c++/7/iostream:61:18: note:   ‘std::cout’
   extern ostream cout;  /// Linked to standard output
                  ^~~~
```

## Exercise 1.16
> Write your own version of a program that prints the sum of a set of integers read from *cin*.
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_16 ex1_16.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_16
2 4 6 7 8 15 62
The sum of these number you input is 104
```

## Exercise 1.17
> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?
```cpp
    // The former is that all the output are in one line; the latter is that all the input have its corresponding line of output
```

## Exercise 1.18
> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_18 ex1_18.cpp
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_18
6 6 6 6 6 6
6 occurs 6 times
root@localhost:/mnt/CppPrimer/Ch01$ ./ex1_18
1 2 3 4 5 6
1 occurs 1 times
2 occurs 1 times
3 occurs 1 times
4 occurs 1 times
5 occurs 1 times
6 occurs 1 times
```

## Exercise 1.19
> Revise the program you wrote for the exercises in $1.4.1 (p.13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.
```cpp
    // Do as Exercise 1.11(or 1.13) do
```