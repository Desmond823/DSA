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
void insertBottom(Stack* S, char x); // insert bottom using Stack ADT function

int main(){
    Stack S;
    initStack(&S);
    (isEmpty(S)) ? printf("\nStack is Empty!\n") : printf("\nStack is not Empty!\n");
    push(&S, 'A');
    push(&S, 'B');
    push(&S, 'C');
    push(&S, 'D');
    insertBottom(&S, 'E');
    printf("Top: %c\n", Top(S));
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
        free(temp);
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
        printf("%c -> ", Top(*S));
    }
    Top(*S);
}

void insertBottom(Stack* S, char x){
    Stack temp;
    initStack(&temp);
    for(;*S != NULL; pop(S)){ // transfer everything to temp
        push(&temp, (*S)->elem);
    }
    push(S, x);
    for(; temp != NULL; pop(&temp)){ // transfer everything back to S
        push(S, Top(temp));
    }
}