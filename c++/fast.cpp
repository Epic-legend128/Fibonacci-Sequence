#include <iostream>
#include <map>

std::vector<__uint128_t> helper(__uint128_t n) {
    std::vector<__uint128_t> r;
    if (!n) {
        r.push_back(0);
        r.push_back(1);
        return r;
    }

    std::vector<__uint128_t> f = helper(n>>1);
    __uint128_t a = f[0];
    __uint128_t b = f[1];

    __uint128_t c = a*(2*b-a);
    __uint128_t d = b*b + a*a;

    if (n&1) {
        r.push_back(d);
        r.push_back(c+d);
    }
    else {
        r.push_back(c);
        r.push_back(d);
    }
    return r;
}


__uint128_t fast(unsigned int n) {
    return helper(n)[0];
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
    __uint128_t result = fast(n);
    std::cout << "The "<<n<<"th Fibonacci number is "<<to_string(result)<< std::endl;
    return 0;
}