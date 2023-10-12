# CH5

## 5.1

> What is a null statement? When might you use a null statement?

- no any context; whenever i want

<br></br>

## 5.2

> What is a block? When might you might use a block?

- that composed with at least one sentence; whenever you want

<br></br>

## 5.3

> Use the comma operator (§ 4.10, p. 157) to rewrite the `while` loop from § 1.4.1 (p. 11) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.

```cpp
while (val <= 10, ++val)
    sum += val;
```

- I think no

<br></br>

## 5.4

> Explain each of the following examples, and correct any problems you detect.
> (a) `while (string::iterator iter != s.end()) { /* . . . */ }`
> (b) `while (bool status = find(word)) { /* . . . */ }`
> `if (!status) { /* . . . */ }`

- a. ~~travesal all the elements in the string object~~ **Wrong. changes to the following**
    ```cpp
    std::string::iterator iter = s.begin();
    while (iter != s.end()) {
        ++iter;
        /*...*/
    }
    ```
- b. ~~travesal `word` until some status is catered~~ **Wrong, revise to the following**
    ```cpp
    bool status = false;
    while (status = find(word)) { /*...*/ }
    if (!status) { /*...*/ }
    ```

<br></br>

## 5.5

> Using an `if–else` statement, write your own version of the program to generate the letter grade from a numeric grade.

[run exer5-5.sh](./exer5-5.sh)

<br></br>

## 5.6

> Rewrite your grading program to use the conditional operator (§ 4.7, p. 151) in place of the `if–else` statement

[run exer5-6.sh](./exer5-6.sh)

<br></br>

## 5.7

> Correct the errors in each of the following code fragments:
> ```cpp
> (a) if (ival1 != ival2)
>         ival1 = ival2
>     else ival1 = ival2 = 0;
> (b) if (ival < minval)
>         minval = ival;
>         occurs = 1;
> (c) if (int ival = get_value())
>         cout << "ival = " << ival << endl;
>     if (!ival)
>         cout << "ival = 0\n";
> (d) if (ival = 0)
>         ival = get_value();
> ```

- (a) no problem
- (b) `occurs = 1` will always execute
    ```cpp
    if (ival < minval) {
        minval = ival;
        occurs = 1;
    }
    ```
- (c) `ival` is local variable
    ```cpp
    int ival;
    if (ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";    
    ```
- (d) condition will always not cater
    ```cpp
    if (ival == 0)
        ival = get_value();
    ```

<br></br>

## 5.8

> What is a "dangling else"? How are else clauses resolved in C++?

- more `if` branches than `else` branches; in C++ is resolved by specifying that each `else` is matched with the closest preceding unmatched `if`

<br></br>

## 5.9

> Write a program using a series of `if` statements to count the number of vowels in text read from `cin`.

[run exer5-9.sh](./exer5-9.sh)

<br></br>

## 5.10

> There is one problem with our vowel-counting program as we’ve implemented it: It doesn’t count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel—that is, your program should count both 'a' and 'A' as part of aCnt, and so forth.

[run exer5-10.sh](./exer5-10.sh)

<br></br>

## 5.11

> Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.

[run exer5-11.sh](./exer5-11.sh)

<br></br>

## 5.12

> Modify our vowel-counting program so that it counts the number of occurrences of the following two-character sequences: ff, fl, and fi.

[run exer5-12.sh](./exer5-12.sh)

<br></br>

## 5.13

> Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.
> ```cpp
> (a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
>     char ch = next_text();
>     switch (ch) {
>         case 'a': aCnt++;
>         case 'e': eCnt++;
>         default: iouCnt++;
>     }
> (b) unsigned index = some_value();
>     switch (index) {
>         case 1:
>             int ix = get_value();
>             ivec[ ix ] = index;
>             break;
>         default:
>             ix = ivec.size()-1;
>             ivec[ ix ] = index;
>     }
> (c) unsigned evenCnt = 0, oddCnt = 0;
>     int digit = get_num() % 10;
>     switch (digit) {
>     case 1, 3, 5, 7, 9:
>         oddcnt++;
>         break;
>     case 2, 4, 6, 8, 10:
>         evencnt++;
>         break;
>     }
> (d) unsigned ival=512, jval=1024, kval=4096;
>     unsigned bufsize;
>     unsigned swt = get_bufCnt();
>     switch(swt) {
>     case ival:
>         bufsize = ival * sizeof(int);
>         break;
>     case jval:
>         bufsize = jval * sizeof(int);
>         break;
>     case kval:
>         bufsize = kval * sizeof(int);
>         break;
>     }
> ```

