#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int Set[MAX];

typedef struct node{
    int elem;
    struct node* link;
}*NodeType;

typedef NodeType Dictionary[MAX];

int hash(int data);
void initDic(Dictionary D);
void displayDic(Dictionary D);
void insert(Dictionary D, int data);
//void populateDic(Dictionary D, Set S); // use if needed

int main(){
    Dictionary D;
    initDic(D);


    insert(D, 10);
    insert(D, 20);
    insert(D, 50);
    insert(D, 30);
    insert(D, 13);
    insert(D, 11);
    displayDic(D);
}

int hash(int data){
    return (data == 0) ? 0 : data % 10;
}

void initDic(Dictionary D){
    for(int i = 0; i<MAX; i++){
        D[i] = NULL;
    }
}

void displayDic(Dictionary D){
    for(int i = 0; i<MAX; i++){
        if(D[i] != NULL){
            printf("Group %d: ", i);
            NodeType trav;
            for(trav = D[i]; trav != NULL; trav = trav->link){
                printf("%5d",trav->elem);
            }
            printf("\n");
        }
    }
}

void insert(Dictionary D, int data){
    int group = hash(data);
    NodeType check = D[group];

    for(check = D[group]; check != NULL && check->elem != data; check = check->link){} // check if unique
    if(check == NULL){
        NodeType* trav = &D[group];
        for(; *trav != NULL && (*trav)->elem < data; trav = &(*trav)->link){} // insert sorted;
        NodeType temp = (NodeType)malloc(sizeof(struct node));
        temp->elem = data;
        temp->link = *trav;
        *trav = temp; 
    }
}

