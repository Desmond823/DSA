#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int data;
    int left;
    int right;
    int next;
}nodeType;

typedef struct{
    nodeType nodes[MAX];
    int avail;
}VirtualHeap;

typedef int root;

void initVH(VirtualHeap* VH);
int allocSpace(VirtualHeap* VH);
void deallocSpace(VirtualHeap* VH, int idx);

void insertNode(VirtualHeap* VH, root T, int data);
void removeNode(VirtualHeap* VH, root T, int data);
int max(VirtualHeap VH, root T, int data);
int min(VirtualHeap VH, root T, int data);
int member(VirtualHeap VH, root T, int data);

int main(){
    VirtualHeap VH;
    root T = -1;
    initVH(&VH);
}

void initVH(VirtualHeap* VH){
    for(int i = 0; i<MAX-1; i++){
        VH->nodes[i].next = i+1;
    }
    VH->nodes[MAX-1].next = -1;
    VH->avail = 0;
}

int allocSpace(VirtualHeap* VH){
    int temp = VH->avail;
    if(temp != -1){
        VH->avail = VH->nodes[temp].next;
    }
    return temp;
}
void deallocSpace(VirtualHeap* VH, int idx){
    VH->nodes[idx].next = VH->avail;
    VH->avail = idx;
}

void insertNode(VirtualHeap* VH, root T, int data){
    int temp = allocSpace(VH);
    if(T != -1){
        root* trav = &T;
        while(*trav != -1){
            if(data != VH->nodes[*trav].data && data < VH->nodes[*trav].data) trav = &VH->nodes[*trav].left;
            else trav = &VH->nodes[*trav].right;
        }
        if(*trav == -1){
            nodeType nodetemp = {data, -1, -1, -1};
            if(temp != -1){
                VH->nodes[temp] = nodetemp;
                *trav = temp;
            }
        }
    }
    
}

void removeNode(VirtualHeap* VH, root T, int data);

int max(VirtualHeap VH, root T, int data);

int min(VirtualHeap VH, root T, int data);

int member(VirtualHeap VH, root T, int data);

