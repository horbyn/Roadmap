# Chapter 3. Strings, vectors, and arrays

## Exercise 3.1
> Rewrite the exercises from $1.4.1 (p. 13) and $2.6.2 (p. 76) with appropriate *using* declarations.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_1_copy_ex1_9.cpp -o ex3_1_copy_ex1_9
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_1_copy_ex1_9
The sum of 50 to 100 inclusive is 3825

root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_1_copy_ex1_10.cpp -o ex3_1_copy_ex1_10
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_1_copy_ex1_10
10 9 8 7 6 5 4 3 2 1 0

root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_1_copy_ex1_11.cpp -o ex3_1_copy_ex1_11
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_1_copy_ex1_11
Please input two number in order to print each number in the range specified by these two integers: 2 15
2 3 4 5 6 7 8 9 10 11 12 13 14 15
```

## Exercise 3.2
> Write a program to read the standard input a line at a time. Modify your program to read a word at a time.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_2.cpp -o ex3_2
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_2
Please input a string: abcdefghijklmn opq rstu vwxy z
abcdefghijklmn opq rstu vwxy z
^C

root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_2.cpp -o ex3_2
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_2
Please input a string: abcdefghijklmn opq rstu vwxy z
abcdefghijklmn
opq
rstu
vwxy
z
^C
```

## Exercise 3.3
> Explain how whitespace characters are handled in the *string* input operator and in the *getline* function.
```cpp
    // In common standard input:
    // It reads characters until the whitespace(e.g., spaces, newlines, tabs) character is encountered.

    // In getline():
    // It stops reading and returns after seeing a newline.
```

## Exercise 3.4
> Write a program to read two *strings* and report whether the *strings* are equal. If not, report which of the two is larger. Now, change the program to report whether the *strings* have the same length, and if not, report which is longer.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_4.cpp -o ex3_4
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_4
Please input two strings: abcdefg
abcdeft
They aren't equal, but abcdeft is larger
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_4
Please input two strings: abcdefg
abcdefg
These two strings are equal!

root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_4.cpp -o ex3_4
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_4
Please input two strings: abcdefg
abcdefg
These two strings have the same length!
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_4
Please input two strings: abcedfg
abcd
Their length aren't same, but abcedfg is longer
```

## Exercise 3.5
> Write a program to read *strings* from the standard input, concatenation what is read into one large *string*. Print the conctenated *string*. Next, change the program to separate adjacent input *strings* by a space.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_5.cpp -o ex3_5
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_5
Please input two strings: abcdef
ghijklmn
abcdefghijklmn

root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_5.cpp -o ex3_5
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_5
Please input two strings: abcdef
ghijklmn
abcdef ghijklmn
```