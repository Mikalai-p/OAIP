#include <iostream>
#include <cmath>


double sum_cos(int n, double x) {
    
    if (n == 1) {
        return cos(x);
    }
    
    else {
        return cos(n * x) + sum_cos(n - 1, x);
    }
}

int main() {
    int n;
    double x;
    std::cout << "Введите n и x: ";
    std::cin >> n >> x;

    // Вычисляем сумму
    double result = sum_cos(n, x);
    std::cout << "Результат: " << result << std::endl;

    return 0;
}