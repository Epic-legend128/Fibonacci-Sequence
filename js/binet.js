function binet(n) {
    return Math.round((Math.pow((1+Math.sqrt(5))/2, n)-Math.pow((1-Math.sqrt(5))/2, n))/Math.sqrt(5));
}
