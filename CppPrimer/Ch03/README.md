# CH3

## Exer 3.1

> Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with appropriate using declarations.

- SKIP

<br></br>

## Exer 3.2

> Write a program to read the standard input a line at a time. Modify your program to read a word at a time.

[run exer3-2.sh](exer3-2.sh)

<br></br>

## Exer 3.3

> Explain how whitespace characters are handled in the string input operator and in the getline function.

- For string input op: spaces,tabs and newlines will be ignored, and input stream will be truncated at that point
- For getline(): only newlines work out

<br></br>

## Exer 3.4

> Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.

[run exer3-4.sh](exer3-4.sh)

<br></br>

## Exer 3.5

> Write a program to read strings from the standard input, concatenating what is read into one large string. Print the concatenated string. Next, change the program to separate adjacent input strings by a space.

[run exer3-5.sh](exer3-5.sh)

<br></br>

## Exer 3.6

> Use a range for to change all the characters in a string to X.

[run exer3-6.sh](exer3-6.sh)

<br></br>

## Exer 3.7

> What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.

- it works too.

[run exer3-7.sh](exer3-7.sh)

<br></br>

## Exer 3.8

> Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?

- SKIP rewriting, and I don't think one of the method is prefer that which method to use depending on scene

<br></br>

## Exer 3.9

> What does the following program do? Is it valid? If not, why not?
> ```cpp
> string s;
> cout << s[0] << endl;
> ```

- it prints out the first character of the string. it may not be valid when `s` is empty

<br></br>

## Exer 3.10

> Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.

[run exer3-10.sh](exer3-10.sh)

<br></br>

## Exer 3.11

> Is the following range for legal? If so, what is the type of c?
> ```cpp
> const string s = "Keep out!";
> for (auto &c : s) { /* ... */ }
> ```

- ~~illegal, `c` is `int &`~~ **Legal, and `c` is `const int &`, but the code segment cannot be compiled because references to const is unchanging**

<br></br>

## Exer 3.12

> Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.
> (a) vector\<vector\<int\>\> ivec;
> (b) vector\<string\> svec = ivec;
> (c) vector\<string\> svec(10, "null");

- (a): legal, `ivec` is a `std::vector` object whose elements are `std::vector<int>` object
- (b): illegal, assignment cannot happened between two different types
- (c): legal, `svec` is a `std::vector<std::string >` object which have 10 object included "null" value

<br></br>

## Exer 3.13

> How many elements are there in each of the following vectors? What are the values of the elements?
> (a) vector<int> v1;
> (b) vector<int> v2(10);
> (c) vector<int> v3(10, 42);
> (d) vector<int> v4{10};
> (e) vector<int> v5{10, 42};
> (f) vector<string> v6{10};
> (g) vector<string> v7{10, "hi"};

- (a) None
- (b) Ten, all are 0
- (c) Ten, all are 42
- (d) only one object held 10
- (e) Two, 10 and 42 it held
- (f) Ten, all are null
- (g) Ten, all are "hi"

<br></br>

## Exer 3.14

> 3.14: Write a program to read a sequence of ints from cin and store those values in a vector.

[run exer3-14.sh](exer3-14.sh)

<br></br>

## Exer 3.15

> Repeat the previous program but read strings this time.

[run exer3-15.sh](exer3-15.sh)

<br></br>

## Exer 3.16

> Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your answers to that exercise were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong

**SKIP**

<br></br>

## Exer 3.17

> Read a sequence of words from cin and store the values a vector. After you’ve read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line

[run exer3-17.sh](exer3-17.sh)

<br></br>

## Exer 3.18

> Is the following program legal? If not, how might you fix it?
> ```cpp
> vector<int> ivec;
> ivec[0] = 42;
> ```

- No, changes to `ivec.push_back(0);`

<br></br>

## Exer 3.19

> List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.

- `std::vector<int > v1(10, 42);`
- `std::vector<int > v2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };`
- ```cpp
    std::vector<int > v3;
    for(size_t i = 0; i < 10; ++i)
        v3.push_back(42);
  ```

i like the first one because of convenience

<br></br>

## Exer 3.20

> Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.

[run exer3-20.sh](exer3-20.sh)
