# Section 1.2

流是字符序列，每个流对应着一个 IO 设备，可以从中读取或写入字符

标准库定义了 4 个 IO 对象：

- cin：用于读取，相当于 stdin
- cout：用于写入，相当于 stdout
- cerr：用于写入，用于写入警告或错误信息
- clog：用于写入，用于写入程序执行过程中的生成信息

通常，这 4 个流对象都关联到程序运行的那个窗口

`endl` 属于 `manipulator`，作用是：

- 换行
- 清空设备关联的缓冲区

使用 `endl` 可以确保程序目前为止生成的所有输出都写入到输出流，而不是留在内存等待写入

<br></br>

# Section 1.3

`/*` 和 `*/` 不能被嵌套

<br></br>

# Section 1.4.3

读入不定输入

```cpp
int value = 0;
while (std::cin >> value) {
    /* TODO */
}
```

这里条件是 `std::cin >> value`，返回的是 `istream` 对象，实际上测试的条件是 `stream` 的状态，如果状态无效即条件判定为假

关于 `stream` 状态是这么规定的：

- 有效：`stream` 没有出错
- 无效：无效输入或遇到 `EOF`

此处是 `istream` 对象，且输入类型为 `int`，因此无效输入的定义是输入了非 `int` 数据

至于 `EOF`，需要手动输入，`Windows` 需要输入 `ctrl + z`；`unix/mac` 需要输入 `ctrl + d` / `control + d`

<br></br>

# Section 1.5

从 `C++` 语言设计层面来说，要让类类型和内置类型表现得差不多

<br></br>

# Section 2.1.2

如果赋值给无符号类型一个超出它自身范围的值时，结果是初始值对无符号类型表示数值总数取模后的余数（比如向 `8` 比特无符号数赋值 `256`，结果为 `256` 取模 `256`（`8` 比特表示数值总数）的余数，即 0）

```c
#include <cstdio>

int main() {
        unsigned char uc = 5;
        printf("%u\n", uc);
        uc = 256;
        printf("%u\n", uc);
        uc = 260;
        printf("%u\n", uc);
        return 0;
}
```

如果赋值给有符号类型一个超出它表示范围的值时，结果是未定义的

<br></br>

# Section 2.1.3

## 数值字面值赋值

字面值即直接的数字，字面值也是有范围的，其范围如下：

- 十进制字面值：
    `int`、`long` 和 `long long` 当中尺寸最小那个（比如，在 `x86_64` 上分别是 `4`、`8` 和 `8` 字节，则范围为四字节的 `int`，即 (2<sup>31</sup> - 1)）
- 八进制和十六进制字面值：
    `int`、`unsigned int`、`long`、`unsigned long`、`long long` 和 `unsigned long long` 当中尺寸最小那个

```cpp
/* 以下是测试程序 */
/* 主要是测试将 2^31、2^31 - 1、2^32、2^32 - 1 赋值给 int */
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "===============================" << endl;
    cout << "2^31 = 2,147,483,648" << endl;

    cout << "2^31 - 1 assigns to int variable a: " << endl;
    int a = 2147483647;
    cout << "\ta = " << a << endl;
    cout << "2^31 assigns to int variable b: " << endl;
    int b = 2147483648;
    cout << "\tb = " << b << endl << endl;

    cout << "===============================" << endl;
    cout << "2^32 = 4,294,967,296" << endl;

    cout << "2^32 - 1 assigns to int variable c: " << endl;
    int c = 4294967295;
    cout << "\tc = " << c << endl;
    cout << "2^32 assigns to int variable d: " << endl;
    int d = 4294967296;
    cout << "\td = " << d << endl;

    return 0;
}
```

输出结果如下：

```shell
[root@xxx]# g++ -std=c++11 test2.cpp -o test2
test2.cpp: In function ‘int main(int, char**)’:
test2.cpp:22:13: warning: overflow in conversion from ‘long int’ to ‘int’ changes value from ‘4294967296’ to ‘0’ [-Woverflow]
   22 |     int d = 4294967296;
      |             ^~~~~~~~~~

[root@xxx]# ./test2
===============================
2^31 = 2,147,483,648
2^31 - 1 assigns to int variable a: 
        a = 2147483647
2^31 assigns to int variable b: 
        b = -2147483648

===============================
2^32 = 4,294,967,296
2^32 - 1 assigns to int variable c: 
        c = -1
2^32 assigns to int variable d: 
        d = 0
```

输出结果可能很迷惑，但主要关注内存数据就很清晰了：

```shell
2^31            0x7f ff ff ff
2^31 - 1        0x80 00 00 00
2^32            0xff ff ff ff
2^32 - 1        0x00 00 00 00
```

需要注意的是：

- 如果字面值超出与其关联的最大的范围，则产生错误
- `short` 没有对应的字面值

<br></br>

## 字面值常量

多个字符串字面值紧邻且仅由空格、缩进和换行分隔，则编译器会当成整体

```cpp
// 适用于一行写不下，分两行来写的字符串
std::cout << "a really, really long string literal "
 "that spans two lines" << std::endl;
```

<br></br>

# Section 2.2

## 初始化与赋值不同

初始化是创建对象的同时赋予一个初始值；而赋值是用一个新值覆盖对象原值

<br></br>

# Section 2.3

两指针相等有三种情况：

- 均为空指针
- 均指向同一对象
- 均指向同一对象的下一个地址

另外，还有可能是：

- 一个指针指向某个对象，而另一个指针指向另一对象的下一个地址，这个地址刚好就是这个对象的。如：

```cpp
/*  
 * ┌──────┐<- P1
 * │Obj 1 │  
 * ├──────┤<- P2
 * │Obj 2 │  
 * └──────┘  
*/
```


