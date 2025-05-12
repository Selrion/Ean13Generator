#pragma once
#include <vector>
#include <string>
using namespace std;

class Ean13Barcode {
public:
    explicit Ean13Barcode(const string& ean13Code);

    // �������� �������� ������������� �����-���� (������������������ 0 � 1)
    const vector<int>& getBinaryPattern() const;

    // �������� �������� EAN-13 ���
    const string& getEan13Code() const;

private:
    string ean13Code;
    vector<int> binaryPattern;

    void generateBinaryPattern();
};