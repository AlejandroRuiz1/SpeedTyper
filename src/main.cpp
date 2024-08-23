#include "SpeedTyperTest.hpp"
#include "WordBank.hpp"
#include "UserInterface.hpp"
#include "Utilities.hpp"

#include <iostream>

int main() {
    int greeting {UserInterface::greetUser()};
    if (!greeting) return 0; // User not ready to be pushed to their absolute limits
    
    const std::string filename {"../wordbank.txt"};

    try {
        WordBank wordBank(filename);
        wordBank.loadWords();
        wordBank.shuffleWords();


        // Running SpeedTyperTest
        int wordCount = 10;
        SpeedTyperTest speedTyper(wordBank, wordCount);
        speedTyper.startTest();

        // Calculate results
        double wpm = speedTyper.calculateWPM();
        double accuracy = speedTyper.calculateAccuracy();

        // Present results to user
        UserInterface::displayResults(
            speedTyper,
            wpm,
            accuracy,
            wordCount
        );
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}