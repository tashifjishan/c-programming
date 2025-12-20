#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertAtHead(struct Node **head, int data)
{
    /*
        create a new node
        assign data to the new node
        make new node point forward to the current head
        make new node's prev point to NULL
        update the old head's prev to new node
        move head to point to the new node
    */

    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

void insertAtTail(struct Node **head, int data)
{
    /*
        create a new node
        move to the last node of the list
        link last node's next to new node
        link new node's prev to last node
        if list is empty, make new node the head
    */

    struct Node *temp = malloc(sizeof(struct Node));
    if (temp == NULL) return;

    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = temp;
    temp->prev = current;
}

void insertAtPos(struct Node **head, int pos, int data)
{
    /*
        if position is zero, insert at head
        otherwise traverse till position - 1
        adjust next and prev pointers to insert the node
    */

    if (pos < 0) return;

    struct Node *temp = malloc(sizeof(struct Node));
    if (temp == NULL) return;

    temp->data = data;

    if (pos == 0)
    {
        temp->prev = NULL;
        temp->next = *head;

        if (*head != NULL)
            (*head)->prev = temp;

        *head = temp;
        return;
    }

    struct Node *current = *head;
    for (int i = 0; i < pos - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL)
    {
        free(temp);
        return;
    }

    temp->next = current->next;
    temp->prev = current;

    if (current->next != NULL)
        current->next->prev = temp;

    current->next = temp;
}

void deletePos(struct Node **head, int pos)
{
    /*
        if position is zero, delete the head node
        otherwise move to the given position
        adjust prev and next pointers
        free the deleted node
    */

    if (pos < 0 || *head == NULL)
        return;

    struct Node *current = *head;

    if (pos == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;

        free(current);
        return;
    }

    for (int i = 0; i < pos && current != NULL; i++)
        current = current->next;

    if (current == NULL)
        return;

    if (current->prev != NULL)
        current->prev->next = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
}

void deleteByValue(struct Node **head, int value)
{
    /*
        traverse the list to find the node with given value
        if found, reconnect previous and next nodes
        update head if required
        free the node
    */

    if (*head == NULL) return;

    struct Node *current = *head;

    while (current != NULL && current->data != value)
        current = current->next;

    if (current == NULL)
        return;

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
}

int search(struct Node *head, int value)
{
    /*
        traverse the list
        compare each node's data with value
        return position if found
        return -1 if not found
    */

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
    /*
        traverse the list
        increment count for each node
        return total count
    */

    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void traverseForward(struct Node *current)
{
    /*
        start from head
        print data of each node
        move forward using next pointer
        repeat until current becomes NULL
    */

    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void traverseBackward(struct Node *head)
{
    /*
        keep going forward until the current node's next does not point to NULL
        print the current node's data
        move backward using prev pointer and print
        repeat this until current becomes NULL
    */

    if (head == NULL) return;

    struct Node *current = head;
    while (current->next != NULL)
        current = current->next;

    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->prev;
    }
}

void freeList(struct Node **head)
{
    /*
        traverse the list
        free each node one by one
        finally set head to NULL
    */

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
    insertAtTail(&head, 50);

    printf("Traverse forward:\n");
    traverseForward(head);

    printf("Traverse backward:\n");
    traverseBackward(head);

    freeList(&head);
    return 0;
}
