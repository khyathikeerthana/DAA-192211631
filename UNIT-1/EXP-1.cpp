#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacci(int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", fibonacci(i));
    }
}

int main() {
    int count;

    
    printf("Enter the number of terms of Fibonacci series: ");
    scanf("%d", &count);

    printf("Fibonacci Series: ");
    printFibonacci(count);

    return 0;
}

