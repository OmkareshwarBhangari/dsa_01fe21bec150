#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct TreeNode {
    int employee_id;
    int salary;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int employee_id, int salary) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->employee_id = employee_id;
    newNode->salary = salary;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new employee with salary into the tree
struct TreeNode* insert(struct TreeNode* root, int employee_id, int salary) {
    if (root == NULL) {
        return createNode(employee_id, salary);
    }

    if (employee_id < root->employee_id) {
        root->left = insert(root->left, employee_id, salary);
    } else {
        root->right = insert(root->right, employee_id, salary);
    }

    return root;
}

// Function to delete an employee from the tree
struct TreeNode* deleteNode(struct TreeNode* root, int employee_id) {
    if (root == NULL) {
        return root;
    }

    if (employee_id < root->employee_id) {
        root->left = deleteNode(root->left, employee_id);
    } else if (employee_id > root->employee_id) {
        root->right = deleteNode(root->right, employee_id);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* successor = root->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        root->employee_id = successor->employee_id;
        root->salary = successor->salary;
        root->right = deleteNode(root->right, successor->employee_id);
    }

    return root;
}

// Function to traverse the tree in pre-order and write the output to a file
void traversePreorderToFile(struct TreeNode* root, FILE* file) {
    if (root != NULL) {
        fprintf(file, "Employee ID: %d, Salary: %d\n", root->employee_id, root->salary);
        traversePreorderToFile(root->left, file);
        traversePreorderToFile(root->right, file);
    }
}

// Function to traverse the tree in post-order and write the output to a file
void traversePostorderToFile(struct TreeNode* root, FILE* file) {
    if (root != NULL) {
        traversePostorderToFile(root->left, file);
        traversePostorderToFile(root->right, file);
        fprintf(file, "Employee ID: %d, Salary: %d\n", root->employee_id, root->salary);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Insert employees and their salaries
    root = insert(root, 1001, 50000);
    root = insert(root, 1002, 60000);
    root = insert(root, 1003, 55000);
    root = insert(root, 1004, 70000);

    // Open the output file
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Traverse the tree in-order and write the output to the file
    fprintf(file, "Traversing the tree in order:\n");
    //traverseInorderToFile(root, file);
    fprintf(file, "\n");

    // Delete an employee
    root = deleteNode(root, 1003);

    // Traverse the tree in pre-order and write the output to the file
    fprintf(file, "Traversing the tree in preorder:\n");
    traversePreorderToFile(root, file);
    fprintf(file, "\n");

    // Traverse the tree in post-order and write the output to the file
    fprintf(file, "Traversing the tree in postorder:\n");
    traversePostorderToFile(root, file);

    // Close the file
    fclose(file);

    return 0;
}
