#include <stdio.h>

void generateFibonacci(int n) {
    // Handle special cases
    if (n <= 0) {
        printf("Please enter a positive number of terms.\n");
        return;
    }
    if (n == 1) {
        printf("Fibonacci Sequence: 0\n");
        return;
    }

    long long first = 0, second = 1, next;
    printf("Fibonacci Sequence: %lld, %lld", first, second);

    for (int i = 3; i <= n; i++) {
        next = first + second;
        printf(", %lld", next);
        first = second;
        second = next;
    }
    printf("\n");
}

int main() {
    int terms;

    // Prompt the user for the number of terms
    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &terms);

    // Generate and display the Fibonacci sequence
    generateFibonacci(terms);

    return 0;
}
