#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 15

typedef struct{
    int arr[MAX];
    int lastIDX;
}PQ;

void initPrioQueue(PQ* Q);
void Insert(PQ* Q, int elem);
int Deletemin(PQ* Q);
void Makenull(PQ* Q);
void swap(int* x, int* y);
void print(PQ* Q);

int main(){
    PQ Q;
    initPrioQueue(&Q);

    Q.arr[++Q.lastIDX] = 3; // populate initial POT 
    Q.arr[++Q.lastIDX] = 5;
    Q.arr[++Q.lastIDX] = 9;
    Q.arr[++Q.lastIDX] = 8;
    Q.arr[++Q.lastIDX] = 6;
    Q.arr[++Q.lastIDX] = 9;
    Q.arr[++Q.lastIDX] = 10;
    Q.arr[++Q.lastIDX] = 10;
    Q.arr[++Q.lastIDX] = 18;
    Q.arr[++Q.lastIDX] = 9;

    printf("Before inserting: ");
    print(&Q);

    printf("After inserting 4: ");
    Insert(&Q, 4);
    print(&Q);

    printf("After deleting %d: ", Deletemin(&Q));
    print(&Q);
}

void initPrioQueue(PQ* Q){
    Q->lastIDX = -1;
}

void Insert(PQ* Q, int elem){
    if(Q->lastIDX != MAX-1){
        Q->arr[++Q->lastIDX] = elem;
        int parent = (Q->lastIDX - 1) / 2;
        for(int i = Q->lastIDX; i > 0 && Q->arr[parent] > Q->arr[i]; parent = (parent-1)/2){
            swap(&Q->arr[parent], &Q->arr[i]);
            i = parent;
        }
    }
}

int Deletemin(PQ* Q){
    int temp = Q->arr[0];
    Q->arr[0] = Q->arr[Q->lastIDX--];
    int flag = 0;

    for(int i = 0; i <= Q->lastIDX && flag == 0; ){
        flag = 1;
        int lChild = i*2 + 1;
        int rChild = i*2 + 2;
        int sChild = 99999;

        if(rChild <= Q->lastIDX && Q->arr[rChild] <= Q->arr[lChild]) sChild = rChild; // keep index of rChild
        else if(lChild <= Q->lastIDX) sChild = lChild; // keep index of lChild

        if(Q->arr[i] >= Q->arr[sChild]){
            swap(&Q->arr[i], &Q->arr[sChild]);
            flag = 0;
            i = sChild;
        }
    }
    return temp;
}

void print(PQ* Q){
    for(int i = 0; i<=Q->lastIDX; i++){
        printf("%d ", Q->arr[i]);
    }
    printf("\n");
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

