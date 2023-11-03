function recursive(n) {
    if (n <= 1) return n;
    return BigInt(recursive(n-1)+recursive(n-2));
}