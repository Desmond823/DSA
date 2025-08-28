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


    insertLast(&VH, &L, 'C');
    insertLast(&VH, &L, 'D');
    insertSorted(&VH,&L,'C');
    insertSorted(&VH,&L,'A');
    deleteElem(&VH, &L, 'C');
    deleteElem(&VH, &L, 'A');
    printList(VH, L);
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
    for(i = 9; ref.Nodes[i].elem != '\0' && i < MAX; i--){}   // exits on the first available node
    return (i < 10) ? i: -1;                                  // returns -1 if no available node
}

void deallocSpace(VirtualHeap* ref, int index){
    ref->Nodes[index].elem = '\0';
    ref->Nodes[index].link = ref->avail;
}

void insertFirst(VirtualHeap* ref, List* L, char x){
    ref->avail = allocSpace(*ref);
    if(ref->avail != -1){
        ref->Nodes[ref->avail].elem = x;
        ref->Nodes[ref->avail].link = *L;
        *L = ref->avail;
    }
}

void insertLast(VirtualHeap* ref, List* L, char x){
    ref->avail = allocSpace(*ref);
    if(ref->avail != -1){
        ref->Nodes[ref->avail].elem = x;
        ref->Nodes[ref->avail].link = -1;
        if(*L == -1){
            *L = ref->avail;
        } else {
            int i;
            for(i = *L; ref->Nodes[i].link != -1; i = ref->Nodes[i].link){}
            ref->Nodes[i].link = ref->avail;
        }
    }
}

void insertSorted(VirtualHeap* ref, List* L, char x){
    ref->avail = allocSpace(*ref);
    if(ref->avail != -1){
        int* i;
        for(i = L; *i != -1 && ref->Nodes[*i].elem < x; i = &ref->Nodes[*i].link){}
        ref->Nodes[ref->avail].elem = x;
        ref->Nodes[ref->avail].link = *i;
        *i = ref->avail;
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