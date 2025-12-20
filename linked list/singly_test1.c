#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
void insertathead(struct node **head,int data){
    struct node *newnode = malloc(sizeof(struct node));
    if(newnode==NULL)return;
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=*head;
    if(*head!=NULL){
        (*head)->prev=newnode;
    }
    *head=newnode;
}
void insertatpos(struct node **head,int pos,int data){
    if(pos<0)return;//
    struct node *temp = malloc(sizeof(struct node));
    if(temp==NULL)return;
    temp->data=data;
    if(pos==0){
        temp->next=*head;
        *head=temp;
        return;
    }
    struct node *current = malloc (sizeof(struct node));
    for(int i=0;i<pos-1 && current!=NULL;i++){
        current=current->next;//
    }
    if(current==NULL){
        free(temp);
        return;
    }
    temp->next=current->next;
    current->next=temp;
}
void insertattail(struct node **head,int data){
    struct node *temp = malloc(sizeof(struct node));
    if(temp==NULL)return;
    temp->data=data;
    temp->next=NULL;
    if(*head==NULL){
        *head = temp;
        return;
    }
    struct node *current =*head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next=temp;
}
void deleteatpos(struct node **head,int pos){
    if(pos<0||*head==NULL)return;
    if(pos==0){
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct node *current=*head;
    for(int i=0;i<pos-1||current!=NULL;i++){
        current=current->next;
    }
    if(current==NULL||current->next==NULL)return;
    struct node *temp = current->next;
    current->next=temp->next;
    free(temp);

}
void deletebyvalue(struct node **head, int data){
    if(*head=NULL)return;
    if((*head)->data==data){
        struct node *temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
    }
    struct node *current = *head;
    while(current->next!=NULL && current->next->data!=data){
        current=current->next;
    }
    if(current->next==NULL)return;
    struct node *temp = current->next;
    current->next=temp->next;
    free(temp);

}
int search(struct node *head,int data){
    int pos=0;
    while(head!=NULL){
        if(head->data==data){
            return pos;
        }
        head= head->next;
        pos++
    }
    return -1;
}
int length(struct node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
void traversal(struct node *current){
    while(current!=NULL){
        printf("%d\n",current->data);
        current=current->next;
    }
}
void freelist(){

}
int main(){
    struct node *head = NULL;
    return 0;
}