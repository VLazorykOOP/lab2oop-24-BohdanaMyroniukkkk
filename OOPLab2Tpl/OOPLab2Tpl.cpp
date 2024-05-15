#include <iostream>

int main() {
    int a, b, c, d;

    // Введення значень a, b, c, d
    std::cout << "Enter a value a: ";
    std::cin >> a;
    std::cout << "Enter a value b: ";
    std::cin >> b;
    std::cout << "Enter a value c: ";
    std::cin >> c;
    std::cout << "Enter a value d: ";
    std::cin >> d;

    // Обчислення виразу без використання операцій множення та ділення
    int result = (b << 10) + ((d << 4) + (a << 3)) - ((c << 12) + (c << 2)) + (d << 3);

    // Outputting the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}
