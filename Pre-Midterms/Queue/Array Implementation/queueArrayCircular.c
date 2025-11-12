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
void printStack(Queue* Q);

int main(){
    Queue Q;
    initQueue(&Q);
    (isEmpty(Q) == true) ? printf("Queue is empty!\n") : printf("Queue is not empty!\n");

    Enqueue(&Q, 'a');
    Enqueue(&Q, 'b');
    Enqueue(&Q, 'c');
    Enqueue(&Q, 'd');
    Enqueue(&Q, 'e');
    Enqueue(&Q, 'f');
    Enqueue(&Q, 'g');
    Enqueue(&Q, 'g');
    (isFull(Q) == true) ? printf("Queue is full!!\n") : printf("Queue is not full!\n");
    Dequeue(&Q);

    printStack(&Q);
    (isEmpty(Q) == true) ? printf("\nQueue is empty!\n") : printf("\nQueue is not empty!\n");

}

void Enqueue(Queue* Q, char x){
    if(isFull(*Q) != true){ 
        Q->Rear = (Q->Rear+1) % MAX;
        Q->Elem[Q->Rear] = x;
    }
}

void Dequeue(Queue* Q){
    if(isEmpty(*Q) != true){
        Q->Front = (Q->Front + 1) % MAX;
    }
}

char Front(Queue Q){
    return(isEmpty(Q) != true) ? Q.Elem[Q.Front]: '\0';
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

void printStack(Queue* Q){
    for(; isEmpty(*Q) != true; Dequeue(Q)){
        printf("%c ", Front(*Q));
    }
}