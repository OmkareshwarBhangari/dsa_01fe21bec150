#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

struct Node* findMinimumNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMinimumNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

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

void displayMenu() {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert a random number\n");
    printf("2. Delete a node\n");
    printf("3. Display tree traversals\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void generateRandomNumbers(int count, const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int number = rand() % 100;
        fprintf(fp, "%d\n", number);
    }

    fclose(fp);
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    generateRandomNumbers(10, "input.txt");  // Generate 10 random numbers and save them to "input.txt"

    FILE* input_fp = fopen("input.txt", "r");
    if (input_fp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fscanf(input_fp, "%d", &data) != EOF) {
        root = insertNode(root, data);
    }

    fclose(input_fp);

    FILE* output_fp = fopen("output_fp.txt", "w");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                data = rand() % 100;  // Generate a random number between 0 and 99
                printf("Inserting random number: %d\n", data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Node deleted successfully.\n");
                break;
            case 3:
                printf("Post-order traversal: ");
                postOrder(root, output_fp);
                fprintf(output_fp, "\n");

                printf("Pre-order traversal: ");
                preOrder(root, output_fp);
                fprintf(output_fp, "\n");

                printf("In-order traversal: ");
                inOrder(root, output_fp);
                fprintf(output_fp, "\n");

                printf("Level-order traversal: ");
                levelOrder(root, output_fp);
                fprintf(output_fp, "\n");
                break;
            case 4:
                fclose(output_fp);  // Close the output file
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
