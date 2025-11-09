/*Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of
 Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to QUEUE
b. Delete an Element from QUEUE
c. Demonstrate Overflow and Underflow situations on QUEUE
d. Display the status of QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations.*/
#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void insert(char element) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert '%c'.\n", element);
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = element;
    printf("'%c' inserted into queue.\n", element);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot delete.\n");
        front = rear = -1;
        return;
    }
    printf("'%c' deleted from queue.\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements (front to rear): ");
    for (int i = front; i <= rear; i++)
        printf("%c ", queue[i]);
    printf("\n");
}

int main() {
    int choice;
    char element;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
