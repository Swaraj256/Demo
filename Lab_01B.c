/* 1B.Write a program to implement a Binary Search algorithm.
 Write a search function which takes a SearchList as its first parameter and a Comparable as its second. 
 If either parameter is null, or if the SearchList is empty, you should return NULL.
implement the following algorithm:
Examine the value in the middle of the current array and print it.
If the midpoint value is the value that we are looking for, return true
If the value that we are looking for is greater than the midpoint value, adjust the current array to start at the midpoint and print the index.
if the value that we are looking for is less than the midpoint value, adjust the current array to end at the midpoint and print the index.
Continue until you find the value, or until the start reaches the end. */
#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    if (arr == NULL || n == 0)
        return -1;

    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        printf("Examining value: %d\n", arr[mid]);

        if (arr[mid] == target) {
            printf("Found value at index: %d\n", mid);
            return mid;
        } else if (target > arr[mid]) {
            printf("Target greater than midpoint, adjusting start to index: %d\n", mid + 1);
            start = mid + 1;
        } else {
            printf("Target less than midpoint, adjusting end to index: %d\n", mid - 1);
            end = mid - 1;
        }
    }

    printf("Value not found.\n");
    return -1;
}

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter value to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);
    if (result != -1)
        printf("Result: Found at index %d\n", result);
    else
        printf("Result: Value not found or invalid input.\n");

    return 0;
}
