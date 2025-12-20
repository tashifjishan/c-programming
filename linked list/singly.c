#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtHead(struct Node **head, int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    printf("\n");
    printf("Address of node pointed by head before insertion: %p\n", *head);
    printf("address of new node: %p\n", newNode);

    printf("=====================\n");

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;

    printf("address of head after it is changed: %p\n", *head);
    printf("address of node pointed by the new node: %p\n", newNode->next);
    


}

void insertAtTail(struct Node **head, int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    if (temp == NULL) return;

    temp->data = data;
    temp->next = NULL;

    if (*head == NULL)
    {
        *head = temp;
        return;
    }
  
    struct Node *current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = temp;
}

void insertAtPos(struct Node **head, int pos, int data)
{
    if (pos < 0) return;

    struct Node *temp = malloc(sizeof(struct Node));
    if (temp == NULL) return;

    temp->data = data;

    if (pos == 0)
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    struct Node *current = *head;
    for(int i = 0; i < pos - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL)
    {
        free(temp);
        return;
    }

    temp->next = current->next;
    current->next = temp;
}

void deletePos(struct Node **head, int pos)
{
    if (pos < 0 || *head == NULL)
        return;

    if (pos == 0)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node *current = *head;
    for (int i = 0; i < pos - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL || current->next == NULL)
        return;

    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

void deleteByValue(struct Node **head, int value)
{
    if (*head == NULL) return;

    if ((*head)->data == value)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL && current->next->data != value)
        current = current->next;

    if (current->next == NULL)
        return;

    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

int search(struct Node *head, int value)
{
    int pos = 0;
    while (head != NULL)
    {
        if (head->data == value)
            return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

int length(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}


void traverse(struct Node *current)
{
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void freeList(struct Node **head)
{
    struct Node *current = *head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

int main()
{
    struct Node *head = NULL;

    insertAtHead(&head, 70);
    insertAtHead(&head, 90);
   
  
    traverse(head);

    freeList(&head);
    return 0;
}




