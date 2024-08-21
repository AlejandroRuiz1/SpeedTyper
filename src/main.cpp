#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <sstream>

#include "SpeedTyperTest.hpp"
#include "WordBank.hpp"

/*
* @param words - vector<string>& : reference to words vector
* @param wordCount - int : Specifies number of words needed to generate sentence
* @return string : Sentence generated for typing test
*/
std::string generateSentence(const std::vector<std::string>& words, int wordCount) {
    std::ostringstream sentence;
    for (int i = 0; i < wordCount; ++i) {
        if (i != 0) sentence << " ";
        sentence << words[i];
    }
    return sentence.str();
}

// Greets users, lets them proceed or quit test
int greet() {
    std::cout << "Hello, and Welcome to SpeedTyper!\n";
    std::cout << "\nYou will be pushed to your absolute limits...\n";
    std::cout << "Are you ready? (y/n): ";
    
    char response{};
    std::cin >> response; 
    if (response == 'n') {
        std::cout << "Oh well... Come back another time.\n";
        return 1;
    }

    return 0;
}



int main() {
    int greeting {greet()};
    if (!greeting) return 0; // User not ready to be pushed to their absolute limits
    const std::string filename {"../wordbank.txt"};
    std::vector<std::string> words = loadWords(filename);

    int wordCount = 25;
    speedTyperTest(words, wordCount);

    return 0;
}