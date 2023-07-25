#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for AVL tree node
typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// Function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get the height of a node
int getHeight(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to create a new AVL node
AVLNode* createNode(int data) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to right rotate a subtree
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Function to left rotate a subtree
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to get the balance factor of a node
int getBalanceFactor(AVLNode* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to insert a node into the AVL tree
AVLNode* insertNode(AVLNode* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1) {
        if (data < root->left->data) {
            return rotateRight(root);
        } else if (data > root->left->data) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    if (balanceFactor < -1) {
        if (data > root->right->data) {
            return rotateLeft(root);
        } else if (data < root->right->data) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

// Function to print the AVL tree in inorder traversal
void inorderTraversal(AVLNode* root, FILE* file) {
    if (root != NULL) {
        inorderTraversal(root->left, file);
        fprintf(file, "%d ", root->data);
        inorderTraversal(root->right, file);
    }
}

// Function to generate random numbers and insert them into AVL tree
void generateRandomNumbers(int count) {
    AVLNode* root = NULL;
    FILE* inputFile = fopen("input.txt", "w");
    FILE* outputFile = fopen("output.txt", "w");

    srand(time(0));

    for (int i = 0; i < count; i++) {
        int num = rand() % 1000 + 1;
        fprintf(inputFile, "%d ", num);
        root = insertNode(root, num);
    }

    fclose(inputFile);

    inorderTraversal(root, outputFile);

    fclose(outputFile);
}

int main() {
    int count;

    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &count);

    generateRandomNumbers(count);

    printf("Random numbers generated and AVL tree solution saved in files 'input.txt' and 'output.txt' respectively.\n");

    return 0;
}
