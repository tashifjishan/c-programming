#include<stdio.h>
#define max 5
struct stack{
    int arr[max];
    int top;
};
void inItStack(struct stack *s){
    s->top = -1;
}
int isEmpty(struct stack *s){
    return s->top == -1;
}
int isFull(struct stack *s){
    return s->top == max-1;
}
void push(struct stack *s,int data){
    if(isFull(s)){
        printf("Stack overflow");
        return;
    }
    s->top++;
    s->arr[s->top]=data;
}
int pop(struct stack *s){
    if(isEmpty(s)){
        printf("stack underflow");
        return -1;
    }
    int popped = s->arr[s->top];
    s->top--;
    return popped;
}
int peek(struct stack *s){
    if(isEmpty(s)){
        printf("stack is empty");
        return -1;
    }
    return s->arr[s->top];
}
void display(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is empty");
        return;
    }
    printf("stack:\n");
    for(int i=s->top;i>=0;i--){
        printf("%d\n",s->arr[i]);
    }
    printf("\n");
}
int main(){
    struct stack s;
    inItStack(&s);
    push(&s,21);
    push(&s,13);
    push(&s,5);
    display(&s);
    pop(&s);
    display(&s);
    int peek1=peek(&s);
    printf("Top of stack: %d",peek1);
    return 0;
}