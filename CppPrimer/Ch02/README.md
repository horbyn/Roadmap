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

## Exercise 2.18
> Write code to change the value of a pointer. Write code to change the value to which the pointer points.
```shell
hoo@hoo-VirtualBox:/mnt/CppPrimer/Ch02$ g++ ex2_18.cpp -o ex2_18
hoo@hoo-VirtualBox:/mnt/CppPrimer/Ch02$ ./ex2_18
The value of the pointer before changing is 0x7ffd2972c3ac
The value of the pointer after changing is 0
The value to which the pointer points before changing is 0
The value to which the pointer points after changing is 5
```

## Exercise 2.19
> Explain the key differences between pointers and references.
```cpp
    // References must be initialized, but pointers must not.
    // References can not reassigned, but pointers can be assigned or copied. 
```

## Exercise 2.20
> What does the following program do?
> ```cpp
>     int i = 42;
>     int *p1 = &i;
>     *p1 = *p1 * *p1;
> ```
```cpp
    // Calculate 42 * 42
```

## Exercise 2.21
> Explain each of the following definitions. Indicate whether any are illegal and, if so, why.
> &#8195;int i = 0;  
> &#8195;(a) double *dp = &i;&#8195;&#8195;(b) int *ip = i;&#8195;&#8195;(c) int *p = &i;
```cpp
    // (a) Illegal, an int is assigned to a double type pointer.
    // (b) Illegal, cannot assign an int to a pointer.
```

## Exercise 2.22
> Assuming *p* is a pointer to *int*, explain the following code:
> ```cpp
> if (p) // ...
> if (*p) // ...
> ```
```cpp
    // Check whether this pointer is a valid one.
    // Check whether the value the pointer points is a nonzero.
```

## Exercise 2.23
> Given a pinter *p*, can you determine whether *p* points to a valid object? If so, how? If not, why not?
```cpp
    // Sure. Test whether the pointer is nullptr.
```

## Exercise 2.24
> Why is the initialization of *p* legal but that of *lp* illegal?  
> &#8195;int i = 42;&#8195;&#8195;void *p = &i;&#8195;&#8195;long *lp = &i;
```cpp
    // void *pointer can hold the address of any object
```

## Exercise 2.25
> Determine the types and values of each of the following variables.  
> &#8195;(a) int *ip, i, &r = i;&#8195;&#8195;(b) int i, *ip = 0;&#8195;&#8195;(c) int *ip, ip2;
```cpp
    // (a) ip: Type is int * pointer, value is nullptr;
    //     i: Type is int, value is undefined;
    //     r: Type is int reference, value is underfined;
    // (b) i: Type is int, value is undefined;
    //     ip: Type is int * pointer, value is nullptr;
    // (c) ip: Type is int * pointer, value is undefined;
    //     ip2: Type is int, value is undefined;
```

## Exercise 2.26
> Which of the following are legal? For those that are illegal, explain why.  
> &#8195;(a) const int buf;&#8195;&#8195;(b) int cnt = 0;&#8195;&#8195;(c) const int sz = cnt;*#8195;&#8195;(d) ++cnt; ++sz;
```cpp
    // (a) Illegal, const variable must initialize while it is created.
    // (b) Legal.
    // (c) Legal.
    // (d) Illegal, const variable cannot be reassigned.
```