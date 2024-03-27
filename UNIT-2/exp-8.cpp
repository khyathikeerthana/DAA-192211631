#include <stdio.h>

int isPrime(int n, int i) {
    if (i == 1) {
        return 1; 
    } else {
        if (n % i == 0) {
            return 0;
        } else {
            return isPrime(n, i - 1); 
        }
    }
}

void generatePrimes(int limit, int num) {
    if (num <= limit) {
        if (isPrime(num, num / 2)) {
            printf("%d ", num);
        }
        generatePrimes(limit, num + 1);
    }
}

int main() {
    int limit;

    printf("Enter the limit to generate prime numbers up to: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are:\n", limit);
    generatePrimes(limit, 2); 

    printf("\n");

    return 0;
}

