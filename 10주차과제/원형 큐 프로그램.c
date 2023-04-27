#include <stdio.h>
#define SIZE 5

int front = -1, rear = -1, queue[SIZE];

void enqueue(int item) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
        return;
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
    }
    else if (rear == SIZE - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = item;
}

int dequeue() {
    int item;
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    item = queue[front];
    if (front == rear) {
        front = rear = -1;
    }
    else if (front == SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
    return item;
}

void display() {
    int i;
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    if (front <= rear) {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    else {
        for (i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, item;
    do {
        printf("1. Input data and Enqueue\n");
        printf("2. Dequeue and Print data\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf_s("%d", &item);
            enqueue(item);
            break;
        case 2:
            item = dequeue();
            if (item != -1) {
                printf("Deleted element is: %d\n", item);
            }
            break;
        case 3:
            printf("front = %d, rear = %d : ", &front, &rear);
            break;
        case 4:
            printf("Exiting from program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
