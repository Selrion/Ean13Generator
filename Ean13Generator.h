#pragma once

#include <string>
#include <random>
using namespace std;

class Ean13Generator {
private:
    // ���������� ����������� �����
    static char calculateChecksum(const string& code);

    // ���������� ���� �� �����
    static bool isDigits(const string& str);

    //��������� ��������� �����
    static string generateRandomDigits(int count);
public:
    // ��������� EAN-13 ���� �� ������ 12 ������ (13-� - ����������� �����)
    static string generateEan13(const string& code);

    // �������� ���������� EAN-13 ����
    static bool validateEan13(const string& code);

    // ��������� ���������� ��������� EAN-13 ����
    static string generateRandomEan13();

    
};



