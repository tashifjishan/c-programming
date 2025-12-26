#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct cqueue{
    int data[MAX];
    int front;
    int rear;
};
void inItCqueue(struct cqueue *cq){
    cq->front = -1;
    cq->rear = -1;
}
int isEmpty(struct cqueue *cq){
    return (cq->front == -1);
}
int isFull(struct cqueue *cq){
    return ((cq->rear+1)%MAX == cq->front);
}
void enqueue(struct cqueue *cq,int data){
    if(isFull(cq)){
        printf("Queue Overflow");   
        return;
    }
    if(isEmpty){
        cq->front = 0;
    }
    cq->rear = (cq->rear+1) % MAX;
    cq->data[cq->rear]=data;
    printf("%d is inserted into the queue\n",data);
}
void dequeue(struct cqueue *cq){
    if(isEmpty(cq)){
        printf("Queue underflow");
        return;
    }
    printf("%d is removed from the queue\n",cq->data[cq->front]);
    if(cq->front == cq->rear){
        cq->front = -1;
        cq->rear = -1;
    }
    else{
        cq->front = (cq->front+1) % MAX;
    }
}
void display(struct cqueue *cq){
    if(isEmpty(cq)){
        printf("No element is present in queue");
        return;
    }
    for(int i=cq->front;i<=cq->rear;i++){
        printf("%d\n",cq->data[i]);
    }
}
int main(){
    struct cqueue cq;
    inItCqueue(&cq);
    enqueue(&cq,23);
    enqueue(&cq,1);
    enqueue(&cq,54);
    display(&cq);
    dequeue(&cq);
    display(&cq);
    return 0;
}