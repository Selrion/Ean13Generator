#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;

class Ean13Patterns {
private:
    static const map<char, vector<int>> leftLPatterns;
    static const map<char, vector<int>> leftGPatterns;
    static const map<char, vector<int>> rightPatterns;
    static const map<char, string> firstDigitEncodings;
    static const vector<int> guardPattern;
    static const vector<int> centerGuardPattern;

public:
    // �������� ������� ��� ����� ����� �� ����� � ���� ��������� (L/G)
    static const vector<int>& getLeftPattern(char digit, char encoding);

    // �������� ������� ��� ������ ����� �� �����
    static const vector<int>& getRightPattern(char digit);

    // �������� ��������� ��� ����� ����� �� ������ �����
    static const string& getEncodingsForFirstDigit(char firstDigit);

    // �������� �������� ������������
    static const vector<int>& getGuardPattern();
    static const vector<int>& getCenterGuardPattern();


};


