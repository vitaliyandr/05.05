#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

void replaceWord(std::string& text, const std::string& oldWord, const std::string& newWord) {
    size_t pos = text.find(oldWord);
    while (pos != std::string::npos) {
        text.replace(pos, oldWord.length(), newWord);
        pos = text.find(oldWord, pos + newWord.length());
    }
}

void capitalizeSentences(std::string& text) {
    size_t len = text.length();
    for (size_t i = 0; i < len; i++) {
        if (i == 0 || (i > 0 && text[i - 1] == '.')) {
            text[i] = std::toupper(text[i]);
        }
    }
}

void countLetters(const std::string& text) {
    int letters[26] = { 0 };
    size_t len = text.length();
    for (size_t i = 0; i < len; i++) {
        char c = std::tolower(text[i]);
        if (c >= 'a' && c <= 'z') {
            letters[c - 'a']++;
        }
    }
    std::cout << "Letter counts:\n";
    for (int i = 0; i < 26; i++) {
        std::cout << static_cast<char>('a' + i) << ": " << letters[i] << "\n";
    }
}

void countDigits(const std::string& text) {
    int digits = 0;
    size_t len = text.length();
    for (size_t i = 0; i < len; i++) {
        if (std::isdigit(text[i])) {
            digits++;
        }
    }
    std::cout << "Digit count: " << digits << "\n";
}

int main() {
    std::string text;
    std::string oldWord;
    std::string newWord;

    std::cout << "Enter some text: ";
    std::getline(std::cin, text);

    std::cout << "Enter a word to replace: ";
    std::cin >> oldWord;

    std::cout << "Enter the new word: ";
    std::cin >> newWord;

    replaceWord(text, oldWord, newWord);
    capitalizeSentences(text);
    countLetters(text);
    countDigits(text);

    return 0;
}

