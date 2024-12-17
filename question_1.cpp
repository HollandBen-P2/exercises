#include <iostream>

int main();
unsigned long sqrt(unsigned long n);

int main() {
    unsigned long n{};
    std::cin >> n;
    std::cout << sqrt(n);
}

unsigned long sqrt(unsigned long n) {
    unsigned long k{0};
    for (; k*k <= n; ++k) {
        ;
    }
    return k - 1;
}