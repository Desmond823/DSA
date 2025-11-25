#include <stdio.h>
#include <stdlib.h>
#define MAX 5


typedef struct node{
    int label;
    struct node* next;
}*Vertex;

typedef Vertex AdjList[MAX];

void initAdjList(AdjList L);
void insertEdge(AdjList L, int edges[2]);
void displayList(AdjList L);
void displayEdges(AdjList L);

int main(){
    int edges[][2] = {{1,2},{2,3},{3,0}};
    int edgeCount = sizeof(edges)/sizeof(edges[0]);

    AdjList L;
    initAdjList(L);

    for(int i = 0; i<edgeCount; i++){
        insertEdge(L, edges[i]);
    }

    displayList(L);
    displayEdges(L);
}

void initAdjList(AdjList L){
    for(int i = 0; i<MAX; i++){
        L[i] = NULL;
    }
}

void insertEdge(AdjList L, int edges[2]){ // {1,2}, {2,3}
    Vertex temp = (Vertex)malloc(sizeof(struct node));

    if(temp != NULL){ 
        temp->label = edges[1]; // 2, 3
        temp->next = L[edges[0]]; // temp = NULL
        L[edges[0]] = temp; // L[1] = 2
    }

    temp = (Vertex)malloc(sizeof(struct node));
    if(temp != NULL){ 
        temp->label = edges[0]; // 1, 2
        temp->next = L[edges[1]]; // L[2] = NULL, L[3] = NULL
        L[edges[1]] = temp; // L[2] = 1, L[3] = 2
    }
}

void displayList(AdjList L){
    for(int i = 0; i<MAX; i++){
        printf("Node %d: ", i);
        if(L[i] == NULL) printf("No Adjacent Nodes");
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
            printf("(%d,%d) ", i,trav->label);
        }
    }
}