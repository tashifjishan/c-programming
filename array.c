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

int main()
{

    Array students = {calloc(5, sizeof(int)), 0, 5};
    push(&students, 90);
    push(&students, 100);
    push(&students, 87);
    push(&students, 96);
    push(&students, 45);
    push(&students, 98);
    push(&students, 12);
    push(&students, 15);
    push(&students, 98);
    push(&students, 19);

    printArr(&students);
    free(students.data);
}