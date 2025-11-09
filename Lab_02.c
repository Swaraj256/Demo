/*Design, Develop and Implement a menu driven Program in C for the following operations on STACK of
Integers (Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
c. Demonstrate how Stack can be used to check Palindrome
b. Pop an Element from Stack
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each of the above operations.*/
#include <stdio.h>
#include <string.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", element);
        return;
    }
    stack[++top] = element;
    printf("%d pushed onto stack.\n", element);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    printf("%d popped from stack.\n", stack[top]);
    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

void checkPalindrome() {
    if (top == -1) {
        printf("Stack is empty. Cannot check palindrome.\n");
        return;
    }
    int i = 0, j = top, flag = 1;
    while (i < j) {
        if (stack[i] != stack[j]) {
            flag = 0;
            break;
        }
        i++;
        j--;
    }
    if (flag)
        printf("The stack contents form a palindrome.\n");
    else
        printf("The stack contents do not form a palindrome.\n");
}

int main() {
    int choice, element;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
