#include <stdio.h>
#define MAX 5

struct Queue {
    int data[MAX];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Enqueue operation
void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;

    q->data[++q->rear] = value;
    printf("%d inserted into queue\n", value);
}

// Dequeue operation
void dequeue(struct Queue *q){
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d removed from queue\n", q->data[q->front++]);
}

// Display front element
void peek(struct Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", q->data[q->front]);
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    peek(&q);

    dequeue(&q);
    dequeue(&q);

    return 0;
}

/*




1. Take exam
2. View Result
3. Analyse
4. print question paper
5. exit



*/