#include <stdio.h>
#include <stdbool.h>
bool isPrimeRecursive(int n, int divisor) {
    if (n <= 2)
        return (n == 2);
    if (n % divisor == 0)
        return false;
    if (divisor * divisor > n)
        return true;
    return isPrimeRecursive(n, divisor + 1);
}
bool isPrime(int n) {
    return isPrimeRecursive(n, 2);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPrime(num))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    return 0;
}

