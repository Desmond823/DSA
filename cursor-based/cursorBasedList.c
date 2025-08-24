#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10


typedef struct{
    char elem;
    int link;
}Node;

typedef struct{
    Node Nodes[MAX];
    int avail;
}VirtualHeap;

typedef int List; // List is an index to the first element in the Virtual Heap

// 3 Virtual Heap Management Functions
void initHeap(VirtualHeap* ref);
int allocSpace(VirtualHeap ref);
void deallocSpace(VirtualHeap* ref, int index);

//utility functions
void insertFirst(VirtualHeap* ref, List* L, char x);
void insertLast(VirtualHeap* ref, List L, char x);
void insertSorted(VirtualHeap* ref, List* L);
void deleteElem(VirtualHeap* ref, List* L);

int main(){
    VirtualHeap VH;
    List L;

    return 0;
}

void initHeap(VirtualHeap* ref){
    for(int i = 0; i < MAX-1; i++){
        ref->Nodes[i].link = i-1;
        ref->Nodes[i].elem = '\0';
    }
    ref->avail = 9;
}

int allocSpace(VirtualHeap ref){
    int i;
    for(i = 0; ref.Nodes[i].elem != '\0' && i < MAX; i++){}   // exits on the first available node
    return (i < 10) ? i: -1;                                               // returns -1 if no available node
}

void deallocSpace(VirtualHeap* ref, int index){

}

void insertFirst(VirtualHeap* ref, List* L, char x){
    ref->avail = allocSpace(*ref);
    if(ref->avail != -1){
        ref->Nodes[ref->avail].elem = x;
        ref->Nodes[ref->avail].link = *L;
        *L = ref->avail;
    }
}

void insertLast(VirtualHeap* ref, List L, char x){
    ref->avail = allocSpace(*ref);
    if(ref->avail != -1){
        ref->Nodes[ref->avail].elem = x;
        ref->Nodes[ref->avail].link = -1;
    }
}
