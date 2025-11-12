#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
#define VH_NULL -1

typedef struct{
    char elem;
    int link;
}NodeType;

typedef struct{
    NodeType Nodes[MAX];
    int avail;
}virtualHeap;

typedef int Stack; // this is just an alias for int

// cursorBased management functions
void initVH(virtualHeap* VH); // initializes the virtual heap
void initStack(Stack* S); // initializes top to -1
int allocSpace(virtualHeap* VH); // malloc()
void deallocSpace(virtualHeap* VH, int idx); // free()

//Stack ADT functions
void push(virtualHeap* VH, Stack* S, char x); // basically insertFirst for linked list
void pop(virtualHeap* VH, Stack* S); // deleteFirst for linked List
char Top(virtualHeap VH, Stack S); // prints the 'top' element

// Utiltiy Functions
bool isEmpty(Stack S); // returns true if empty, else false
void printStack(virtualHeap* VH, Stack* S); // prints and pops all elements

int main(){
    virtualHeap VH;
    Stack S;

    initVH(&VH);
    initStack(&S);

    (isEmpty(S)) ? printf("Stack is empty\n") : printf("Stack is not empty\n");

    push(&VH, &S, 'a');
    push(&VH, &S, 'b');
    push(&VH, &S, 'c');
    push(&VH, &S, 'd');
    push(&VH, &S, 'e');

    (isEmpty(S)) ? printf("Stack is empty\n") : printf("Stack is not empty\n");
    printf("Top: %c\n", Top(VH, S));
    printf("Stack: ");
    printStack(&VH, &S);
}

void initVH(virtualHeap* VH){
    for(int i = 0; i<MAX; i++){
        VH->Nodes[i].link = i-1;
    }
    VH->avail = MAX-1;
}

void initStack(Stack* S){
    *S = -1;
}

int allocSpace(virtualHeap* VH){
    int index = VH->avail;
    if(index != VH_NULL){
        VH->avail = VH->Nodes[index].link;
    }
    return index;
}

void deallocSpace(virtualHeap* VH, int idx){
    if(idx >= 0 && idx < MAX){
        VH->Nodes[idx].link = VH->avail;
        VH->avail = idx;
    }
}

void push(virtualHeap* VH, Stack* S, char x){ // equivalent of insertFirst
    int idx = allocSpace(VH);
    if(idx != VH_NULL){
        VH->Nodes[idx].elem = x;
        VH->Nodes[idx].link = *S;
        *S = idx;
    }
}

void pop(virtualHeap* VH, Stack* S){ // equivalent of deleteFirst
    if(*S != VH_NULL){
        int temp = *S;
        *S = VH->Nodes[*S].link;
        deallocSpace(VH, temp);
    }
}

bool isEmpty(Stack S){
    return(S == VH_NULL) ? true : false;
}

char Top(virtualHeap VH, Stack S){
    if(S != VH_NULL){
        return VH.Nodes[S].elem;
    }
}

void printStack(virtualHeap* VH, Stack* S){
    for(; *S != VH_NULL; pop(VH, S)){
        printf("%c ", VH->Nodes[*S].elem);
    }
}




