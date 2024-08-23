#include "WordBank.hpp"

#include <fstream>
#include <algorithm>
#include <random>
#include <stdexcept>
#include <sstream>

WordBank::WordBank(const std::string& filename) : filename_(filename) {}

void WordBank::loadWords() {
    std::ifstream file(filename_);

    // check if file opens correctly
    if (!file.is_open()) {
        throw std::runtime_error("| Error | - Could not open the file: " + filename_ + '\n');
    }

    std::string word;
    while (file >> word) {
        words_.push_back(word);
    }
    
    if (words_.empty()) {
        throw std::runtime_error("| Error | - File is empty: " + filename_ + '\n');
    }
}

void WordBank::shuffleWords() {
    std::random_device rd;
    std::mt19937 rnGenerator(rd()); // initializing random num generator
    std::shuffle(words_.begin(), words_.end(), rnGenerator);
}

std::string WordBank::getWord(int index) const {
    return words_.at(index);
}

/*
* @param wordCount - int : Specifies number of words needed to generate sentence
* @return string : Sentence generated for typing test
*/
std::string WordBank::generateSentence(int wordCount) const {
    std::ostringstream sentence;
    for (int i = 0; i < wordCount; ++i) {
        if (i != 0) sentence << " ";
        sentence << words_[i];
    }
    return sentence.str();
}