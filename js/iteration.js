function iteration(n) {
    if (n <= 1) return n;
    let a = 0n, b = 1n;
    for (let i = 2; i<=n; i++) {
        b = a+b;
        a = b-a;
    }
    return b;
}