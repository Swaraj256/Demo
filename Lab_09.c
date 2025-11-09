/*Assume that you have a seven-slot closed hash table (the slots are numbered o through 6)
 Write program to final hash table that would result if you used the hash function h(k)-k mod 7.*/
#include <stdio.h>
#define SIZE 7
int main() {
    int hashTable[SIZE];
    int i, key, n, index, j;

    // Initialize hash table with -1
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter the keys:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        index = key % SIZE;  // h(k) = k mod 7

        // Handle collision using linear probing
        j = index;
        while (hashTable[j] != -1) {
            j = (j + 1) % SIZE;
            if (j == index) {
                printf("Hash table is full!\n");
                break;
            }
        }
        if (hashTable[j] == -1)
            hashTable[j] = key;
    }

    // Display final hash table
    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++)
        printf("Slot %d : %d\n", i, hashTable[i]);

    return 0;
}
