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
hoo@hoo-VirtualBox:/mnt/CppPrimer/Ch01$ ./ex1_4
Enter two numbers:
3 7
The product of 3 and 7 is 21
```

## Exercise 1.5
> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.
```shell
root@localhost:/mnt/CppPrimer/Ch01$ g++ -o ex1_5 ex1_5.cpp
hoo@hoo-VirtualBox:/mnt/CppPrimer/Ch01$ ./ex1_5
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