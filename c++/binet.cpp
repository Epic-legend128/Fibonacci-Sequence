#include <iostream>

long long binet(unsigned int n) {
    return (long double)(pow((long double)(1+(long double)sqrt(5))/2, n)-pow((long double)(1-(long double)sqrt(5))/2, n))/sqrt(5);
}

int main()  {
    unsigned int n;
    std::cout << "Enter n\n";
    std::cin >> n;
    long long result = binet(n);
    std::cout << "The "<<n<<"th Fibonacci number is "<<result<< std::endl;
    return 0;
}