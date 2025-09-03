#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 8

typedef struct{
    char Elem[MAX];
    int Rear;
    int Front;
}Queue;

void Enqueue(Queue* Q, char x);
void Dequeue(Queue* Q);
char Front(Queue Q);

// Utility operations
void initQueue(Queue* Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);

int main(){
    Queue Q;
    initQueue(&Q);
    (isEmpty(Q) == true) ? printf("Queue is empty!\n") : printf("Queue is not empty!\n");

    Enqueue(&Q, 'a');
    Enqueue(&Q, 'b');
    Enqueue(&Q, 'c');
    Enqueue(&Q, 'd');
    Enqueue(&Q, 'd');
    Enqueue(&Q, 'd');
    Enqueue(&Q, 'd');
    Enqueue(&Q, 'd');
    printf("\n%d", Q.Rear);

}

void Enqueue(Queue* Q, char x){
    if(isEmpty(*Q) == true){ // change this code later
        Q->Rear++;
        if(Q->Rear == MAX){
            Q->Rear = 0;
        }
        Q->Elem[Q->Rear] = x;
    }
    else if(isFull(*Q) != true){
        Q->Rear++;
        if(Q->Rear == MAX){
            Q->Rear = 0;
        }
        Q->Elem[Q->Rear] = x;
    }
    else{
        printf("\nQueue is full!\n");
    }
}

void Dequeue(Queue* Q){
    if(isEmpty(*Q) != true){
        Q->Front++;
        if(Q->Front == MAX){
            Q->Front = 0;
        }
    }
}

char Front(Queue Q){
    return(isEmpty(Q) != true) ? Q.Elem[Q.Front]: printf("\nList is empty!\n");
}

void initQueue(Queue* Q){
    Q->Rear = 0;
    Q->Front = 1;
}

bool isEmpty(Queue Q){
    return (Q.Front == (Q.Rear + 1) % MAX) ? true : false;
}
bool isFull(Queue Q){
    return (Q.Front == (Q.Rear+2) % MAX) ? true : false;
}