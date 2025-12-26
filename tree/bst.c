#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* INSERT */
void insert(struct Node** root, int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    if (value < (*root)->data) {
        if ((*root)->left == NULL) {
            (*root)->left = newNode;
            return;
        } else {
            insert(&((*root)->left), value);
        }
    }
    else if (value > (*root)->data) {
        if ((*root)->right == NULL) {
            (*root)->right = newNode;
            return;
        } else {
            insert(&((*root)->right), value);
        }
    }
    else {
        printf("Duplicate key insertion not allowed!\n");
        free(newNode);
    }
}

/* FIND MIN VALUE NODE (used in deletion) */
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

/* DELETE */
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        /* Case 1: No child */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        /* Case 2: One child */
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        /* Case 3: Two children */
        else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

/* INORDER TRAVERSAL */
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* MAIN */
int main() {
    struct Node* root = NULL;

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder before deletion:\n");
    inorder(root);

    root = deleteNode(root, 20);  // leaf
    root = deleteNode(root, 30);  // one child
    root = deleteNode(root, 50);  // two children

    printf("\nInorder after deletion:\n");
    inorder(root);

    return 0;
}
