#include "Utilities.hpp"

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> Utilities::splitIntoWords(const std::string& sentence) {
    std::istringstream stream(sentence);
    std::vector<std::string> words;
    std::string word;
    while (stream >> word) {
        words.push_back(word);
    }
    return words;
}
