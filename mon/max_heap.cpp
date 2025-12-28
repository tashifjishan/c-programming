#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

/* Utility function to swap */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify Up (for insertion) */
void heapifyUp(int index) {
    if (index == 0)
        return;

    int parent = (index - 1) / 2;

    if (heap[parent] < heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

/* Insert into Max Heap */
void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
}

/* Heapify Down (for deletion) */
void heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

/* Delete root (max element) */
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

/* Display Heap */
void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

/* Main */
int main() {
    insert(50);
    insert(30);
    insert(40);
    insert(10);
    insert(5);

    printf("Max Heap: ");
    display();

    deleteRoot();

    printf("After Deletion: ");
    display();

    return 0;
}
