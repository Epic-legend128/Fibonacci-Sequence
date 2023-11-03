function helper(n) {
    if (!n) {
        return [0n, 1n];
    }

    let f = helper(Math.floor(n/2));
    let a = f[0];
    let b = f[1];

    let c = a * (2n * b - a);
    let d = b*b + a*a;

    if (n%2) {
        return [d, c+d];
    }
    return [c, d];
}

function fast(n) {
    return helper(n)[0];
}