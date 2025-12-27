#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define table_size 10
struct node{
    char *key;
    char *value;
    struct node *next;
};
struct node *hashtable[table_size];

int hashfunction(const char *key){
    int hash = 0;
    while(*key){
        hash = (hash * 31) + *key;
        key++;
    }
    return hash % table_size;
}
void init(){
    for(int i=0;i<table_size;i++){
        hashtable[i]=NULL;
    }
}
void put(const char *key,const char *value){
    int index = hashfunction(key);
    struct node *temp = hashtable[index];
    while(temp != NULL){
        if(strcmp(temp->key,key) == 0){
            free(temp->value);
            temp->value = strdup(value);
            return;
        }
        temp = temp->next;
    }
    struct node *newnode = malloc(sizeof(struct node));
    newnode->key = strdup(key);
    newnode->value = strdup(value);
    newnode->next = hashtable[index];
    hashtable[index] = newnode;
}
char* get(const char *key){

}
int main(){
    return 0;
}