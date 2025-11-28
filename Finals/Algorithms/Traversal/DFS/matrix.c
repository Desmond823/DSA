#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef int AdjMatrix[MAX][MAX];

void initMatrix(AdjMatrix M);
void insertEdge(AdjMatrix M, int edges[2]);
void displayMatrix(AdjMatrix M);
void DFS(AdjMatrix M, int root, int* visited);

int main(){
    int edges[][2] = {{4,6},{4,5},
                        {6,5},{6,3},
                        {5,1},{1,3},{1,2},
                        {3,2},{3,0},{2,0},
                        {0,2},{0,1}};
    int edgeCount = sizeof(edges)/sizeof(edges[0]);

    AdjMatrix M;
    initMatrix(M);
    
    for(int i = 0; i<edgeCount;i++) insertEdge(M, edges[i]);
    displayMatrix(M);

    int* visited = calloc(MAX,sizeof(int));
    for(int i = 0; i<MAX; i++){
        DFS(M,i,visited);
    }

}

void initMatrix(AdjMatrix M){
    for(int i=0;i<MAX;i++){
        for(int j = 0; j<MAX; j++){
            M[i][j] = 0;
        }
    }
}

void insertEdge(AdjMatrix M, int edges[2]){
    M[edges[0]][edges[1]] = 1;
}

void displayMatrix(AdjMatrix M){
    for(int i=0;i<MAX;i++){
        printf("Node %d: ", i);
        for(int j = 0; j<MAX; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }  
}

void DFS(AdjMatrix M, int root, int* visited){
    visited[root] = 1;
    for(int i = 0; i<MAX; i++){
        if(M[root][i] == 1 && visited[i] == 0) DFS(M, i, visited);
    }
}