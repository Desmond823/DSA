#include <stdio.h>
#include <stdlib.h>
#define ROOT -1
#define DNE -2
#define MAX 10

typedef int tree[MAX];

void initTree(tree T);
void insertChild(tree T, int nodeNum, int parentIdx);
void printfromRoot(tree T, int root);


int main(){
    tree T;
    initTree(T);

    insertChild(T,5,ROOT);
    insertChild(T,0,5);
    insertChild(T,6,5);
    insertChild(T,2,5);
    insertChild(T,3,6);
    insertChild(T,1,6);
    insertChild(T,8,2);
    insertChild(T,4,1);
    insertChild(T,7,1);

    printfromRoot(T,5);
}

void initTree(tree T){
    for(int i = 0; i<MAX; i++){
        T[i] = DNE;
    }
}

void insertChild(tree T, int nodeNum, int parentIdx){
    if(nodeNum < MAX && nodeNum > -1){
        T[nodeNum] = parentIdx;
    }
}

void printfromRoot(tree T, int root){
    if(root < 0 || root >= MAX) return;
    if(T[root] == DNE) return;

    // Print the current node
    printf("%d ", root);

    // Find all children of this node
    for(int i = 0; i < MAX; i++){
        if(T[i] == root){   // i is a child of root
            printfromRoot(T, i);
        }
    }
}

