#include "UserInterface.hpp"
#include "SpeedTyperTest.hpp"
#include <iostream>

// Greets users, lets them proceed or quit test
int UserInterface::greetUser() {
    std::cout << "Hello, and Welcome to SpeedTyper!\n";
    std::cout << "\nYou will be pushed to your absolute limits...\n";
    std::cout << "\nAre you ready? (y/n): ";
    
    char response{};
    std::cin >> response; 
    if (response == 'n') {
        std::cout << "Oh well... Come back another time.\n";
        return 0;
    }

    return 1;
}

// Displays test results to user
void UserInterface::displayResults(SpeedTyperTest& speedTyperTest, double wpm, double accuracy, int wordCount) {
    std::cout << "\n--- Finished Speed Typing Test ! ---\n";
    std::cout << "\n --- Results --- \n";
    std::cout << "Words Per Minute (WPM): " << wpm << std::endl;
    std::cout << "Typing Accuracy: " << accuracy << "%\n";
    std::cout << "Time: " << speedTyperTest.getElapsedTime() << " seconds\n";
    std::cout << "You correctly typed " << speedTyperTest.getCorrectWords() << " out of " << wordCount << " words.\n";
    std::cout << "\n --------------- \n";
}
