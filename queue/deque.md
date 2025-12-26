```c

#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

/* Check if deque is full */
int isFull() {
    return (front == (rear + 1) % MAX);
}

/* Check if deque is empty */
int isEmpty() {
    return (front == -1);
}

/* Insert at front */
    void insertFront(int value) {
        if (isFull()) {
            printf("Deque Overflow\n");
            return;
        }

        if (front == -1) { // first element
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }

        deque[front] = value;
    }

/* Insert at rear */
void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) { // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = value;
}

/* Delete from front */
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear) { // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

/* Delete from rear */
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear) { // only one element
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

/* Display deque */
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    printf("Deque elements: ");
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

/* Main function */
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(3);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}


```