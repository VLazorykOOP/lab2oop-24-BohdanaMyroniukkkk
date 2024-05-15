#include <iostream>
#include <string>
#include <bitset>

// ������� ��� ���������� ����� �������� �� 16 �������
std::string padString(const std::string& str) {
    std::string paddedStr = str;
    while (paddedStr.size() < 16) {
        paddedStr += ' ';
    }
    return paddedStr;
}

// ������� ��� ���������� ������� � ��� �����
std::string encryptChar(char ch, int row, int position) {
    std::bitset<8> asciiBits(ch);
    std::bitset<2> rowBits(row);
    std::bitset<4> positionBits(position);
    std::string encrypted;

    // ������� ������� ASCII-����
    encrypted += asciiBits.to_string().substr(0, 4);
    // ����� ����� �����
    encrypted += rowBits.to_string();
    // ������� ����� � �����
    encrypted += positionBits.to_string();
    // ������ ������� ASCII-����
    encrypted += asciiBits.to_string().substr(4, 4);
    // ��� ������� ���� 4-9
    encrypted += (asciiBits.count() % 2 == 0) ? "0" : "1";
    // ��� ������� ���� �������
    encrypted += (asciiBits.count() % 2 == 0) ? "0" : "1";

    return encrypted;
}

int main() {
    // ������� �����
    std::string text[4] = { "Hello", "world", "this", "is" };

    // ���������� ����� �������� �� 16 �������
    for (int i = 0; i < 4; ++i) {
        text[i] = padString(text[i]);
    }

    // ���������� �� ��������� ����������� �����
    std::cout << "Coded text:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 16; ++j) {
            std::string encrypted = encryptChar(text[i][j], i, j);
            std::cout << encrypted << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