- (a) no `break`
- (b) ~~`default` has no `break`~~ **`ix` initialization will be skipped**
- (c) `case` syntax error, it did not has comma
- (d) ~~SHOULD have `default` branch~~ **the value of `case` tag must be const integer expression**

<br></br>

## 5.14

> Write a program to read `string`s from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is
> `how now now now brown cow cow`
> the output should indicate that the word `now` occurred three times.

[run exer5-14.sh](./exer5-14.sh)

<br></br>

## 5.15

> Explain each of the following loops. Correct any problems you detect.
> ```cpp
> (a) for (int ix = 0; ix != sz; ++ix) { /* . . . */ }
>     if (ix != sz) // . . .
> (b) int ix;
>     for (ix != sz; ++ix) { /* . . . */ }
> (c) for (int ix = 0; ix != sz; ++ix, ++ sz) { /* . . . */ }
> ```

- (a) do something until `ix != sz`, do another thing if break halfway. No problem
- (b) do something until `ix != sz`. Problem is `for()` syntax incorrectly that omits semicolon
    `for (; ix != sz; ++ix) { /* . . . */ }`
- (c) do something until `ix != sz`. Problem is `++sz` will cause loop forever
    `for (int ix = 0; ix != sz; ++ix)`

<br></br>

## 5.16

> The `while` loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The `for` loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?

- SKIP

<br></br>

## 5.17

> Given two `vector`s of `int`s, write a program to determine whether one `vector` is a prefix of the other. For `vector`s of unequal length, compare the number of elements of the smaller `vector`. For example, given the `vector`s containing `0, 1, 1`, and `2` and `0, 1, 1, 2, 3, 5, 8`, respectively your program should return `true`.

[run exer5-17.sh](./exer5-17.sh)

<br></br>

## 5.18

> Explain each of the following loops. Correct any problems you detect.
> ```cpp
> (a) do
>         int v1, v2;
>         cout << "Please enter two numbers to sum:";
>         if (cin >> v1 >> v2)
>             cout << "Sum is: " << v1 + v2 << endl;
>     while (cin);
> (b) do {
>         // . . .
>     } while (int ival = get_response());
> (c) do {
>         int ival = get_response();
>     } while (ival);
> ```

- (a) input two integer and calculate they sum. Problem is the statements block has no brackets
- (b) do something if `ival` is not zero. Problem is the condition statement has variable definition
- (c) do something if `ival` is not zero. ~~No problems.~~ **some variable happened in condition must be defined outside of loop body**

<br></br>

## 5.19

> Write a program that uses a `do while` loop to repetitively request two `string`s from the user and report which `string` is less than the other.

[run exer5-19.sh](./exer5-19.sh)

<br></br>

## 5.20

> Write a program to read a sequence of `string`s from the standard input until either the same word occurs twice in succession or all the words have been read. Use a `while` loop to read the text one word at a time. Use the `break` statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.

[run exer5-20.sh](./exer5-20.sh)

<br></br>

## 5.21

> Revise the program from the exercise in § 5.5.1 (p. 191) so that it looks only for duplicated words that start with an uppercase letter.

[run exer5-21.sh](./exer5-21.sh)

<br></br>

## 5.22

> The last example in this section that jumped back to `begin` could be better written using a loop. Rewrite the code to eliminate the `goto`.

```cpp
for (int sz = get_size(); sz <= 0; ) {
    /* DO SOMETHING */
}
```

<br></br>

## 5.23

> Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.

[run exer5-23.sh](./exer5-23.sh)

<br></br>

## 5.24

> Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don’t `catch` an exception.

[run exer5-24.sh](./exer5-24.sh)

<br></br>

## 5.25

> Revise your program from the previous exercise to use a `try` block to `catch` the exception. The `catch` clause should print a message to the user and ask them to supply a new number and repeat the code inside the `try`.

[run exer5-25.sh](./exer5-25.sh)

<br></br>
