A circular queue is an improved version of a simple queue where the last position is connected back to the first.
This avoids the wasted space problem of a normal queue.

Key idea

- Uses modulus (%) to wrap around the array.



# Conditions

- Queue Full

(rear + 1) % MAX == front


- Queue Empty

front == -1

# Circular Queue Implementation in C (Using struct)
```c
#include <stdio.h>
#define MAX 5

struct CircularQueue {
    int data[MAX];
    int front;
    int rear;
};

// Initialize queue
void initQueue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is full
int isFull(struct CircularQueue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Check if queue is empty
int isEmpty(struct CircularQueue *q) {
    return (q->front == -1);
}

// Enqueue operation
void enqueue(struct CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Circular Queue Overflow\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    printf("%d inserted into circular queue\n", value);
}

// Dequeue operation
void dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular Queue Underflow\n");
        return;
    }

    printf("%d removed from circular queue\n", q->data[q->front]);

    if (q->front == q->rear) {
        // Queue becomes empty
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

// Display queue elements
void display(struct CircularQueue *q) {
    int i;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    i = q->front;
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    struct CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    enqueue(&q, 50);
    enqueue(&q, 60);

    display(&q);

    return 0;
}

```