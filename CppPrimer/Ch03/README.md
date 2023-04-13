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

<br></br>

## Exer 3.21

> Redo the first exercise from § 3.3.3 (p. 105) using iterators

- SKIP

<br></br>

## Exer 3.22

> Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase. After you’ve updated text, print its contents.

[run exer3-22.sh](exer3-22.sh)

<br></br>

## Exer 3.23

> Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector

[run exer3-23.sh](exer3-23.sh)

<br></br>

## Exer 3.24

> Redo the last exercise from § 3.3.3 (p. 105) using iterators.

[run exer3-24.sh](exer3-24.sh)

<br></br>

## Exer 3.25

> Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts

[run exer3-25.sh](exer3-25.sh)

<br></br>

## Exer 3.26

> In the binary search program on page 112, why did we write `mid = beg + (end - beg) / 2`; instead of `mid = (beg + end) / 2` ?;

- ~~because of considering of overflowing~~ **because there is NO plus operator overrided**

<br></br>

## Exer 3.27

> Assuming txt_size is a function that takes no arguments and returns an int value, which of the following definitions are illegal? Explain why.
> `unsigned buf_size = 1024;`
> (a) `int ia[buf_size];`
> (b) `int ia[4 * 7 - 14];`
> (c) `int ia[txt_size()];`
> (d) `char st[11] = "fundamental"`

- (a) illegal, because `buf_size` is a variable
- (c) illegal too, the reason likes above
- ~~(d) illegal, becasue no capacity could wrap null terminator~~

<br></br>

## Exer 3.28

> What are the values in the following arrays?
> ```cpp
> string sa[10];
> int ia[10];
> int main() {
>     string sa2[10]; int ia2[10];
> }
> ```

- `sa` is all 10 elements are null string
- `ia` is all 10 elements are 0
- `sa2` is all 10 elements are undefined
- `ia2` is all 10 elements are undefined

<br></br>

## Exer 3.29

> List some of the drawbacks of using an array instead of a vector

- With fixed length, array is unfiexible

<br></br>

## Exer 3.30

> Identify the indexing errors in the following code:
> ```cpp
> constexpr size_t array_size = 10;
> int ia[array_size];
> for (size_t ix = 1; ix <= array_size; ++ix)
>     ia[ix] = ix;
> ```

- 10

<br></br>

## Exer 3.31

> Write a program to define an array of ten ints. Give each element the same value as its position in the array

[run exer3-31.sh](exer3-31.sh)

<br></br>

## Exer 3.32

> Copy the array you defined in the previous exercise into another array. Rewrite your program to use vectors.

[run exer3-32.sh](exer3-32.sh)

<br></br>

## Exer 3.33

> What would happen if we did not initialize the scores array in the program on page 116?

- some score range which is actually no input maybe a nonzero value

<br></br>

## Exer 3.34

> Given that p1 and p2 point to elements in the same array, what does the following code do? Are there values of p1 or p2 that make this code illegal?
> `p1 += p2 - p1;`

- `p1` is equivalent of `p2`
- ~~no~~ **if `p1` and `p2` are belong with different array that the statement is illegal**

<br></br>

## Exer 3.35

> Using pointers, write a program to set the elements in an array to zero.

[run exer3-35.sh](exer3-35.sh)

<br></br>

## Exer 3.36

> Write a program to compare two arrays for equality. Write a similar program to compare two vectors.

[run exer3-36.sh](exer3-36.sh)

<br></br>

## Exer 3.37

> What does the following program do?
> ```cpp
> const char ca[] = {'h', 'e', 'l', 'l', 'o'};
> const char *cp = ca;
> while (*cp) {
>     cout << *cp << endl; ++cp;
> }
> ```

- it calculates the string length logically, but it wouldn't get the correct result because the array misses the null character in the end

<br></br>

## Exer 3.38

> In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

- it maybe point to the place that is undefined

<br></br>

## Exer 3.39

> Write a program to compare two strings. Now write a program to compare the values of two C-style character strings.

[run exer3-39.sh](exer3-39.sh)

<br></br>

## Exer 3.40

> Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use strcpy and strcat to copy the two arrays into the third.

[run exer3-40.sh](exer3-40.sh)

<br></br>

## Exer 3.41

> Write a program to initialize a `vector` from an array of `int`s

[run exer3-41.sh](exer3-41.sh)

<br></br>

## Exer 3.42

> Write a program to copy a `vector` of `int`s into an array of `int`s

[run exer3-42.sh](exer3-42.sh)

<br></br>

## Exer 3.43

> Write three different versions of a program to print the elements of ia. One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers. In all three programs write all the types directly. That is, do not use a type alias, auto, or decltype to simplify the code.

[run exer3-43.sh](exer3-43.sh)

<br></br>

## Exer 3.44

> Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.

[run exer3-44.sh](exer3-44.sh)

<br></br>

## Exer 3.45

> Rewrite the programs again, this time using `auto`.

[run exer3-45.sh](exer3-45.sh)

<br></br>
