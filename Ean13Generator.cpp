#include "Ean13Generator.h"
#include <stdexcept>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>



char Ean13Generator::calculateChecksum(const string& code) 
{
    int sum = 0;
    for (size_t i = 0; i < 12; ++i) 
    {
        int digit = code[i] - '0';
        sum += (i % 2 == 0) ? digit : digit * 3;
    }
    int checksum = (10 - (sum % 10)) % 10;
    return '0' + checksum;
}

bool Ean13Generator::isDigits(const string& str) 
{
    return all_of(str.begin(), str.end(), ::isdigit);
}

string Ean13Generator::generateEan13(const string& code) 
{
    if (code.length() != 12 || !isDigits(code)) 
    {
        throw invalid_argument("Input must be 12-digit string");
    }

    return code + calculateChecksum(code);
}

bool Ean13Generator::validateEan13(const string& code) 
{
    if (code.length() != 13 || !isDigits(code)) 
    {
        return false;
    }

    char expectedChecksum = calculateChecksum(code.substr(0, 12));
    return code[12] == expectedChecksum;
}

string Ean13Generator::generateRandomDigits(int count) 
{
    string result;
    result.reserve(count);

    // Инициализация генератора случайных чисел 
    unsigned seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
    static mt19937 generator(seed);
    uniform_int_distribution<int> distribution(0, 9);

    for (int i = 0; i < count; ++i) 
    {
        result.push_back('0' + distribution(generator));
    }

    return result;
}

string Ean13Generator::generateRandomEan13() 
{
    // Генерируем 12 случайных цифр 
    string partialCode = generateRandomDigits(12);

    // Добавляем контрольную сумму 
    return generateEan13(partialCode);
}
