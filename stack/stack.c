#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack
{
    int arr[MAX];
    int top;
};

void inItStack(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

int isFull(struct Stack *s)
{
    return s->top == MAX - 1;
}

void push(struct Stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }

    s->top++;
    s->arr[s->top] = data;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int popped = s->arr[s->top];
    s->top--;
    return popped;
}

int peek(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }

    return s->arr[s->top];
}

void display(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = s->top; i >= 0; i--)
        printf("%d\n", s->arr[i]);
}

int main()
{
    struct Stack s;
    
    inItStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    printf("Popped element: %d\n", pop(&s));
    printf("Top element: %d\n", peek(&s));

    display(&s);

    return 0;
}
