# Fibonacci-Sequence
In this repository I discuss multiple different ways of calculating the fibonacci sequence.

## Table of Contents
  - [What is the Fibonacci Sequence](#what-is-the-fibonacci-sequence)
  - [Iteration](#iteration)
  - [Recursion](#recursion)
  - [Dynamic Programming with Memoization](#dynamic-programming-with-memoization)
  - [Matrix Exponentiation](#matrix-exponentiation)
  - [Fast Doubling](#fast-doubling)
  - [Binet's Formula](#binets-formula)

## What is the Fibonacci Sequence
The Fibonacci Sequence is a sequence in mathematics in which each term is the sum of the 2 previous terms. The recursive mathematival definition is F(n) = F(n-1) + F(n-2). The first 2 terms are 0 and 1, and then the sequence continues as 1,2,3,5,8 etc. Sometimes the first 2 terms are defined as 1 and 1 instead of 0 and 1.

## Iteration
One of the easiest ways to compute the nth term in the fibonacci sequence is by using a simple for loop starting from the first 2 terms(0 and 1) and building your way upwards towards the term you are looking for(bottom-up approach). Therefore, the code would look something like this in C++:
```
__uint128_t iteration(unsigned int n) {
    if (n <= 1) return n;
    __uint128_t a=0,b=1;
    for (int i = 2; i<=n; i++) {
        b += a;
        a = b-a;
    }
    return b;
}
```
This algorithm is of course not optimal as it unecessarily calculates all terms of the Fibonacci sequence up until the one you are looking for whereas it should only be calculating the nth term. The asymptotic time notation is O(n) so this method is only useful when trying to calculate mutliple terms of the sequence.

## Recursion
The most straightforward and easy way to tackle this problem is to use recursion. We take advantage of the fact that F(n) = F(n-1) + F(n-2) and plug it directly into a nice recursive function with a simple base case of when n <= 1 then it should just return n(F(0) = 0, F(1) = 1). This means that the code needed is just a few lines, like so:
```
__uint128_t recursion(unsigned int n) {
    if (n <= 1) return n;
    return recursion(n-1) + recursion(n-2);
}
```
Even though this is very simple to code, its asymptotic time notation is roughly O(2^n), which is superpolynomial and will therefore need a lot of time to calculate even the 50th term. However, it helps us build the next solution with dynamic programming and memoization which is a lot more efficient.

## Dynamic Programming with Memoization
This solution improves upon the plain recursive function that we built. So, what makes the recursive solution so slow? The reason lies in the fact that it is constantly calculating terms which we have already calculated previously. So how could we avoid repeating the same call to the function with the same exact arguments? Well, we could use a concept called memoization which basically saves all of our previous solutions in a data structure, which in this case we'll use a hash map, although you could also use an array or a vector(it's actually better to use an array or vector of size n for this case). So every time we find F(n) we store it in our nice little map and if we ever happen to make a call to the function to calculate F(n) again then we can just return what we have saved in our map. So with an extra 2 lines of code we have immensely increased the efficiency of our algorithm.
```
__uint128_t dynamic(unsigned int n, std::map<unsigned int, __uint128_t>& fib) {
    if (n <= 1) return n;
    if (fib.find(n) != fib.end()) return fib[n];
    fib[n] = dynamic(n-1, fib) + dynamic(n-2, fib);
    return fib[n];
}
```
and we can also overload the function so that it accepts a call with only one parameter if you are not going to use the map again.
```
__uint128_t dynamic(unsigned int n) {
    std::map<unsigned int, __uint128_t> fib;
    return dynamic(n, fib);
}
```
And that's it. This solution is also completed. It is very short and relatively fast compared to our last solution. It's asymptotic time notation is also O(n) as it only calculates each term once, and it basically is like our iterative solution but it starts from the last term and goes towards the first 2(top-down approach). So, this is also not optimal as it calculates a lot of unnecessary terms and also takes up a lot of space.

## Matrix Exponentiation

## Fast Doubling

## Binet's Formula






