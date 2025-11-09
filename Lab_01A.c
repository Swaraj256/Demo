//Write a program to accept 'n' numbers into an array and then calculate the sum of numbers present in odd positions and even positions respectively
#include <stdio.h>

int main() {
    int n, i;
    int sumOdd = 0, sumEven = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0)
            sumEven += arr[i]; 
        else
            sumOdd += arr[i];  
    }

    printf("\nSum of numbers at odd positions: %d", sumOdd);
    printf("\nSum of numbers at even positions: %d", sumEven);

    return 0;
}
