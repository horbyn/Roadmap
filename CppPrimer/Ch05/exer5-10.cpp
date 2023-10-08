#include <iostream>
#include <string>

int main() {
    std::string words;
    std::cout << "Please input some words: ";
    std::getline(std::cin, words);

    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    for (auto ch : words)
        switch (ch) {
        case 'a': case 'A': ++aCnt; break;
        case 'e': case 'E': ++eCnt; break;
        case 'i': case 'I': ++iCnt; break;
        case 'o': case 'O': ++oCnt; break;
        case 'u': case 'U': ++uCnt; break;
        default: break;
        }
    std::cout << "Vowel a amount: " << aCnt
        << "\nVowel e amount: " << eCnt
        << "\nVowel i amount: " << iCnt
        << "\nVowel o amount: " << oCnt
        << "\nVowel u amount: " << uCnt
        << std::endl;

    return 0;
}
