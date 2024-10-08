#ifndef SPEEDTYPERTEST_HPP
#define SPEEDTYPERTEST_HPP

#include "WordBank.hpp"

class SpeedTyperTest {
public:
    SpeedTyperTest(const WordBank& wordBank, int wordCount);
    void startTest();
    double calculateWPM() const;
    double calculateAccuracy() const;
    double getElapsedTime() const;
    int getCorrectWords() const;

private:
    const WordBank& wordBank_;
    void countCorrectWords_(const std::string &sentence, const std::string &userSentence);
    int wordCount_;
    int correctWords_;
    double elapsedTime_;
    std::string sentence_;
    std::string userInputSentence_;
};

#endif
