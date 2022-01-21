#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

struct stack{
    int size;
    int top;
    stackS *data;
};

typedef struct stack* stack_t;

stack_t create(int max_size){
    stack_t newS = (stack_t)malloc(sizeof(struct stack));
    newS->size = max_size;
    newS->top = -1;
    newS->data = (int*)malloc(newS->size*sizeof(int));
    return newS;
}

int is_empty(stack_t root){
    return root->top == -1;
}

int is_full(stack_t root){
    return root->top == root->size - 1;
}

void push(stack_t root, int data){
    if(is_full(root)){
        printf("Stack full\n");
    } else{
        root->data[++root->top] = data;
    }    
}

void pop(stack_t root){
    if(is_empty(root)){
        root->top == -1;
    } else{
        root->data[root->top--];
    }   
}

stackS top(stack_t root){
    if(is_empty(root)){
        printf("Nothing to display");
    } else{
        return root->data[root->top];
    }
}