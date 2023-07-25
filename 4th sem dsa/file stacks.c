#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void push(Stack* stack, int value, FILE* push_file) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(1);
    }
    stack->top++;
    stack->items[stack->top] = value;
    fprintf(push_file, "Pushed %d onto the stack\n", value);
}

int pop(Stack* stack, FILE* pop_file) {
    if (stack->top == -1) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    int popped = stack->items[stack->top];
    stack->top--;
    fprintf(pop_file, "Popped %d from the stack\n", popped);
    return popped;
}

int main() {
    Stack stack;
    stack.top = -1;
    int num=0;

    FILE* input_file = fopen("numbers.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    FILE* push_file = fopen("push_log.txt", "w");
    if (push_file == NULL) {
        printf("Error: could not create push log file\n");
        exit(1);
    }

    FILE* pop_file = fopen("pop_log.txt", "w");
    if (pop_file == NULL) {
        printf("Error: could not create pop log file\n");
        exit(1);
    }

    FILE* operational = fopen("operational.txt", "w");
    if (pop_file == NULL) {
        printf("Error: could not create pop log file\n");
        exit(1);
    }
    while(fscanf( pop_file, "%d",pop_file) != EOF) {
        num++;
        printf("The numbers in the stack are %d",num);
    }
 while(fscanf( pop_file, "%d",push_file) != EOF) {
        num++;
        printf("The numbers in the stack are %d",num);
 }




    while (fscanf(input_file, "%d", &num) == 1) {
        push(&stack, num, push_file);
    }

    fclose(input_file);
    fclose(push_file);

    while (stack.top != -1) {
        pop(&stack, pop_file);
    }

    fclose(pop_file);

    return 0;
}
