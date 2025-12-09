

#include<stdio.h>
extern int add(int a , int b);
int sub(int a, int b);

int main(){
    printf("%d\n", add(4, 5));
    printf("%d\n", sub(90, 10));
}

// compile: gcc b.c a.c -o main