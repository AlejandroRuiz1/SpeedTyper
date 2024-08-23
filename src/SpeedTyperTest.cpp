#include "WordBank.hpp"
#include "SpeedTyperTest.hpp"
#include "Utilities.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <chrono>
#include <sstream>

SpeedTyperTest::SpeedTyperTest(const WordBank& wordBank, int wordCount) :
    wordBank_(wordBank),
    wordCount_(wordCount),
    correctWords_(0),
    elapsedTime_(0),
    sentence_(""),
    userInputSentence_("") {}

// Executes typing test and calculates elapsed time, wpm, and accuracy.
void SpeedTyperTest::startTest() {
    std::cout << "\n------------------------------------\n\n";

    // Generate sentence
    sentence_ = wordBank_.generateSentence(wordCount_);
    std::cout << "Type the following sentence:\n\n" << sentence_ << '\n';

    // clear input buffer before taking user input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << '\n';

    // Timing Starts Now
    auto start = std::chrono::steady_clock::now();
    std::getline(std::cin, userInputSentence_);

    // for (int i = 0; i < wordCount_; ++i) {
    //     std::string word = wordBank_.getWord(i);
    //     std::string userInput;
    //     std::cout << word << ": ";
    //     std::cin >> userInput;
    //     if (userInput == word) correctWords_++;
    // }

    // Timing Ends Now
    auto end = std::chrono::steady_clock::now();
    elapsedTime_ = std::chrono::duration<double>(end - start).count();

    countCorrectWords_(sentence_,userInputSentence_);
}

// Calculate how many words were typed per minute
double SpeedTyperTest::calculateWPM() const {
    double wpm = (wordCount_ / elapsedTime_) * 60;
    return wpm;
}

// Compare user typed sentence against generated sentence and count how many words were typed correctly
void SpeedTyperTest::countCorrectWords_(const std::string& sentence, const std::string& userSentence) {
    auto correctWords = Utilities::splitIntoWords(sentence);
    auto userInputWords = Utilities::splitIntoWords(userSentence);
    for (int i = 0; i < correctWords.size(); ++i) {
        if (i < userInputWords.size() && correctWords[i] == userInputWords[i]) {
            ++correctWords_;
        }
    }
}

double SpeedTyperTest::calculateAccuracy() const {
    double accuracy = (static_cast<double>(correctWords_) / wordCount_) * 100;
    return accuracy;
}

double SpeedTyperTest::getElapsedTime() const {
    return elapsedTime_;
}

int SpeedTyperTest::getCorrectWords() const {
    return correctWords_;
}
