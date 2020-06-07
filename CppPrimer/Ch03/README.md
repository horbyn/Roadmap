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

## Exercise 3.6
> Use a range *for* to change all the characters in a *string* to X.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_6.cpp -o ex3_6
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_6
abcdefg
XXXXXXX
```

## Exercise 3.7
> What would happen if you define the loop control variable in the previous exercise as type *char*? Predict the results and then change your program to use a *char* to see if you were right.
```cpp
    // Outcome will be same as the input string, all the characters won't be changed to 'X'
```
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_7.cpp -o ex3_7
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_7
abcdefg
abcdefg
```

## Exercise 3.8
> Rewrite the program in the first exercise, first using a *while* and again using a traditional *for* loop. Which of the three approaches do you prefer and why?
```cpp
    // I prefer range for, because it's readable and sententious.
```

## Exercise 3.9
> What does the following program do? Is it valid? If not, why not?
> ```cpp
>     string s;
>     cout << s[0] << endl;
> ```
```cpp
    // It's invalid. String s is uninitialized so the first element is undefined.
```

## Exercise 3.10
> Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_10.cpp -o ex3_10
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_10
abc,defg!hi@jkl;mno!
abcdefghijklmno
```

## Exercise 3.11
> Is the following range *for* legal? If so, what is the type of c?
> ```cpp
>     const string s = "Keep out!";
>     for (auto &c : s) { /* ... */ }
> ```
```cpp
    // It's legal if the body of for to read-only, whereas illegal if to reassign.
    // The type of c is char &.
```

## Exercise 3.12
> Which, if any, of the following *vector* definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.
> ```shell
>     (a) vector<vector<int>> ivec;
>     (b) vector<string> svec = ivec;
>     (c) vector<string> svec(10, "null");
> ```
```cpp
    // (a) Legal, to define a vector object whose elements are vectors, ivec.
    // (b) Illegal, a vector object assigns to string object.
    // (c) Legal, svec has ten elements that are all "null".
```

## Exercise 3.13
> How many elements are there in each of the following *vectors*? What are the values of the elements?
> ```shell
>     (a) vector<int> v1;           (b) vector<int> v2(10);
>     (c) vector<int> v3(10, 42);   (d) vector<int> v4{10};
>     (e) vector<int> v5{10, 42};   (f) vector<string> v6{10};
>     (g) vector<string> v7{10, "hi"};
```cpp
    // (a) one; zero.
    // (b) ten; zero.
    // (c) ten; 42.
    // (d) one; 10.
    // (e) two; 10 and 42.
    // (f) ten; empty.
    // (g) ten; "hi".
```

## Exercise 3.14
> Write a program to read a sequence of *int*s from *cin* and store those values in a *vector*.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_14.cpp -o ex3_14
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_14
Enter "RETURN" then "CTRL + D" to exit input
1 3 4 5 6 7 8
1345678
```

## Exercise 3.15
> Repeat the previous program but read *string*s this time.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_15.cpp -o ex3_15
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_15
Enter "RETURN" then "CTRL + D" to exit input
abc def ghijk
abcdefghijk
```

## Exercise 3.16
> Write a program to print the size and contents of the *vectors* from exercise 3.13. Check whether your answers to that exercise were correct. If not, restudy $3.3.1 (p. 97) until you understand why you were wrong.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_16.cpp -o ex3_16
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_16
(a) 0; 
(b) 10; 0000000000
(c) 10; 42424242424242424242
(d) 1; 10
(e) 2; 1042
(f) 10; 
(g) 10; hihihihihihihihihihi
```

## Exercise 3.17
> Read a sequence of words from *cin* and store the values a *vector*. After you've read all the words, process the *vector* and change each word to uppercase. Print the transformed elements, eight words to a line.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_17.cpp -o ex3_17
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_17
Enter "RETURN" then "CTRL + D" to exit input
abandon ability able abnormal aboard abolish abortion about above abroad abrupt absence absent absolute absorb abstract absurd
ABANDON ABILITY ABLE ABNORMAL ABOARD ABOLISH ABORTION ABOUT
ABOVE ABROAD ABRUPT ABSENCE ABSENT ABSOLUTE ABSORB ABSTRACT
ABSURD
```

## Exercise 3.18
> Is the following program legal? If not, how might you fix it?
> ```cpp
>     vector<int> ivec;
>     ivec[0] = 42;
> ```
```cpp
    // Illegal.
    vector<int> ivec;
    ivec.push_back(42);
```

## Exercise 3.19
> List three ways to define a *vector* and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.
```cpp
    // preferrer, because it's sententious
    vector<int> v1(10, 42);

    vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

    vector<int> v3(10);
    for(auto &index : v3)    index = 42;

    vector<int> v4;
    for(int i = 0; i < 10; i++)    v4.push_back(42);
```

## Exercise 3.20
> Read a set of integers into a *vector*. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_20.cpp -o ex3_20
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_20
Enter "RETURN" then "CTRL + D" to exit input
1 2 3 4 5 6 7 8 9 10
3 5 7 9 11 13 15 17 19 
Enter "RETURN" then "CTRL + D" to exit input
11 11 11 11 11 11 11 11 11 11
```