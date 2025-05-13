#pragma once
#include <vector>
#include <string>
using namespace std;

class Ean13Barcode {
private:
    string ean13Code;
    vector<int> binaryPattern;

    void generateBinaryPattern();

public:
    explicit Ean13Barcode(const string& ean13Code);

    // Получить двоичное представление штрих-кода (последовательность 0 и 1)
    const vector<int>& getBinaryPattern() const;

    // Получить исходный EAN-13 код
    const string& getEan13Code() const;

};