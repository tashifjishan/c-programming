// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     // Malloc
//     // int *arr = malloc(5*sizeof(*arr));
//     // for(int i=0; i<5; i++){
//     //     arr[i] = i+10;
//     // }

//     // for(int i=0; i<5; i++){
//     //     printf("%d\n", arr[i]);
//     // }
//     // int a;
//     // while(scanf("%d", &a)){
//     //     printf("You entered: %d\n", a);
//     // }
//     // free(arr);

//     // calloc

//     // int *arr = calloc(10, sizeof(*arr));
//     // for(int i=0; i<10; i++){
//     //     printf("%d\n", arr[i]);
//     // }

//     // free(arr);

//     // realloc
//     int *marksArr = calloc(5, sizeof(int));
//     if (!marksArr)
//         return 1;

//     printf("Enter marks below. Enter ~ when done!\n");

//     int currentIndex = 0;
//     int size = 5;

//     while (1)
//     {
//         if (currentIndex == size)
//         {
//             int *temp = realloc(marksArr, (size + 5) * sizeof(int));
//             if (!temp)
//             {
//                 printf("Reallocation failed\n");
//                 free(marksArr);
//                 return 1;
//             }
//             marksArr = temp;
//             size += 5;
//         }

//         int succeed = scanf("%d", &marksArr[currentIndex]);
//         if (succeed != 1)
//         {
//             scanf("%*s"); // consume invalid input like '~'
//             break;
//         }
//         currentIndex++;
//     }

//     for (int i = 0; i < currentIndex; i++)
//     {
//         printf("%d\n", marksArr[i]);
//     }

//     free(marksArr);

//     // return 0;
// }

// // malloc, calloc, realloc, free
// // binary file operations




#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Array;

/* ---------- Internal Helper ---------- */
void resize(Array *arr, int newCapacity) {
    int *temp = realloc(arr->data, newCapacity * sizeof(int));
    if (!temp) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
    arr->data = temp;
    arr->capacity = newCapacity;
}

/* ---------- Initialization ---------- */
void initArray(Array *arr, int initialCapacity) {
    arr->data = malloc(initialCapacity * sizeof(int));
    if (!arr->data) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    arr->size = 0;
    arr->capacity = initialCapacity;
}

/* ---------- Push ---------- */
void push(Array *arr, int value) {
    if (arr->size == arr->capacity) {
        resize(arr, arr->capacity * 2);
    }
    arr->data[arr->size++] = value;
}

/* ---------- Pop ---------- */
int pop(Array *arr) {
    if (arr->size == 0) {
        printf("Array is empty\n");
        return -1;
    }
    return arr->data[--arr->size];
}

/* ---------- Insert at Index ---------- */
void insertAtIndex(Array *arr, int index, int value) {
    if (index < 0 || index > arr->size) {
        printf("Invalid index\n");
        return;
    }

    if (arr->size == arr->capacity) {
        resize(arr, arr->capacity * 2);
    }

    for (int i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }

    arr->data[index] = value;
    arr->size++;
}

/* ---------- Remove at Index ---------- */
int removeAtIndex(Array *arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Invalid index\n");
        return -1;
    }

    int removed = arr->data[index];

    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }

    arr->size--;
    return removed;
}

/* ---------- Print ---------- */
void printArray(Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

/* ---------- Cleanup ---------- */
void freeArray(Array *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

/* ---------- Example Usage ---------- */
int main() {
    Array arr;
    initArray(&arr, 4);

    push(&arr, 10);
    push(&arr, 20);
    push(&arr, 30);
    push(&arr, 40);
    push(&arr, 50);

    printArray(&arr);

    insertAtIndex(&arr, 2, 99);
    printArray(&arr);

    removeAtIndex(&arr, 3);
    printArray(&arr);

    pop(&arr);
    printArray(&arr);

    freeArray(&arr);
    return 0;
}
