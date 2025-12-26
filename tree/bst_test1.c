#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
void insert(struct node **root,int data){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if(*root==NULL){
        *root = newnode;
        printf("Successfully inserted %d\n",data);
        return;
    }
    else if((*root)->data>data){
        if((*root)->left==NULL){
            (*root)->left = newnode;
            printf("Successfully inserted %d\n",data);
        }
        else {
            free(newnode);
            insert(&(*root)->left,data);
        }
    }
    else if((*root)->data<data){
        if((*root)->right==NULL){
            (*root)->right = newnode;
            printf("Successfully inserted %d\n",data);
        }
        else {
            free(newnode);
            insert(&(*root)->right,data);
        }
    }
    else {
        printf("Cannot store two same values\n");
        free(newnode);
        return;
    }
    
}
struct node *findmin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
void deletenode(struct node **root,int data){
    if((*root) == NULL) return;
    if((*root)->data>data){
        deletenode(&((*root)->left),data);
    }
    if((*root)->data<data){
        deletenode(&((*root)->right),data);
    }
    else{
        if((*root)->left==NULL && (*root)->right==NULL){
            printf("Successfully deleted %d\n",*root);
            free(*root);
            *root=NULL;
            
        }
        else if((*root)->left==NULL ){
            
            struct node *temp = *root;
            printf("Successfully deleted %d\n",*temp);
            *root = (*root)->right;
            free(temp);
            
        }
        else if((*root)->right==NULL){
            struct node *temp = *root;
            *root = (*root)->left;
            free(temp);
            
        }
        else{
            struct node *temp = findmin((*root)->right);
            (*root)->data = temp->data;
            deletenode(&((*root)->right),temp->data);
        }
    }
}
void inorder(struct node *root){

}
int main(){
    struct node *root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);
    deletenode(&root, 20);
    deletenode(&root, 30);
    deletenode(&root, 50);
    return 0;
}