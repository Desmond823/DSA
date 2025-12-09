#include <stdio.h>
#include <stdlib.h>
#define MAX 6
#define INF 99999

typedef struct{
    int source, destination;
    int weight;
}edgeType;

typedef struct{
    edgeType edges[MAX-1]; // MAX-1 because the number of edges is -1 the number of nodes
    int edgeCount; // basically size or smthn wahaha
    int totalWeight;
}MCT; // Minimum Cost Tree shortened

typedef int adjMatrix[MAX][MAX];

MCT kruskals(adjMatrix M);
void displayEdgeList(edgeType edges[], int size);

void initMatrix(adjMatrix M);
void insertEdge(adjMatrix M, int edges[3]);
void displayMatrix(adjMatrix M);
void displayEdges(adjMatrix M);

int main(){
    int edges[][3] = {
                        {0,1,1},
                        {0,2,5},
                        {0,3,4},
                        {0,4,6},
                        {0,5,5},
                        {1,2,5},
                        {2,3,2},
                        {3,4,1},
                        {4,5,3},
                        {5,1,6}
                    };
    int edgeCount = sizeof(edges)/sizeof(edges[0]);
    
    adjMatrix M;
    initMatrix(M);

    for(int i = 0; i<edgeCount; i++){
        insertEdge(M,edges[i]);
    }
    displayMatrix(M);
    displayEdges(M);

    MCT krusified = kruskals(M);
    displayEdgeList(krusified.edges, krusified.edgeCount);
}

MCT kruskals(adjMatrix M){
    adjMatrix copy;
    MCT retTree = {.edgeCount = 0, .totalWeight = 0};
    
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            copy[i][j] = M[i][j];
        }
    }

    while(retTree.edgeCount != MAX-1){
        edgeType minEdge = {.weight = INF};

        for(int i = 0; i<MAX; i++){ // check for every value in adjMatrix
            for(int j = 0; j<MAX; j++){
                if(copy[i][j] < minEdge.weight){ // just record the edge with smallest weight
                    edgeType temp = {i,j,copy[i][j]};
                    minEdge = temp;
                }
            }
        }

        if(minEdge.weight != INF){
            retTree.edges[retTree.edgeCount++] = minEdge;
            retTree.totalWeight += minEdge.weight;
            copy[minEdge.source][minEdge.destination] = INF; // erase edge from adjMatrix to prevent redundancy
            copy[minEdge.destination][minEdge.source] = INF; // erase both ways bra
        }
    }
    return retTree;
}

void initMatrix(adjMatrix M){
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            M[i][j] = INF;
        }
    }
}

void insertEdge(adjMatrix M, int edges[3]){
    M[edges[0]][edges[1]] = edges[2];
    M[edges[1]][edges[0]] = edges[2];
}

void displayMatrix(adjMatrix M){
    for(int i = 0; i<MAX; i++){
        printf("Node %d: ", i);
        for(int j = 0; j<MAX; j++){
            (M[i][j] == INF) ? printf("INF\t") : printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}

void displayEdges(adjMatrix M){
    printf("Edges: ");
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            if(M[i][j] != INF) printf("(%d,%d) ", i,j);
        }
    }
    printf("\n");
}

void displayEdgeList(edgeType edges[], int size){
    printf("\nAfter Prims: ");
    int totalWeight = 0;
    for(int i = 0; i<size; i++){
        printf("(%d, %d, %d) ", edges[i].source, edges[i].destination, edges[i].weight);
        totalWeight += edges[i].weight;
    }
    printf("\nTotal Weight: %d\n", totalWeight);
}
