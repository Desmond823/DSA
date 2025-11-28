#include <stdio.h>
#include <stdlib.h>
#define MAX 7


typedef struct node{
    int label;
    struct node* next;
}*Vertex;

typedef Vertex AdjList[MAX];

void insertEdge(AdjList L, int edges[2]);
void initList(AdjList L);
void displayList(AdjList L);
void DFS(AdjList L, int* set, int root);

int main(){
    int edges[][2] = {{4,6},{4,5},
                        {6,5},{6,3},
                        {5,1},{1,3},{1,2},
                        {3,2},{3,0},{2,0},
                        {0,2},{0,1}};
    int edgeCount = sizeof(edges)/sizeof(edges[0]);

    AdjList L;
    initList(L);

    for(int i = 0; i<edgeCount;i++){
        insertEdge(L,edges[i]);
    }
    displayList(L);

    int mark[MAX];
    for(int i = 0;i<MAX; i++)mark[i] = 0;
    
    for(int i = 0; i<MAX; i++){
        if(mark[i] == 0) DFS(L,mark,i);
    }
}

void initList(AdjList L){
    for(int i = 0; i<MAX; i++) L[i] = NULL;
}

void insertEdge(AdjList L, int edges[2]){
    Vertex temp = (Vertex)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->label = edges[1];
        temp->next = L[edges[0]];
        L[edges[0]] = temp;
    }
}

void displayList(AdjList L){
    for(int i = 0; i<MAX; i++){
        printf("Node %d: ", i);
        if(L[i] == NULL) printf("No adjacent nodes");
        else{
            for(Vertex trav = L[i]; trav != NULL; trav = trav->next){
                printf("%d ", trav->label);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void DFS(AdjList L,int* set, int root){
    Vertex trav = L[root];
    set[root] = 1;
        
    for(; trav != NULL; trav=trav->next){
        if(set[trav->label] == 0) DFS(L,set,trav->label);   
    }
    
}


