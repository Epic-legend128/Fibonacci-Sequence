#include <iostream>
#include <map>

__uint128_t dynamic(int n, std::map<int, __uint128_t>& fib) {
    if (n <= 1) return n;
    if (fib.find(n) != fib.end()) return fib[n];
    fib[n] = dynamic(n-1, fib) + dynamic(n-2, fib);
    return fib[n];
}

__uint128_t dynamic(int n) {
    std::map<int, __uint128_t> fib;
    return dynamic(n, fib);
}

std::string to_string(__uint128_t num) {
    std::string s = "";
    while (num > 0) {
        __uint128_t t = num/10;
        int d = num-t*10;
        s = std::to_string(d) + s;
        num -= d;
        num /= 10;
    }
    if (s == "") return "0";
    return s;
}

int main()  {
    int n = 1000;
    std::cout << "Enter n\n";
    std::cin >> n;
    __uint128_t result = dynamic(n);
    std::cout << "The "<<n<<"th Fibonacci number is "<<to_string(result)<< std::endl;
    return 0;
}