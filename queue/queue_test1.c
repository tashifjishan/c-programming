#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue{
    int data[MAX];
    int front,rear;
};
void inItQueue(struct queue *q){
    q->front = -1;
    q->rear = -1;
}
void enqueue(struct queue *q,int data){
    if(q->rear == MAX-1){
        printf("queue overflow");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->data[++q->rear]=data;
    printf("%d inserted into queue\n",data);
}
void dequeue(struct queue *q){
    if(q->front == -1 || q->front > q->rear){
        printf("queue underflow");
        return;
    }
    // if(q->front==0){
    //     q->front = -1;
    // }
    printf("%d is dequeued from the queue\n",q->data[q->front++]);
}
void display(struct queue *q){
    if(q->front == -1 || q->front > q->rear)return;
    for(int i=q->front;i<=q->rear;i++){
        printf("%d\t",q->data[i]);
    }
}

int main(){
    struct queue q;
    inItQueue(&q);
    enqueue(&q,3);
    enqueue(&q,43);
    enqueue(&q,21);
    display(&q);
    printf("\n");
    dequeue(&q);
    display(&q);
    return 0;
}