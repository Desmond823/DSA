#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char elem;
    struct node* prev;
    struct node* next;
}*LIST;

typedef struct{
    LIST front;
    LIST rear;
}Queue;

void initQueue(Queue* Q);
void Enqueue(Queue* Q, char x);
void Dequeue(Queue* Q);
char Front(Queue Q);

int main(){
    Queue Q;
    initQueue(&Q);

    Enqueue(&Q, 'a');
    Enqueue(&Q, 'b');
    Enqueue(&Q, 'c');
    Enqueue(&Q, 'd');

    printf("%c", Front(Q));
    Dequeue(&Q);
    printf("%c", Front(Q));
    Dequeue(&Q);
    printf("%c", Front(Q));
    Dequeue(&Q);
    printf("%c", Front(Q));
    Dequeue(&Q);
    printf("%c", Front(Q));
}

void initQueue(Queue* Q){
    Q->front = NULL;
    Q->rear = NULL;
}

void Enqueue(Queue* Q, char x){
    LIST temp = (LIST)malloc(sizeof(struct node)); // make new node
    if(temp != NULL){
        temp->elem = x;
        temp->next = NULL; 
        temp->prev = Q->rear; // initialize prev
        if(Q->front == NULL){
            Q->front = temp;
        }
        else{
            Q->rear->next = temp;
        }
        // initialize new rear
        Q->rear = temp; // reinitialize rear to new node

        // circly linky
        Q->rear->next = Q->front; // have rears next point to front
        Q->front->prev = Q->rear; // link front to the new rear
    }
}

void Dequeue(Queue *Q){
    if(Q->front != NULL){
        LIST temp = Q->front;
        Q->front = temp->next; // change front
        
        Q->front->prev = Q->rear;
        Q->rear->next = Q->front; 
        free(temp);
    }
}

char Front(Queue Q){
    return (Q.front->elem != NULL) ? Q.front->elem : '\0' ;
}


