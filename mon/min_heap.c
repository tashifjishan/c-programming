#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify Up */
void heapifyUp(int index) {
    if (index == 0)
        return;

    int parent = (index - 1) / 2;

    if (heap[parent] > heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

/* Insert */
void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
}

/* Heapify Down */
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

/* Delete root (min element) */
void deleteRoot() {
    if (size == 0) {
        printf("Heap Underflow\n");
        return;
    }

    printf("Deleted: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(20);
    insert(15);
    insert(30);
    insert(5);
    insert(10);

    printf("Min Heap: ");
    display();

    deleteRoot();

    printf("After Deletion: ");
    display();

    return 0;
}
