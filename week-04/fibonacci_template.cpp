#include <iostream>

template <size_t N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};
template <size_t N>
void printFibonacci() {
    if constexpr (N > 0) {
        printFibonacci<N - 1>();
    }
     std::cout << "Fibonacci(" << N << ") = " << Fibonacci<N>::value << std::endl;
}

int main() {
    printFibonacci<10>();
    return 0;
}