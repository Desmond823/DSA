#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct node{
    char elem;
    int link;
}NodeType;

typedef struct{
    NodeType Nodes[MAX];
    int front;
    int rear;
    int avail;
}VirtualHeap;

void initHeap(VirtualHeap* ref);
int allocSpace(VirtualHeap* ref);
void deallocSpace(VirtualHeap* ref);

void Enqueue(VirtualHeap* ref, char x);
void Dequeue(VirtualHeap* ref);
char Front(VirtualHeap ref);
void printStack(VirtualHeap* ref);

int main(){
    VirtualHeap Queue;
    initHeap(&Queue);

}

void initHeap(VirtualHeap* ref){
    for(int i = 0; i<MAX; i++){
        ref->Nodes[i].link = i-1;
    }
    ref->avail = MAX-1;
}

int allocSpace(VirtualHeap* ref){
    int temp = ref->avail;
    if(ref->avail != -1){
        ref->avail = ref->Nodes[ref->avail].link;
    }
    return temp;
}