#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char elem;
    struct node* next;
    struct node* prev;
}*List;

typedef struct{
    List Front;
    List Rear;
}Queue;

void initQueue(Queue* Q);
void enqueue(Queue* Q, char x);
void dequeue(Queue* Q);
char front(Queue Q);

bool isEmpty(Queue Q);

int main(){
    Queue Q;
    initQueue(&Q);

    enqueue(&Q, 'a');
    printf("%c", front(Q));
    enqueue(&Q, 'b');
    printf("%c", front(Q));
    enqueue(&Q, 'c');
    printf("%c", front(Q));
    enqueue(&Q, 'd');
    printf("%c", front(Q));
    enqueue(&Q, 'e');
    printf("%c", front(Q));
    printf("\n");

    dequeue(&Q);
    printf("%c", front(Q));
    dequeue(&Q);
    printf("%c", front(Q));
    dequeue(&Q);
    printf("%c", front(Q));
    dequeue(&Q);
    printf("%c", front(Q));

}

void initQueue(Queue* Q){
    Q->Front = NULL;
    Q->Rear = NULL;
}

void enqueue(Queue* Q, char x){
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->elem = x;
        temp->next = NULL;
        temp->prev = Q->Rear;
        if(isEmpty(*Q) == true){
            Q->Front = temp;
        }
        else{
        Q->Rear->next = temp;
        }
        Q->Rear = temp;
    }
}

void dequeue(Queue* Q){
    if(isEmpty(*Q) != true){
        List temp = Q->Front;
        Q->Front = Q->Front->next;
        free(temp); 
    }
}

char front(Queue Q){
    return(isEmpty(Q) != true) ? Q.Front->elem : '\0';
}

bool isEmpty(Queue Q){
    return (Q.Front == NULL) ? true : false;
}