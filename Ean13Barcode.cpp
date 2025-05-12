#include "Ean13Barcode.h"
#include "Ean13Patterns.h"
#include "Ean13Generator.h"
#include <stdexcept>

Ean13Barcode::Ean13Barcode(const string& ean13Code) : ean13Code(ean13Code) {
    if (!Ean13Generator::validateEan13(ean13Code)) {
        throw invalid_argument("Invalid EAN-13 code");
    }
    generateBinaryPattern();
}

const vector<int>& Ean13Barcode::getBinaryPattern() const {
    return binaryPattern;
}

const string& Ean13Barcode::getEan13Code() const {
    return ean13Code;
}

void Ean13Barcode::generateBinaryPattern() {
    binaryPattern.clear();

    // Добавляем левый ограничитель
    const auto& guard = Ean13Patterns::getGuardPattern();
    binaryPattern.insert(binaryPattern.end(), guard.begin(), guard.end());

    // Первая цифра определяет кодировку левой части
    char firstDigit = ean13Code[0];
    const string& encodings = Ean13Patterns::getEncodingsForFirstDigit(firstDigit);

    // Кодируем левую часть (6 цифр со 2 по 7)
    for (int i = 1; i <= 6; ++i) {
        char digit = ean13Code[i];
        char encoding = encodings[i - 1];
        const auto& pattern = Ean13Patterns::getLeftPattern(digit, encoding);
        binaryPattern.insert(binaryPattern.end(), pattern.begin(), pattern.end());
    }

    // Добавляем центральный разделитель
    const auto& centerGuard = Ean13Patterns::getCenterGuardPattern();
    binaryPattern.insert(binaryPattern.end(), centerGuard.begin(), centerGuard.end());

    // Кодируем правую часть (5 цифр с 8 по 12)
    for (int i = 7; i <= 12; ++i) {
        char digit = ean13Code[i];
        const auto& pattern = Ean13Patterns::getRightPattern(digit);
        binaryPattern.insert(binaryPattern.end(), pattern.begin(), pattern.end());
    }

    // Добавляем правый ограничитель
    binaryPattern.insert(binaryPattern.end(), guard.begin(), guard.end());
}