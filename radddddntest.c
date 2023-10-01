#include <stdio.h>
#include <stdlib.h>

#define max 20
#define stackCount 4

typedef struct Stack{
    int data[max];
    int top[max];
    int bottom[max];
} Stack;

void initStackTop(Stack* stack){
    for (int i=0; i<stackCount; i++){
        stack->top[i] = (((max/stackCount)*i)-1);
    }
}

void initStackBottom(Stack* stack){
    for (int i=0; i<=stackCount; i++){
        stack->bottom[i] = (((max/stackCount)*i)-1);
    }
}

void push(Stack* stack, int stackNum, int element){
    if (stack->top[stackNum-1] == stack->bottom[stackNum]){
        printf("Stack Overflow \n");
    } else {
        stack->data[++stack->top[stackNum-1]] = element;
    }
}

int pop(Stack* stack, int stackNum){
    if (stack->top[stackNum-1] == stack->bottom[stackNum-1]){
        printf("Stack Underflow \n");
        return -1; // Return an error value
    } else {
        return (stack->data[stack->top[stackNum-1]--]);
    }
}

void display(Stack* stack, int stackNum){
    printf("Stack Number %d: ", stackNum);
    for (int i=stack->bottom[stackNum-1]+1; i<=stack->top[stackNum-1]; i++){
        printf("%d \t", stack->data[i]);
    }
    printf("\n");
}

int main(){
    Stack stack;
    initStackTop(&stack);
    initStackBottom(&stack);

    push(&stack, 1, 10);
    push(&stack, 2, 20);
    push(&stack, 3, 30);
    push(&stack, 4, 40);

    display(&stack, 1);
    display(&stack, 2);
    display(&stack, 3);
    display(&stack, 4);
}
