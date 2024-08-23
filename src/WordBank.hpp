#ifndef WORDBANK_HPP
#define WORDBANK_HPP

#include <vector>
#include <string>

class WordBank {
    public:
        WordBank(const std::string& filename);
        void loadWords();
        void shuffleWords();
        std::string getWord(int index) const;
        std::string generateSentence(int wordCount) const;

    private:
        std::vector<std::string> words_;
        std::string filename_;
};

#endif