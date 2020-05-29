# Chapter 2. Variables and Basic Types

## Exercise 2.1
> What are the differences between *int*, *long*, *long long*, and *short*? Between an unsigned and a signed type? Between a *float* and a *double*?
```cpp
    // Minimum size
    // Whether all the bits represent the value
    // Length of the significant digits
```

## Exercise 2.2
> To calculate a mortgage payment, what types would you use for the ratem principalm and payment? Explain why you selected each type.
```cpp
    // Double. Because we will finally obtain inaccurate value when we calculate addition, subtraction, multiplication and division by using imprecise values.
```

## Exercise 2.3
> What output will the following code produce?  
> &#8195;&#8195;unsigned u = 10, u2 = 42;  
> &#8195;&#8195;std::cout << u2 - u << std::endl;  
> &#8195;&#8195;std::cout << u - u2 << std::endl;  
> &#8195;&#8195;int i = 10, i2 = 42;  
> &#8195;&#8195;std::cout << i2 - i << std::endl;  
> &#8195;&#8195;std::cout << i - i2 << std::endl;  
> &#8195;&#8195;std::cout << i - u << std::endl;  
> &#8195;&#8195;std::cout << u - i << std::endl;
```cpp
    // an expected value: 32
    // an unexpected value
    // an expected value: 32
    // an expected value: -32
    // an expected value: 0
    // an expected value: 0
```

## Exercise 2.4
> Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.
```shell
root@localhost:/mnt/CppPrimer/Ch02$ g++ ex2_3.cpp -o ex2_3
root@localhost:/mnt/CppPrimer/Ch02$ ./ex2_3
32
4294967264
32
-32
0
0
```

## Exercise 2.5
> Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:  
> &#8195;&#8195;(a) 'a', L'a', "a", L"a"  
> &#8195;&#8195;(b) 10, 10u, 10L, 10uL, 012, 0xC  
> &#8195;&#8195;(c) 3.14, 3.14f, 3.14L  
> &#8195;&#8195;(d) 10, 10u, 10., 10e-2  
```cpp
    // (a) char(8 bits), wchar_t(16 bits), string(16 bits), string(32 bits);
    // (b) signed int, unsigned int, signed long, unsigned long, escape sequences(CRLF), escape sequences(Page Change Key)
    // (c) double, float, long double
    // (d) signed int, unsigned int, double, double
```

## Exercise 2.6
> What, if any, are the differences between the following definitions:  
> &#8195;&#8195;int month = 9, day = 7;  
> &#8195;&#8195;int month = 09, day = 07;  
```cpp
    // right
    // error: 09 is a escape sequences, but 9 is not a octal number
```

## Exercise 2.7
> What values do these literals represent? What type does each have?  
> &#8195;&#8195;(a) "Who goes with F\145rgus?\012"  
> &#8195;&#8195;(b) 3.14e1L&#8195;&#8195;(c) 1024f&#8195;&#8195;(d) 3.14L
```cpp
    // (a) "Who goes with Fergus?\n"; string
    // (b) 3.14; long double
    // (c) 1024.0; float
    // (d) 3.14; long double
```

## Exercise 2.8
> Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.
```shell
root@localhost:/mnt/CppPrimer/Ch02$ g++ ex2_8.cpp -o ex2_8
root@localhost:/mnt/CppPrimer/Ch02$ ./ex2_8
2M

2	M

```

## Exercise 2.9
> Explain the following definitions. For those that are illegal, explain what's wrong and how to correct it.  
> &#8195;&#8195;(a) std::cin >> int input_value;&#8195;&#8195;(b) int i = { 3.14 };  
> &#8195;&#8195;(c) double salary = wage = 9999.99;&#8195;&#8195;(d) int i = 3.14;
```cpp
    // (a) I can't..
    // (b) 3.14 will be truncated. List Initialization will not allow this initialization.
    // (c) wage is not initialized.
    // (d) I can't..
```

## Exercise 2.10
> What are the initial values, if any, of each of the following variables?
> ```cpp
> std::string global_str;
> int global_int;
> int main()
> {
>     int local_int;
>     std::string local_str;
> }
> ```
```cpp
    // global_str is a empty string;        global_int = 0;
    // local_str is uninitialized;          local_int is uninitialized;
```

## Exercise 2.11
> Explain whether each of the following is a declaration or a definition:  
> (a) extern int ix = 1024;  
> (b) int iy;  
> (c) extern int iz;  
```cpp
    // (a) definition.
    // (b) declaration.
    // (c) declaration.
```

## Exercise 2.12
> Which, if any, of the following names are invalid?  
> &#8195;&#8195;(a) int double = 3.14;&#8195;&#8195;(b) int _;  
> &#8195;&#8195;(c) int catch-22;&#8192;&#8195;&#8195;&#8195;&#8195;(d) int 1_or_2 = 1;  
> &#8195;&#8195;(e) double Double = 3.14;
```cpp
    // (a) invalid
    // (b) valid
    // (c) invalid
    // (d) invalid
    // (e) valid
```

## Exercise 2.13
> What is the value of *j* in the following program?
> ```cpp
> int i = 42;
> int main()
> {
>     int i = 100;
>     int j = i;
> }
> ```
```cpp
    // j = 100;
```

## Exercise 2.14
> Is the following program legal? If so, what values are printed?
> ```cpp
> int i = 100, sum = 0;
> for (int i = 0; i != 10; ++i)
>     sum += i;
> std::cout << i << " " << sum << std::endl;
> ```
```cpp
    // 100 45
```

## Exercise 2.15
> Which of the following definitions, if any, are invalid? Why?  
> &#8195;&#8195;(a) int ival = 1.01;&#8195;&#8195;&#8195;&#8195;&#8195;&#8195;(b) int &rval1 = 1.01;  
> &#8195;&#8195;(c) int &rval2 = ival;&#8195;&#8195;&#8195;&#8195;&#8195;(d) int &rval3;
```cpp
    // (b). Initializer is not an int object
    // (d). The reference is uninitialized
```

## Exercise 2.16
> Which, if any, of the following assignments are invalid? If they are valid, explain what they do.  
> &#8195;&#8195;int i = 0, &r1 = i; double d = 0, &r2 = d;  
> &#8195;&#8195;(a) r2 = 3.14159;&#8195;&#8195;&#8195;&#8195;&#8195;&#8195;(b) r2 = r1;  
> &#8195;&#8195;(c) i = r2;&#8195;&#8195;&#8195;&#8195;&#8195;&#8195;&#8195;&#8195;&#8195; (d) r1 = d;
```cpp
    // (a). Valid. Assigning a double type value, 3.14159, to a double type reference
    // (b). Valid. Assigning a int type variable to a double type variable
    // (c). Valid. Assigning a double type variable to a int type variable
    // (d). Invalid.
```

## Exercise 2.17
> What does the following code print?
> ```cpp
>     int i, &ri = i;
>     i = 5; ri = 10;
>     std::cout << i << " " << ri << std::endl;
> ```
```cpp
    // 10 10
```