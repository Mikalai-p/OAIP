#include <iostream>

int F(int m, int n) {
    if (m == 0 || n == 0) {
        return n + 1;
    }
    else {
        return F(m - 1, F(m, n - 1));
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int m, n;
    std::cout << "Введите m и n: ";
    std::cin >> m >> n;
    std::cout << "F(" << m << ", " << n << ") = " << F(m, n) << std::endl;
    return 0;
}