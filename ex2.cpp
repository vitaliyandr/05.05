#include <iostream>
#include <string>
#include <algorithm>

int countWordOccurrences(const std::string& text, const std::string& word) {
    int count = 0;
    std::size_t pos = 0;
    while ((pos = text.find(word, pos)) != std::string::npos) {
        count++;
        pos += word.length();
    }
    return count;
}

int countSentences(const std::string& text) {
    int count = 0;
    for (char c : text) {
        if (c == '.' || c == '!') {
            count++;
        }
    }
    return count;
}

int countDotsAndCommas(const std::string& text) {
    int count = 0;
    for (char c : text) {
        if (c == '.' || c == ',') {
            count++;
        }
    }
    return count;
}

std::string reverseText(const std::string& text) {
    std::string reversedText = text;
    std::reverse(reversedText.begin(), reversedText.end());
    return reversedText;
}

std::string reverseSentences(const std::string& text) {
    std::string reversedText = text;
    std::size_t start = 0;
    std::size_t end = text.find_first_of(".!");
    while (end != std::string::npos) {
        std::reverse(reversedText.begin() + start, reversedText.begin() + end);
        start = end + 1;
        end = text.find_first_of(".!", start);
    }
    return reversedText;
}

int main() {
    std::string text = "This is a sample text. It contains multiple sentences. Some of them may have dots or commas.";
    std::string word;
    std::cout << "Enter a word to count its occurrences: ";
    std::cin >> word;

    int wordOccurrences = countWordOccurrences(text, word);
    int sentenceCount = countSentences(text);
    int dotAndCommaCount = countDotsAndCommas(text);
    std::string reversedText = reverseText(text);
    std::string reversedSentences = reverseSentences(text);

    std::cout << "Number of occurrences of the word \"" << word << "\": " << wordOccurrences << std::endl;
    std::cout << "Number of sentences in the text: " << sentenceCount << std::endl;
    std::cout << "Number of dots and commas in the text: " << dotAndCommaCount << std::endl;
    std::cout << "Reversed text: " << reversedText << std::endl;
    std::cout << "Text with reversed sentences: " << reversedSentences << std::endl;

    return 0;
}
