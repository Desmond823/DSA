// given a adjacent matrix, convert it to a adjacent list, maybe u can also
// print ordered pairs heheheha

#include <stdio.h>
#include <stdlib.h>
#define MAX 8
typedef int adjMatrix[MAX][MAX];

typedef struct node{
    char label;
    struct node* next;
}*Vertex;


typedef Vertex adjList[MAX];


void insertEdge(adjList L, int source, int destination);

int main(){
    adjMatrix M = {
                    {0,1,0,0,0,0,0,1}, // a
                    {0,0,0,0,0,1,0,0}, // b 
                    {1,0,0,0,0,0,0,0}, // c
                    {0,0,0,0,1,0,0,1}, // d
                    {0,1,0,0,0,0,0,1}, // e
                    {0,0,1,0,0,0,0,0}, // f
                    {1,0,1,0,0,1,0,0}, // g
                    {0,0,0,0,0,0,0,0}, // h
                };

    adjList L;
    for(int i = 0; i<MAX; i++) L[i] = NULL; // initialize each bucket to NULL

    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            if(M[i][j] == 1) insertEdge(L, i,j); // if 1 then insert
        }
    }

    for(int i = 0; i<MAX; i++){
        printf("Node %c: ", i+65);
        if(L[i] == NULL) printf("No adjacent node");
        else{    
            for(Vertex trav = L[i]; trav!=NULL;trav=trav->next){
                printf("%c ", trav->label);
            }
        }
        printf("\n");
    }
}

void insertEdge(adjList L, int source, int destination ){
    Vertex temp = (Vertex)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->label = destination+65;
        temp->next = L[source];
        L[source] = temp;
    }
}

