#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *data;
    int currentIndex;
    int capacity;
};

typedef struct Array Array;

void push(Array *arr, int element)
{
    if (arr->currentIndex == arr->capacity)
    {
        int *temp = realloc(arr->data, (arr->capacity + 5) * sizeof(int));
        if (!temp)
        {
            printf("Memory reallocation fails!");
            return;
        }

        arr->data = temp;
        arr->capacity = arr->capacity + 5;
    }

    arr->data[arr->currentIndex++] = element;
}

void printArr(Array *arr)
{
    for (int i = 0; i < arr->currentIndex; i++)
    {
        printf("%d\n", arr->data[i]);
    }
    printf("Done!\n");
}

void insert(Array *arr, int index, int element)
{
    if (index < 0 || index > arr->currentIndex)
    {
        printf("Invalid index!");
        return;
    }
    if (arr->capacity == arr->currentIndex)
    {
        int *temp = realloc(arr->data, sizeof(int) * (arr->capacity + 5));

        if (!temp)
        {
            printf("Could not insert at the specified index!\n");
            return;
        }

        arr->data = temp;
        arr->capacity = arr->capacity + 5;
    }

    for (int i = arr->currentIndex; i > index; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }

    arr->data[index] = element;

    arr->currentIndex++;
}

int main()
{

    Array students = {calloc(5, sizeof(int)), 0, 5};
    push(&students, 90);
    push(&students, 100);
    push(&students, 87);
    
    insert(&students, 1, 120);
    insert(&students, 0, 987);

    printArr(&students);
    free(students.data);
}