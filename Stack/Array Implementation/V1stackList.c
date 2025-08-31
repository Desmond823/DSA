// This is version 1 of stack implementation using array
// Uses top = -1 to indicate empty stack
// by Jian Bryce Machacon

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    char elem[MAX];
    int top;
}Stack;

// Stack ADT functions
void initStack(Stack* S); // initializes top to -1
void push(Stack* S, char x); // basically insertLast for array implementation
void pop(Stack* S); // deleteLast for array implementation

// Utiltiy Functions
bool isEmpty(Stack S); // returns true if empty, else false
bool isFull(Stack S); // returns true if full, else false
void Top(Stack S); // returns the top element
void printStack(Stack* S); // prints and pops all elements

int main(){
    Stack S;
    initStack(&S);
    (isEmpty(S)) ? printf("\nStack is Empty!\n") : printf("\nStack is not Empty!\n");

    push(&S, 'A');
    push(&S, 'B');
    push(&S, 'C');
    push(&S, 'D');
    push(&S, 'E');
    push(&S, 'F');
    push(&S, 'G');
    push(&S, 'H');
    push(&S, 'I');
    push(&S, 'J');
    (isFull(S)) ? printf("Stack is Full!\n") : printf("Stack is not Full!\n");
    push(&S, 'K');

    Top(S);
    printStack(&S);
    (isEmpty(S)) ? printf("\nStack is Empty!\n") : printf("\nStack is not Empty!\n");
}

void initStack(Stack* S){
    S->top = -1;
}

void push(Stack* S, char x){
    if(!isFull(*S)){
        S->top++;
        S->elem[S->top] = x;
    } else {
        printf("Stack is Full!\n");
    }
}

void pop(Stack* S){
    if(!isEmpty(*S)){
        S->top--;   
    } else {
        printf("Stack is Empty!\n");
    }
}

bool isEmpty(Stack S){
    return (S.top == -1) ? true : false;
}

bool isFull(Stack S){
    return (S.top == MAX-1) ? true : false;
}

void Top(Stack S){
    if(!isEmpty(S)){
        printf("Top Element: %c\n", S.elem[S.top]);
    } else {
        printf("Stack is Empty!\n");
    }
}

void printStack(Stack* S){
    for(; S->top != -1; pop(S)){
        printf("%c ", S->elem[S->top]);
    }
}