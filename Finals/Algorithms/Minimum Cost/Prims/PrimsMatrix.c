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

MCT prims(adjMatrix M, int start);
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

    MCT primmie = prims(M,0);
    displayEdgeList(primmie.edges, primmie.edgeCount);
}

    MCT prims(adjMatrix M, int start){
        MCT retTree = {.edgeCount = 0, .totalWeight = 0}; // return variable
        int visited[MAX]; //bit-vector set for visited nodes

        for(int i = 0; i<MAX; i++) visited[i] = 0; // initialize everything to 0 (bit-vector)
        visited[start] = 1; // set source node to 1

        while(retTree.edgeCount != MAX-1){
            edgeType minEdge = {.weight = INF}; // initialize a variable to place in edge list

            for(int i = 0; i<MAX; i++){
                if(visited[i] == 1){ // if node is a visited node, check for its adjacent pairs
                    for(int j = 0; j<MAX; j++){
                        if(visited[j] == 0 && M[i][j] < minEdge.weight){ // if node is unvisited and is cheap af
                            edgeType temp = {i, j, M[i][j]}; // declare temp for easy initialization
                            minEdge = temp;
                        }
                    }
                }
            }

            if(minEdge.weight != INF){ // if weight is INF, then that edge doesnt exist,,, im just adding it for overthniking purposes whwahah
                retTree.edges[retTree.edgeCount++] = minEdge;
                retTree.totalWeight += minEdge.weight;
                visited[minEdge.destination] = 1; // set the destination node to 1
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
