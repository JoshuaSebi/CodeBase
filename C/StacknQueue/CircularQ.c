#include <stdio.h>
#define size 7

int queue[size], front = -1, rear = -1, item;

void enqueue(int item) {
    if ((rear + 1) % size == front) {
        printf("Overflow Condition\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = item;
    } else {
        rear = (rear + 1) % size;
        queue[rear] = item;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow Condition\n");
    } else if (front == rear) {
        printf("%d ", queue[front]);
        front = rear = -1;
    } else {
        printf("%d ", queue[front]);
        front = (front + 1) % size;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % size;
        }
        printf("%d\n", queue[rear]);
    }
}

void main() {
    int choice;
    char y;
    do {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Exit....\n");
                break;
        }
        printf("Do you want to continue (y/n): ");
        scanf(" %c", &y);
    } while (y == 'Y' || y == 'y');
}
