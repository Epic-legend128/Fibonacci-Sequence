#include <iostream>

__uint128_t recursion(int n) {
    if (n <= 1) return n;
    return recursion(n-1) + recursion(n-2);
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
    __uint128_t result = recursion(n);
    std::cout << "The "<<n<<"th Fibonacci number is "<<to_string(result)<< std::endl;
    return 0;
}