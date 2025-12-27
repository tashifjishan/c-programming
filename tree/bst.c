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
        } else {
            free(newNode);
            insert(&((*root)->left), value);
        }
    }
    else if (value > (*root)->data) {
        if ((*root)->right == NULL) {
            (*root)->right = newNode;
        } else {
            free(newNode);
            insert(&((*root)->right), value);
        }
    }
    else {
        printf("Duplicate key insertion not allowed!\n");
        free(newNode);
    }
}

/* FIND MINIMUM VALUE NODE */
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

/* DELETE (NO RETURN VALUE) */
void deleteNode(struct Node** root, int value) {
    if (*root == NULL) {
        return;
    }

    if (value < (*root)->data) {
        deleteNode(&((*root)->left), value);
    }
    else if (value > (*root)->data) {
        deleteNode(&((*root)->right), value);
    }
    else {
        /* Case 1: No children */
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        }

        /* Case 2: One child (right) */
        else if ((*root)->left == NULL) {
            struct Node* temp = *root;
            *root = (*root)->right;
            free(temp);
        }

        /* Case 2: One child (left) */
        else if ((*root)->right == NULL) {
            struct Node* temp = *root;
            *root = (*root)->left;
            free(temp);
        }

        /* Case 3: Two children */
        else {
            struct Node* temp = findMin((*root)->right);
            (*root)->data = temp->data;
            deleteNode(&((*root)->right), temp->data);
        }
    }
}

/* INORDER TRAVERSAL (Left -> Root -> Right) */
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* PREORDER TRAVERSAL (Root -> Left -> Right) */
void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

/* POSTORDER TRAVERSAL (Left -> Right -> Root) */
void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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

    printf("Inorder traversal:\n");
    inorder(root);

    printf("\nPreorder traversal:\n");
    preorder(root);

    printf("\nPostorder traversal:\n");
    postorder(root);

    deleteNode(&root, 20);  // leaf
    deleteNode(&root, 30);  // one child
    deleteNode(&root, 50);  // two children

    printf("\n\nAfter deletion (Inorder):\n");
    inorder(root);
    
    return 0;
}
