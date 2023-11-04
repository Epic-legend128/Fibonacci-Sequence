#include <iostream>

__uint128_t iteration(unsigned int n) {
    if (n <= 1) return n;
    __uint128_t a=0,b=1;
    for (int i = 2; i<=n; i++) {
        b += a;
        a = b-a;
    }
    return b;
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
    unsigned int n;
    std::cout << "Enter n\n";
    std::cin >> n;
    __uint128_t result = iteration(n);
    std::cout << "The "<<n<<"th Fibonacci number is "<<to_string(result)<< std::endl;
    return 0;
}