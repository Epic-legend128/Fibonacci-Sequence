function dynamic(n, fib=[]) {
    if (n <= 1) return BigInt(n);
    if (fib[n] != undefined) return fib[n];
    fib[n] = BigInt(dynamic(n-1, fib)+dynamic(n-2, fib));
    return fib[n];
}
