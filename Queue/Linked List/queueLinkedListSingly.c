#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char elem;
    struct node* next;
}*LIST;

typedef struct{
    LIST front;
    LIST rear;
}Queue;

void initQueue(Queue* ref);
void Enqueue(Queue* ref, char x);
void Dequeue(Queue* ref);
char Front (Queue ref);

void printQueue(Queue* ref);

int main(){
    Queue Q;
    initQueue(&Q);

    Enqueue(&Q, 'a');
    Enqueue(&Q, 'b');
    Enqueue(&Q, 'c');
    Enqueue(&Q, 'd');
    Enqueue(&Q, 'e');
    Enqueue(&Q, 'f');
    Dequeue(&Q);
    Dequeue(&Q);
    Dequeue(&Q);
    Dequeue(&Q);
    Dequeue(&Q);
    Dequeue(&Q);
    Dequeue(&Q);
    Enqueue(&Q, 'z');

    printQueue(&Q);
}

void initQueue(Queue* ref){
    ref->front = NULL;
    ref->rear = NULL;
}

void Enqueue(Queue* ref, char x){
    LIST temp = (LIST)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->elem = x;
        temp->next = NULL;
        if(ref->front == NULL){
            ref->front = temp;
        }
        else{
            ref->rear->next = temp;
        }
        ref->rear = temp;
    }
}

void Dequeue(Queue* ref){
    if(ref->front != NULL){
        ref->front = ref->front->next;
        if(ref->front == NULL){
            ref->rear = NULL;
        }
    }
}

char Front(Queue ref){
    return (ref.front != NULL) ? ref.front->elem : '\0';
}

void printQueue(Queue* ref){
    for(; ref->front != NULL; Dequeue(ref)){
        printf("%c ", Front(*ref));
    }
}