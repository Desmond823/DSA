#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char elem;
    struct node* link;
}*Stack;

// Stack ADT functions
void initStack(Stack* S); // initializes top to -1
void push(Stack* S, char x); // basically insertFirst for linked list
void pop(Stack* S); // deleteFirst for linked List

// Utiltiy Functions
bool isEmpty(Stack S); // returns true if empty, else false
char Top(Stack S); // returns the top element
void printStack(Stack* S); // prints and pops all elements

int main(){
    Stack S;
    initStack(&S);
    (isEmpty(S)) ? printf("\nStack is Empty!\n") : printf("\nStack is not Empty!\n");
    push(&S, 'A');
    push(&S, 'B');
    push(&S, 'C');
    push(&S, 'D');

    printf("Top: %c\n", Top(S));
    pop(&S);
    printStack(&S);
    (isEmpty(S)) ? printf("\nStack is Empty!\n") : printf("\nStack is not Empty!\n");

}

void initStack(Stack* S){
    *S = NULL;
}

void push(Stack* S, char x){
    Stack temp = (Stack)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->elem = x;
        temp->link = *S;
        *S = temp;
    }
}

void pop(Stack* S){
    if(*S != NULL){
        Stack temp = *S;
        *S = (*S)->link;
    }
}

bool isEmpty(Stack S){
    return (S == NULL) ? true : false;
}

char Top(Stack S){
    return (S != NULL) ? S->elem : printf("NULL");
}

void printStack(Stack* S){
    for(;*S != NULL; pop(S)){
        printf("%c -> ", (*S)->elem);
    }
    Top(*S);
}

