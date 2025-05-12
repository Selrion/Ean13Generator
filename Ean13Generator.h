#pragma once

#include <string>
using namespace std;

class Ean13Generator {
public:
    // Генерация EAN-13 кода по первым 12 цифрам (13-я - контрольная сумма)
    static string generateEan13(const string& code);

    // Проверка валидности EAN-13 кода
    static bool validateEan13(const string& code);

private:
    // Вычисление контрольной суммы
    static char calculateChecksum(const string& code);

    // Валидность кода на числа
    static bool isDigits(const string& str);
};
