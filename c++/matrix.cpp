#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<__uint128_t> >;

Matrix multiply(Matrix h1, Matrix h2) {
    Matrix result;
    std::vector<__uint128_t> temp;
    temp.push_back(h1[0][0]*h2[0][0]+h1[0][1]*h2[1][0]);
    temp.push_back(h1[0][0]*h2[0][1]+h1[0][1]*h2[1][1]);
    result.push_back(temp);
    temp.clear();
    temp.push_back(h1[1][0]*h2[0][0]+h1[1][1]*h2[1][0]);
    temp.push_back(h1[1][0]*h2[0][1]+h1[1][1]*h2[1][1]);
    result.push_back(temp);
    return result;
}

Matrix power(Matrix ma, int exp) {
    if (exp <= 1) return ma;
    if (exp&1) return multiply(power(ma, exp-1), ma);
    Matrix half = power(ma, exp>>1);
    return multiply(half, half);
}

__uint128_t matrix(unsigned int n) {
    if (n <= 0) return 0;
    if (n <= 2) return 1;
    if (n == 3) return 2;
    
    std::vector<__uint128_t> temp(2, 1);
    Matrix m;
    m.push_back(temp);
    temp.clear(); temp.push_back(1);temp.push_back(0);
    m.push_back(temp);
    int exponent = n-3;
    Matrix f = power(m, exponent);
    __uint128_t sum = 0;
    for (auto y: f) {
        for (auto x: y) {
            sum += x;
        }
    }
    return sum;
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
    __uint128_t result = matrix(n);
    std::cout << "The "<<n<<"th Fibonacci number is "<<to_string(result)<< std::endl;
    return 0;
}