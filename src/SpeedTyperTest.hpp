#ifndef SPEEDTYPERTEST_HPP
#define SPEEDTYPERTEST_HPP

#include "WordBank.hpp"

class SpeedTyperTest {
public:
    SpeedTyperTest(const WordBank& wordBank, int wordCount);
    void startTest();
    double calculateWPM() const;
    double calculateAccuracy() const;

private:
    const WordBank& wordBank_;
    int wordCount_;
    int correctWords_;
    double elapsedTime_;
};

#endif
