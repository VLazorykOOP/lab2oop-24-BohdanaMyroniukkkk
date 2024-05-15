#include <iostream>
#include <string>
#include <bitset>

// Функція для доповнення рядка пробілами до 16 символів
std::string padString(const std::string& str) {
    std::string paddedStr = str;
    while (paddedStr.size() < 16) {
        paddedStr += ' ';
    }
    return paddedStr;
}

// Функція для шифрування символу у два байти
std::string encryptChar(char ch, int row, int position) {
    std::bitset<8> asciiBits(ch);
    std::bitset<2> rowBits(row);
    std::bitset<4> positionBits(position);
    std::string encrypted;

    // Молодша частина ASCII-коду
    encrypted += asciiBits.to_string().substr(0, 4);
    // Номер рядка букви
    encrypted += rowBits.to_string();
    // Позиція букви у рядку
    encrypted += positionBits.to_string();
    // Старша частина ASCII-коду
    encrypted += asciiBits.to_string().substr(4, 4);
    // Біт парності полів 4-9
    encrypted += (asciiBits.count() % 2 == 0) ? "0" : "1";
    // Біт парності коду символу
    encrypted += (asciiBits.count() % 2 == 0) ? "0" : "1";

    return encrypted;
}

int main() {
    // Заданий текст
    std::string text[4] = { "Hello", "world", "this", "is" };

    // Доповнення рядків пробілами до 16 символів
    for (int i = 0; i < 4; ++i) {
        text[i] = padString(text[i]);
    }

    // Шифрування та виведення закодованих байтів
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
