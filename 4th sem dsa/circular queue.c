#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularQueue {
    Node* front;
    Node* rear;
} CircularQueue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initializeQueue(CircularQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(CircularQueue* queue) {
    return (queue->front == NULL);
}

void enqueue(CircularQueue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = queue->front;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to the circular queue\n", data);
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty\n");
        return -1;
    }
    int data;
    if (queue->front == queue->rear) {
        data = queue->front->data;
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        Node* temp = queue->front;
        data = temp->data;
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
        free(temp);
    }
    return data;
}

int getFront(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

void displayQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty\n");
        return;
    }
    Node* current = queue->front;
    printf("Circular queue elements: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    int choice, data;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get Front\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue(&queue));
                break;
            case 3:
                printf("Front element: %d\n", getFront(&queue));
                break;
            case 4:
                displayQueue(&queue);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}







