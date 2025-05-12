#include "Ean13Generator.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

char Ean13Generator::calculateChecksum(const string& code) {
    int sum = 0;
    for (size_t i = 0; i < 12; ++i) {
        int digit = code[i] - '0';
        sum += (i % 2 == 0) ? digit : digit * 3;
    }
    int checksum = (10 - (sum % 10)) % 10;
    return '0' + checksum;
}

bool Ean13Generator::isDigits(const string& str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}

string Ean13Generator::generateEan13(const string& code) {
    if (code.length() != 12 || !isDigits(code)) {
        throw invalid_argument("Input must be 12-digit string");
    }

    return code + calculateChecksum(code);
}

bool Ean13Generator::validateEan13(const string& code) {
    if (code.length() != 13 || !isDigits(code)) {
        return false;
    }

    char expectedChecksum = calculateChecksum(code.substr(0, 12));
    return code[12] == expectedChecksum;
}
