#pragma once

#include <string>
using namespace std;

class Ean13Generator {
public:
    // ��������� EAN-13 ���� �� ������ 12 ������ (13-� - ����������� �����)
    static string generateEan13(const string& code);

    // �������� ���������� EAN-13 ����
    static bool validateEan13(const string& code);

private:
    // ���������� ����������� �����
    static char calculateChecksum(const string& code);

    // ���������� ���� �� �����
    static bool isDigits(const string& str);
};
