#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *queue) {
    queue->front = 0;
    queue->rear = 0;
}

int isQueueEmpty(CircularQueue *queue) {
    return queue->front == queue->rear;
}

int isQueueFull(CircularQueue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(CircularQueue *queue, int item) {
    if (isQueueFull(queue)) {
        printf("Queue is full.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = item;
}

int dequeue(CircularQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    queue->front = (queue->front + 1) % MAX_SIZE;
    int item = queue->data[queue->front];
    return item;
}

void displayQueue(CircularQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    printf("Queue: ");
    do {
        i = (i + 1) % MAX_SIZE;
        printf("%d ", queue->data[i]);
    } while (i != queue->rear);
    printf("\n");
}

int main() {
    CircularQueue queue;
    initQueue(&queue);

    int choice, item;

    while (1) {
        printf("\n***** Menu *****\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        printf("5. Print List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                item = dequeue(&queue);
                if (item != -1)
                    printf("Dequeued item: %d\n", item);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
