#include <iostream>
#include <string>
#include <cstring>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int main() {
    std::string s1{"abcdefg"}, s2{"abcdefh"};

    std::cout << "is `" << s1 << "` different from `" << s2 << "`?"
        " --> " << (s1 != s2 ? "yes" : "no") << std::endl;
    
    char cstyle1[] = { 'a', 'b', 'c', 'd', 'e' },
        cstyle2[] = { 'a', 'b', 'c', 'd', 'f' };
    size_t len1 = NELEMS(cstyle1), len2 = NELEMS(cstyle2);
    
    std::cout << "is cstyle array `";
    for (size_t i = 0; i < len1; ++i)
        std::cout << cstyle1[i];
    std::cout << "` different from `";
    for (size_t i = 0; i < len2; ++i)
        std::cout << cstyle2[i];
    std::cout << "`? --> " << (::strcmp(cstyle1, cstyle2) == 0 ? "yes" : "no")
        << std::endl;

    return 0;
}
