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
