# Priority Queue – Explanation & Implementation (C, using structure)

- A priority queue is a special type of queue where each element has a priority.

- Elements are removed based on priority, not just arrival time.
- Higher priority element is served first
- If priorities are equal → follow FIFO

## Types of Priority Queue

- Ascending Priority Queue
- Smaller value = higher priority
## Descending Priority Queue
- Larger value = higher priority
(Here we implement descending priority)

# Priority Queue Operations

- Insert (enqueue) – insert element based on priority
- Delete (dequeue) – remove highest priority element
- Display


```c

#include <stdio.h>
#define MAX 5

// Define structure
struct PriorityQueue {
    int data[MAX];
    int priority[MAX];
    int size;
};

// Initialize queue
void initQueue(struct PriorityQueue *pq) {
    pq->size = 0;
}

// Insert element
void enqueue(struct PriorityQueue *pq, int value, int pr) {
    int i;

    if (pq->size == MAX) {
        printf("Priority Queue Overflow\n");
        return;
    }

    // Find position based on priority
    for (i = pq->size - 1; i >= 0; i--) {
        if (pq->priority[i] < pr) {
            pq->data[i + 1] = pq->data[i];
            pq->priority[i + 1] = pq->priority[i];
        } else {
            break;
        }
    }

    pq->data[i + 1] = value;
    pq->priority[i + 1] = pr;
    pq->size++;

    printf("%d inserted with priority %d\n", value, pr);
}

// Remove highest priority element
void dequeue(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue Underflow\n");
        return;
    }

    printf("%d removed (priority %d)\n",
           pq->data[0], pq->priority[0]);

    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }

    pq->size--;
}

// Display queue
void display(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Value  Priority\n");
    for (int i = 0; i < pq->size; i++) {
        printf("%5d  %8d\n", pq->data[i], pq->priority[i]);
    }
}

int main() {
    struct PriorityQueue pq;
    initQueue(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 5);
    enqueue(&pq, 30, 1);
    enqueue(&pq, 40, 4);

    display(&pq);

    dequeue(&pq);
    dequeue(&pq);

    display(&pq);

    return 0;
}


```