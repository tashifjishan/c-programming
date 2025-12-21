#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

/* Function Prototypes */
void traverse();
void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteFromBeginning();
void deleteFromEnd();
void deleteByValue();
void search();

/* Main Function */
int main() {
    int choice;

    while (1) {
        printf("\n\n--- Singly Linked List Menu ---\n");
        printf("1. Traverse\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete by Value\n");
        printf("8. Search\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: traverse(); break;
        case 2: insertAtBeginning(); break;
        case 3: insertAtEnd(); break;
        case 4: insertAtPosition(); break;
        case 5: deleteFromBeginning(); break;
        case 6: deleteFromEnd(); break;
        case 7: deleteByValue(); break;
        case 8: search(); break;
        case 9: exit(0);
        default:
            printf("Invalid choice! Try again.");
        }
    }

    return 0;
}

/* Traverse the list */
void traverse() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("Linked List is empty.");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

/* Insert at beginning */
void insertAtBeginning() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int val;

    printf("Enter value: ");
    scanf("%d", &val);

    newNode->data = val;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.");
}

/* Insert at end */
void insertAtEnd() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    int val;

    printf("Enter value: ");
    scanf("%d", &val);

    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Node inserted at end.");
}

/* Insert at given position */
void insertAtPosition() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    int val, pos, i;

    printf("Enter value: ");
    scanf("%d", &val);
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.");
        free(newNode);
        return;
    }

    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.", pos);
}

/* Delete from beginning */
void deleteFromBeginning() {
    struct Node* temp;

    if (head == NULL) {
        printf("List is empty.");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from beginning.");
}

/* Delete from end */
void deleteFromEnd() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from end.");
        return;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    printf("Node deleted from end.");
}

/* Delete by value */
void deleteByValue() {
    struct Node* temp = head;
    struct Node* prev = NULL;
    int key;

    if (head == NULL) {
        printf("List is empty.");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    if (head->data == key) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted.");
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted.");
}

/* Search an element */
void search() {
    struct Node* temp = head;
    int key, pos = 1;

    if (head == NULL) {
        printf("List is empty.");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value found at position %d.", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Value not found.");
}
