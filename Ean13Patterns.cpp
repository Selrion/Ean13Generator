#include "Ean13Patterns.h"
using namespace std;

// L-паттерны для левой части 
const map<char, vector<int>> Ean13Patterns::leftLPatterns = 
{
    {'0', {0,0,0,1,1,0,1}},
    {'1', {0,0,1,1,0,0,1}},
    {'2', {0,0,1,0,0,1,1}},
    {'3', {0,1,1,1,1,0,1}},
    {'4', {0,1,0,0,0,1,1}},
    {'5', {0,1,1,0,0,0,1}},
    {'6', {0,1,0,1,1,1,1}},
    {'7', {0,1,1,1,0,1,1}},
    {'8', {0,1,1,0,1,1,1}},
    {'9', {0,0,0,1,0,1,1}}
};

// G-паттерны для левой части 
const map<char, vector<int>> Ean13Patterns::leftGPatterns = 
{
    {'0', {0,1,0,0,1,1,1}},
    {'1', {0,1,1,0,0,1,1}},
    {'2', {0,0,1,1,0,1,1}},
    {'3', {0,1,0,0,0,0,1}},
    {'4', {0,0,1,1,1,0,1}},
    {'5', {0,1,1,1,0,0,1}},
    {'6', {0,0,0,0,1,0,1}},
    {'7', {0,0,1,0,0,0,1}},
    {'8', {0,0,0,1,0,0,1}},
    {'9', {0,0,1,0,1,1,1}}
};

// Паттерны для правой части 
const map<char, vector<int>> Ean13Patterns::rightPatterns = 
{
    {'0', {1,1,1,0,0,1,0}},
    {'1', {1,1,0,0,1,1,0}},
    {'2', {1,1,0,1,1,0,0}},
    {'3', {1,0,0,0,0,1,0}},
    {'4', {1,0,1,1,1,0,0}},
    {'5', {1,0,0,1,1,1,0}},
    {'6', {1,0,1,0,0,0,0}},
    {'7', {1,0,0,0,1,0,0}},
    {'8', {1,0,0,1,0,0,0}},
    {'9', {1,1,1,0,1,0,0}}
};

// Кодировки для первой цифры 
const map<char, string> Ean13Patterns::firstDigitEncodings = 
{
    {'0', "LLLLLL"},
    {'1', "LLGLGG"},
    {'2', "LLGGLG"},
    {'3', "LLGGGL"},
    {'4', "LGLLGG"},
    {'5', "LGGLLG"},
    {'6', "LGGGLL"},
    {'7', "LGLGLG"},
    {'8', "LGLGGL"},
    {'9', "LGGLGL"}
};

// Паттерны разделителей 
const vector<int> Ean13Patterns::guardPattern = { 1, 0, 1 };
const vector<int> Ean13Patterns::centerGuardPattern = { 0, 1, 0, 1, 0 };

const vector<int>& Ean13Patterns::getLeftPattern(char digit, char encoding) 
{
    if (encoding == 'L') 
    {
        return leftLPatterns.at(digit);
    }
    else {
        return leftGPatterns.at(digit);
    }
}

const vector<int>& Ean13Patterns::getRightPattern(char digit) 
{
    return rightPatterns.at(digit);
}

const string& Ean13Patterns::getEncodingsForFirstDigit(char firstDigit) 
{
    return firstDigitEncodings.at(firstDigit);
}

const vector<int>& Ean13Patterns::getGuardPattern() 
{
    return guardPattern;
}

const vector<int>& Ean13Patterns::getCenterGuardPattern() 
{
    return centerGuardPattern;
}