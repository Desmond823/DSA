#include <stdio.h>
#include <stdlib.h>
#define MAX 15


typedef struct{
    int arr[MAX];
    int lastIDX;
}Set;

void insert(Set* T, int x);
int deleteMin(Set* T);
void initTree(Set* T);
void display(Set T);
void swap(int* x, int* y);
void heapify(Set* T);

int main(){
    Set T;
    initTree(&T);
    
    T.arr[++T.lastIDX] = 3;
    T.arr[++T.lastIDX] = 5;
    T.arr[++T.lastIDX] = 9;
    T.arr[++T.lastIDX] = 8;
    T.arr[++T.lastIDX] = 6;
    T.arr[++T.lastIDX] = 9;
    T.arr[++T.lastIDX] = 10;
    T.arr[++T.lastIDX] = 10;
    T.arr[++T.lastIDX] = 18;
    T.arr[++T.lastIDX] = 9;

    display(T);

    insert(&T, 4);
    display(T);

    printf("\nDeleted: %d\n", deleteMin(&T));
    display(T);

    printf("\nHeapify: ");
    heapify(&T);
    display(T);
}

void insert(Set* T, int x){
    if(T->lastIDX != MAX-1){
        int temp,parent = (T->lastIDX - 1) / 2;
        T->arr[++T->lastIDX] = x;
        for(int i = T->lastIDX; i > 0 && T->arr[parent] > T->arr[i]; parent = (i-1)/2){
            swap(&T->arr[parent],&T->arr[i]);
            i = parent;
        }
    }
}

int deleteMin(Set* T){
    if(T->lastIDX != -1){
        int sChild = 0,lChild,rChild;
        int min = T->arr[0];
        T->arr[0] = T->arr[T->lastIDX--];

        for(int parent = 0; parent < T->lastIDX;){
            sChild = T->arr[parent];
            lChild = parent*2 + 1;
            rChild = parent*2 + 2;
            if(lChild <= T->lastIDX && T->arr[lChild] < T->arr[parent]){
                swap(&T->arr[lChild], &T->arr[parent]);
                parent = lChild;
            }
            else if(rChild <= T->lastIDX && T->arr[rChild] < T->arr[parent]){
                swap(&T->arr[rChild], &T->arr[parent]);
                parent = rChild;
            }
            else{
                return min;
            }
        }
    }
}

void initTree(Set* T){
    T->lastIDX = -1;
}

void display(Set T){
    for(int i = 0; i<=T.lastIDX; i++){
        printf("%d ", T.arr[i]);
    }
    printf("\n");
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(Set* T){
    int lChild, rChild, sChild, parent;
    for(int i = T->lastIDX; i > 0;){
        parent = (i-1)/2;
        lChild= parent*2 + 1;
        rChild= parent*2 + 2;
        if(T->arr[lChild] < T->arr[parent]){
            sChild = lChild;
            swap(&T->arr[lChild], &T->arr[parent]);
        }
        else if(T->arr[rChild] < T->arr[parent]){
            sChild = lChild;
            swap(&T->arr[rChild], &T->arr[parent]);
        }
        else{
            i--;
        }
    }
}