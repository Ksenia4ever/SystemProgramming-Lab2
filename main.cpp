#include <iostream>
#include <cmath>
#include <chrono>

constexpr int N = 100000000;

__attribute__((noinline))
double calculateSin() {
    volatile double result = 0;
    for (int i = 1; i <= N; ++i) {
        result = result + std::sin(i * 0.001);
    }
    return result;
}

__attribute__((noinline))
double calculateSqrt() {
    volatile double result = 0;
    for (int i = 1; i <= N; ++i) {
        result = result + std::sqrt(i);
    }
    return result;
}

__attribute__((noinline))
double processData() {
    double a = calculateSin();
    double b = calculateSqrt();
    return a + b;
}

int main() {
    auto start = std::chrono::steady_clock::now();

    double result = processData();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Result: " << result << '\n';
    std::cout << "Time: " << elapsed.count() << " s\n";

    return 0;
}
