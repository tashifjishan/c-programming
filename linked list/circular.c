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
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = data;

    if (*head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node *last = (*head)->prev;

    newNode->next = *head;
    newNode->prev = last;

    last->next = newNode;
    (*head)->prev = newNode;

    *head = newNode;
}

void insertAtTail(struct Node **head, int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = data;

    if (*head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node *last = (*head)->prev;

    newNode->next = *head;
    newNode->prev = last;

    last->next = newNode;
    (*head)->prev = newNode;
}

void insertAtPos(struct Node **head, int pos, int data)
{
    if (pos < 0) return;

    if (pos == 0)
    {
        insertAtHead(head, data);
        return;
    }

    if (*head == NULL) return;

    struct Node *current = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;
        if (current == *head)
            return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = data;
    newNode->next = current->next;
    newNode->prev = current;

    current->next->prev = newNode;
    current->next = newNode;
}

void deletePos(struct Node **head, int pos)
{
    if (*head == NULL || pos < 0) return;

    struct Node *current = *head;

    if (pos == 0)
    {
        if (current->next == current)
        {
            free(current);
            *head = NULL;
            return;
        }

        struct Node *last = current->prev;
        *head = current->next;

        last->next = *head;
        (*head)->prev = last;

        free(current);
        return;
    }

    for (int i = 0; i < pos; i++)
    {
        current = current->next;
        if (current == *head)
            return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current);
}

void deleteByValue(struct Node **head, int value)
{
    if (*head == NULL) return;

    struct Node *current = *head;

    do
    {
        if (current->data == value)
        {
            if (current->next == current)
            {
                free(current);
                *head = NULL;
                return;
            }

            if (current == *head)
                *head = current->next;

            current->prev->next = current->next;
            current->next->prev = current->prev;

            free(current);
            return;
        }
        current = current->next;
    } while (current != *head);
}

int search(struct Node *head, int value)
{
    if (head == NULL) return -1;

    int pos = 0;
    struct Node *current = head;

    do
    {
        if (current->data == value)
            return pos;
        current = current->next;
        pos++;
    } while (current != head);

    return -1;
}

int length(struct Node *head)
{
    if (head == NULL) return 0;

    int count = 0;
    struct Node *current = head;

    do
    {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}

void traverseForward(struct Node *head)
{
    if (head == NULL) return;

    struct Node *current = head;
    do
    {
        printf("%d\n", current->data);
        current = current->next;
    } while (current != head);
}

void traverseBackward(struct Node *head)
{
    if (head == NULL) return;

    struct Node *current = head->prev;
    struct Node *last = current;

    do
    {
        printf("%d\n", current->data);
        current = current->prev;
    } while (current != last);
}

void freeList(struct Node **head)
{
    if (*head == NULL) return;

    struct Node *current = (*head)->next;

    while (current != *head)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    free(*head);
    *head = NULL;
}

int main()
{
    struct Node *head = NULL;

    insertAtHead(&head, 70);
    insertAtHead(&head, 90);
    insertAtTail(&head, 50);

    printf("Forward Traversal:\n");
    traverseForward(head);

    printf("Backward Traversal:\n");
    traverseBackward(head);

    freeList(&head);
    return 0;
}
