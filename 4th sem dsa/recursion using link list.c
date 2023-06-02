#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};
typedef struct Node *node;


void pushin(node** head, int newdata) {
    node t;
    t = (struct Node*) malloc(sizeof(struct Node));
    t->data = newdata;
    t->next = *head;
    *head = t;
}


void printlistrecursive(node nod) {
    if (nod == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", nod->data);
    printlistrecursive(nod->next);
}

// Function to read integers from user and add them to the linked list using recursion
void readlistrecursive(node** head) {
    int num;
    scanf("%d", &num);
    if (num == -1) {
        return;
    }
    pushin(head, num);
    readlistrecursive(head);
}

int main() {
    // Create an empty linked list
    node head = NULL;

    // Ask the user to enter integers to add to the linked list
    printf("Enter integers to add to the linked list (enter -1 to stop):\n");
    readlistrecursive(&head);

    // Print the contents of the linked list
    printf("Contents of the linked list: ");
    printlistrecursive(head);

    return 0;
}
