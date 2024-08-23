#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "SpeedTyperTest.hpp"

class UserInterface {
public:
    static void displayResults(SpeedTyperTest& speedTyperTest, double wpm, double accuracy, int wordCount);
    static int greetUser();
};

#endif
