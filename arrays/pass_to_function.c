#include<stdio.h>

// void printArr(int *arr){

//     for(int i=0; i<8; i++){
//         printf("%d\n", *arr);
//         arr= arr+1;
//     }

// }

void printArr(int arr[], int length){

   for(int i=0; i<length; i++){
    printf("%d\n", arr[i]);
   }

}

int main(){
    int numbers[] ={9, 10, 11, 12, 1, 2, 3, 4}; 
    printArr(numbers, 8);
    return 0;
}