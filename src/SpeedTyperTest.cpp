#include <vector>
#include <iostream>
#include <string>
#include <chrono>

#include "WordBank.hpp"

/*
* @param words - vector<string>& : reference to string vector 
*   Executes typing test and calculates time taken, wpm, accuracy.
*/
void speedTyperTest(const std::vector<std::string>& words, int wordCount) {
    std::string sentence = generateSentence(words, wordCount);

    std::cout << "Type the following sentence: " << sentence << std::endl;

    // Timing Starts Now
    auto start = std::chrono::steady_clock::now();

    int correctWordCount{0};
    for (const auto& word : words) {
        std::string userInput;
        std::cout << word << ": ";
        std::getline(std::cin, userInput);

        if (userInput == word) correctWordCount++;
    }
    // Timing Ends Now
    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double> elapsedTime = end - start;

    double wpm = (words.size() / elapsedTime.count()) * 60;
    double accuracy = (static_cast<double>(correctWordCount) / words.size()) * 100;

    std::cout << "Words Per Minute: " << wpm << std::endl;
    std::cout << "Accuracy: " << accuracy << "%\n";
}