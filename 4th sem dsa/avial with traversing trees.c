#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

void postOrder(struct Node* root, FILE* fp) {
    if (root == NULL)
        return;

    postOrder(root->left, fp);
    postOrder(root->right, fp);
    fprintf(fp, "%d ", root->data);
}

void preOrder(struct Node* root, FILE* fp) {
    if (root == NULL)
        return;

    fprintf(fp, "%d ", root->data);
    preOrder(root->left, fp);
    preOrder(root->right, fp);
}

void inOrder(struct Node* root, FILE* fp) {
    if (root == NULL)
        return;

    inOrder(root->left, fp);
    fprintf(fp, "%d ", root->data);
    inOrder(root->right, fp);
}

void levelOrder(struct Node* root, FILE* fp) {
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = -1;
    int rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct Node* temp = queue[++front];
        fprintf(fp, "%d ", temp->data);

        if (temp->left)
            queue[++rear] = temp->left;
        if (temp->right)
            queue[++rear] = temp->right;
    }
}

int main() {
    struct Node* root = NULL;
    int i, n, data;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    FILE* fp = fopen("traversals.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    fprintf(fp, "Post-order traversal: ");
    postOrder(root, fp);
    fprintf(fp, "\n");

    fprintf(fp, "Pre-order traversal: ");
    preOrder(root, fp);
    fprintf(fp, "\n");

    fprintf(fp, "In-order traversal: ");
    inOrder(root, fp);
    fprintf(fp, "\n");

    fprintf(fp, "Level-order traversal: ");
    levelOrder(root, fp);
    fprintf(fp, "\n");

    fclose(fp);
    printf("Traversals written to file 'traversals.txt'.\n");

    return 0;
}
