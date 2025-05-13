#include "Ean13Barcode.h"
#include "Ean13Patterns.h"
#include "Ean13Generator.h"
#include "iostream"

int main() 
{
    try {
        // Вариант 1: Генерация по известным 12 цифрам 
        string partialCode = "460005100005";
        string ean13Code = Ean13Generator::generateEan13(partialCode);
        cout << "Generated from known prefix: " << ean13Code << endl;

        // Вариант 2: Полностью случайная генерация 
        string randomEan13 = Ean13Generator::generateRandomEan13();
        cout << "Randomly generated EAN-13: " << randomEan13 << endl;

        // Создание штрих-кода для случайного кода 
        Ean13Barcode barcode(randomEan13);

        // Вывод двоичного паттерна 
        const auto& pattern = barcode.getBinaryPattern();
        cout << "Binary pattern: ";
        for (int bit : pattern) 
        {
            cout << bit;
        }
        cout << endl;

        // Проверка валидности 
        bool isValid = Ean13Generator::validateEan13(randomEan13);
        cout << "Is valid: " << (isValid ? "Yes" : "No") << endl;

    }
    catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}