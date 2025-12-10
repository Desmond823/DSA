#include <stdio.h>
#include <stdbool.h>
#define MAX 15

typedef struct{
    int arr[MAX];
    int lastIDX;
}PrioQueue;

void initPrioQueue(PrioQueue* Q);
void insert(PrioQueue* Q, int data);
int deleteMin(PrioQueue* Q);
void heapSort(PrioQueue* Q, int data);
void print(PrioQueue Q);

int main(){
    PrioQueue Q;
    initPrioQueue(&Q);

    Q.arr[++Q.lastIDX] = 3; // populate initial POT 
    Q.arr[++Q.lastIDX] = 4;
    Q.arr[++Q.lastIDX] = 9;
    Q.arr[++Q.lastIDX] = 8;
    Q.arr[++Q.lastIDX] = 5;
    Q.arr[++Q.lastIDX] = 9;
    Q.arr[++Q.lastIDX] = 10;
    Q.arr[++Q.lastIDX] = 10;
    Q.arr[++Q.lastIDX] = 18;
    Q.arr[++Q.lastIDX] = 9;
    Q.arr[++Q.lastIDX] = 6;

    printf("Before insertion: ");
    print(Q);

    printf("Test deleteMin, root = %d: ", deleteMin(&Q));
    

    // insert(&Q, 2);
    // printf("After insertion: ");
    print(Q);


}

void initPrioQueue(PrioQueue* Q){
    Q->lastIDX = -1;
}

void print(PrioQueue Q){
    for(int i = 0; i <= Q.lastIDX; i++){
        printf("%d ", Q.arr[i]);
    }
    printf("\n");
}

void insert(PrioQueue* Q, int data){
    if(Q->lastIDX != MAX-1){
        Q->arr[++Q->lastIDX] = data;
        int current = Q->lastIDX;
        int parent = (current - 1) / 2;

        while(current != 0 && Q->arr[parent] > Q->arr[current]){
            int temp = Q->arr[parent];
            Q->arr[parent] = Q->arr[current];
            Q->arr[current] = temp;
            current = parent;
            parent = (current - 1)/2;
        }
    }
}

int deleteMin(PrioQueue* Q){
    if(Q->lastIDX != -1){
        int retVal = Q->arr[0];
        Q->arr[0] = Q->arr[Q->lastIDX--];

        int current = 0;
        int left, right;

        while(1){
            left = (current * 2) + 1;
            right = left+1;
            if(left > Q->lastIDX) break;

            int min = left; // record index

            if(right <= Q->lastIDX && Q->arr[right] < Q->arr[min]) min = right;

            int temp;
            if(Q->arr[current] > Q->arr[min]){
                temp = Q->arr[min];
                Q->arr[min] = Q->arr[current];
                Q->arr[current] = temp;
                current = min;
            }else break;
        }
        return retVal;
    }
}