// for lesser confusion, the edges have been premade

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct node{
    int label; // number of the node
    struct node *next;
}*Vertex;

typedef Vertex AdjList[MAX];

void initAdjList(AdjList L);
void insertEdge(AdjList L, int edges[2]);
void displayAdjList(AdjList L);
void displayEdges(AdjList L);

int main(){
    int edges[][2] = {{1,2},{2,3},{3,0}}; // edges[3][2]
    int edgeCount = sizeof(edges)/sizeof(edges[0]); // edgeCount = 3

    AdjList L;
    initAdjList(L);

    for(int i = 0; i<edgeCount; i++){
        insertEdge(L, edges[i]); // i = 0, edges[0] = {1,2}, if i = 1, then it passes {2,3}
    }

    displayAdjList(L);
    displayEdges(L);

}

void initAdjList(AdjList L){
    for(int i = 0; i<MAX; i++){
        L[i] = NULL;
    }
}

void insertEdge(AdjList L, int edges[2]){
    Vertex temp = (Vertex)malloc(sizeof(struct node));

    if(temp != NULL){
        temp->label = edges[1]; // {1,2} passed, temp->label = 2
        temp->next = L[edges[0]]; // temp->next = L[1] = NULL
        L[edges[0]] = temp; 
    }
}

void displayAdjList(AdjList L){ // print all the nodes and their adjacent nodes, (print their *next)
    for(int i = 0 ; i<MAX; i++){
        printf("Node %d: ", i);

        if(L[i] == NULL){
            printf("No adjacent nodes");
        }
        else{
            for(Vertex trav = L[i]; trav != NULL; trav = trav->next){
                printf("%d ", trav->label);
            }
        }
        printf("\n");
    }
}

void displayEdges(AdjList L){
    printf("Edges: ");
    for(int i = 0; i<MAX; i++){
        for(Vertex trav = L[i]; trav != NULL; trav = trav->next){
            printf("(%d,%d)", i, trav->label);
        }
    }
}


