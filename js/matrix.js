const multiply = (h1, h2) => [[h1[0][0]*h2[0][0]+h1[0][1]*h2[1][0], h1[0][0]*h2[0][1]+h1[0][1]*h2[1][1]], [h1[1][0]*h2[0][0]+h1[1][1]*h2[1][0], h1[1][0]*h2[0][1]+h1[1][1]*h2[1][1]]];

function power(matrix, exp) {
    if (exp <= 1) return matrix;
    if (exp%2) return multiply(matrix, power(matrix, exp-1));
    let m = power(matrix, exp/2);
    return multiply(m, m);
}

function matrix(n) {
    if (n <= 0) return 0n;
    if (n <= 2) return 1n;
    if (n == 3) return 2n;
    let matrix = [[1n, 1n], [1n, 0n]];
    let exp = n-3;
    return power(matrix, exp).flat().reduce((t, x) => t+x, 0n);
}