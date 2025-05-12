#pragma once
#include <vector>
#include <string>
using namespace std;

class Ean13Barcode {
public:
    explicit Ean13Barcode(const string& ean13Code);

    // Получаем двоичное представление штрих-кода (последовательность 0 и 1)
    const vector<int>& getBinaryPattern() const;

    // Получаем исходный EAN-13 код
    const string& getEan13Code() const;

private:
    string ean13Code;
    vector<int> binaryPattern;

    void generateBinaryPattern();
};