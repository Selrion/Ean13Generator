#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;

class Ean13Patterns {
private:
    static const map<char, vector<int>> leftLPatterns;
    static const map<char, vector<int>> leftGPatterns;
    static const map<char, vector<int>> rightPatterns;
    static const map<char, string> firstDigitEncodings;
    static const vector<int> guardPattern;
    static const vector<int> centerGuardPattern;

public:
    // Получить паттерн для левой части по цифре и типу кодировки (L/G)
    static const vector<int>& getLeftPattern(char digit, char encoding);

    // Получить паттерн для правой части по цифре
    static const vector<int>& getRightPattern(char digit);

    // Получить кодировки для левой части по первой цифре
    static const string& getEncodingsForFirstDigit(char firstDigit);

    // Получить паттерны разделителей
    static const vector<int>& getGuardPattern();
    static const vector<int>& getCenterGuardPattern();


};


