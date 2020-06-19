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

## Exercise 3.21
> Redo the first exercise from $3.3.3 (p. 105) using iterators.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_21_copy_ex3_16.cpp -o ex3_21_copy_ex3_16
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_21_copy_ex3_16
(a) 0; 
(b) 10; 0000000000
(c) 10; 42424242424242424242
(d) 1; 10
(e) 2; 1042
(f) 10; 
(g) 10; hihihihihihihihihihi
```

## Exercise 3.22
> Revise the loop that printed the first paragraph in *text* to instead change the elements in *text* that correspond to the first paragraph to all uppercase. After you've updated *text*, print its contents.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_22.cpp -o ex3_22
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_22
Enter "RETURN" then "CTRL + D" to exit input
    I am a bird. I like the sky.

    I don't like lake.
    I AM A BIRD. I LIKE THE SKY.
```

## Exercise 3.23
> Write a program to create a *vector* with ten *int* elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the *vector*.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_23.cpp -o ex3_23
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_23
Enter "RETURN" then "CTRL + D" to exit input
0 1 2 3 4 5 6 7 8 9
024681012141618
```

## Exercise 3.24
> Redo the last exercise from $3.3.3 (p. 105) using iterators.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_24_copy_ex3_20.cpp -o ex3_24_copy_ex3_20
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_24_copy_ex3_20
Enter "RETURN" then "CTRL + D" to exit input
1 2 3 4 5 6 7 8 9 10
3 5 7 9 11 13 15 17 19 
Enter "RETURN" then "CTRL + D" to exit input
11 11 11 11 11
```

## Exercise 3.25
> Rewrite the grade clustering program from $3.3.3 (p. 104) using iterators instead of subscripts.
```shell
root@localhost:/mnt/CppPrimer/Ch03$ g++ ex3_25.cpp -o ex3_25
root@localhost:/mnt/CppPrimer/Ch03$ ./ex3_25
Enter "RETURN" then "CTRL + D" to exit input
42 65 95 100 39 67 95 76 88 76 83 92 76 93
0 0 0 1 1 0 2 3 2 4 1
```

## Exercise 3.26
> In the binary search program on page 112, why did we write *mid = beg + (end - beg) / 2*; instead of *mid = (beg + end) / 2*;?
```cpp
    // No addition operation to a iterator and another iterator.
```

## Exercise 3.27
> Assuming *txt_size* is a function that takes no arguments and returns an *int* value, which of the following definitions are illegal? Explain why.
> ```shell
>     unsigned buf_size = 1024;
>     (a) int ia[buf_size];         (b) int ia[4 * 7 -14];
>     (c) int ia[txt_size()];       (d) char st[11] = "fundamental";
> ```
```cpp
    // (a) Illegal, because buf_size is variable that cannot be determined in compile time
    // (c) Illegal, because the value of txt_size() returning is variable that cannot be determined in compile time.
    // (d) Illegal, because the initialization of string literal need additional space to store a null character in the end.
```

## Exercise 3.28
> What are the values in the following arrays?
> ```cpp
>     string sa[10];
>     int ia[10];
>     int main() {
>         string sa2[10];
>         int    ia2[10];
>     }
> ```
```cpp
    // sa[10]: empty
    // ia[10]: 0
    // sa2[10] and ia2[10]: undefined
```

## Exercise 3.29
> List some of the drawbacks of using an array instead of a *vector*
```cpp
    // The primary drawback is that the size of array must be explicit.
```

## Exercise 3.30
> Identify the indexing errors in the following code:
> ```cpp
> constexpr size_t array_size = 10;
> int ia[array_size];
> for(size_t ix = 1; ix <= array_size; ++ix)
>     ia[ix] = ix;
> ```
```cpp
    // the for condition "ix <= array_size" changes to "ix < array_size"
```

## Exercise 3.31
> Write a program to define an array of ten *int*s. Give each element the same value as its position in the array.
```shell
root@localhost:/mnt/e/horbyn/CppPrimer/Loadmap/CppPrimer/Ch03$ ./ex3_31
0 1 2 3 4 5 6 7 8 9
```

## Exercise 3.32
>Copy the array you defined in the previous exercise into another array. Rewrite your program to use *vector*s.
```shell
root@localhost:/mnt/e/horbyn/CppPrimer/Loadmap/CppPrimer/Ch03$ ./ex3_32
After copying from array:
0 1 2 3 4 5 6 7 8 9
After copying from vector:
0 1 2 3 4 5 6 7 8 9
```

## Exercise 3.33
> What would happen if we did not iniialize the *scores* array in the program on page 116?
```cpp
    // The elements of the array is undefined.
```

## Exercise 3.34
> Given that *p1* and *p2* point to elements in the same array, what does the following code do? Are there values of *p1* or *p2* that make this code illegal?  
`p1 += p2 - p1;`
```shell
```

## Exercise 3.35
> Using pointers, write a program to set the elements in an array to zero.
```shell
```

## Exercise 3.36
> Write a program to compare two arrays for equality. Write a similar program to compare two *vector*s.
```shell
```