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
int allocSpace(VirtualHeap* ref);
void deallocSpace(VirtualHeap* ref, int index);

//utility functions
void insertFirst(VirtualHeap* ref, List* L, char x);
void insertLast(VirtualHeap* ref, List* L, char x);
void insertSorted(VirtualHeap* ref, List* L, char x);
void deleteElem(VirtualHeap* ref, List* L, char x);
void initLIST(List* L);
void printList(VirtualHeap ref, List L);

int main(){
    VirtualHeap VH;
    List L;

    initHeap(&VH);
    initLIST(&L);
    
    insertFirst(&VH, &L, 'A');
    insertLast(&VH, &L, 'B');
    insertFirst(&VH, &L, 'C');    
    insertSorted(&VH, &L, 'D');
    
    //printf("%d, %d\n", L, VH.avail);
    printList(VH, L);
    return 0;
}

void initHeap(VirtualHeap* ref){
    for(int i = 0; i < MAX; i++){
        ref->Nodes[i].link = i-1;
    }
    ref->avail = 9;
}

int allocSpace(VirtualHeap* ref){
    int index = ref->avail;
    if(ref->avail != -1){
        ref->avail = ref->Nodes[ref->avail].link;
    }
    return index;
}

void deallocSpace(VirtualHeap* ref, int index){
    ref->Nodes[index].link = ref->avail;
    ref->avail = index;
}

void insertFirst(VirtualHeap* ref, List* L, char x){
    int idx = allocSpace(ref);
    if(idx != -1){
        ref->Nodes[idx].elem = x;
        ref->Nodes[idx].link = *L;
        *L = idx;
    }
}

void insertLast(VirtualHeap* ref, List* L, char x){
    int idx = allocSpace(ref);
    if(idx != -1){
        ref->Nodes[idx].elem = x;
        ref->Nodes[idx].link = -1;
        if(*L == -1){
            *L = idx;
        } else {
            int i;
            for(i = *L; ref->Nodes[i].link != -1; i = ref->Nodes[i].link){}
            ref->Nodes[i].link = idx;
        }
    }
}

void insertSorted(VirtualHeap* ref, List* L, char x){
    int idx = allocSpace(ref);
    if(idx != -1){
        int* i;
        for(i = L; *i != -1 && ref->Nodes[*i].elem < x; i = &ref->Nodes[*i].link){}
        ref->Nodes[idx].elem = x;
        ref->Nodes[idx].link = *i;
        *i = idx;
    }
}

void deleteElem(VirtualHeap* ref, List* L, char x){
    int* i;
    for(i = L; *i != -1 && ref->Nodes[*i].elem != x; i = &ref->Nodes[*i].link){}
    if(*i != -1){
        int temp = *i;
        *i = ref->Nodes[*i].link;
        deallocSpace(ref, temp);
    }
}

void initLIST(List* L){
    *L = -1;
}

void printList(VirtualHeap ref, List L){
    for(int i = L; i != -1; i = ref.Nodes[i].link){
        printf("%c -> ", ref.Nodes[i].elem);
    }
    printf("NULL\n");
}