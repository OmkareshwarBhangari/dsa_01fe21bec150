#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack implementation using an array
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element to the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

// Graph implementation using an adjacency matrix
typedef struct {
    int vertices;
    int** matrix;
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->matrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->matrix[i] = (int*)malloc(vertices * sizeof(int));
    }

    // Initialize the adjacency matrix with zeroes
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}

// Function to perform depth-first search traversal
void dfs(Graph* graph, int startVertex, FILE* outputFile) {
    int visited[MAX_SIZE];
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0;
    }

    Stack* stack = createStack();
    visited[startVertex] = 1;
    push(stack, startVertex);

    fprintf(outputFile, "DFS traversal: ");

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);
        fprintf(outputFile, "%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->matrix[currentVertex][i] == 1 && visited[i] == 0) {
                push(stack, i);
                visited[i] = 1;
            }
        }
    }

    fprintf(outputFile, "\n");
}

// ...

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);

    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    int startVertex;
    fscanf(inputFile, "%d", &startVertex);

    dfs(graph, startVertex, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

