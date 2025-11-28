#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 99999

typedef int AdjMatrix[MAX][MAX];

int* djikstra(AdjMatrix M, int origin);
void initMatrix(AdjMatrix M);
void insertEdge(AdjMatrix M, int edges[3]);
void displayMatrix(AdjMatrix M);
void displayDjk(AdjMatrix M, int origin);

int main(){
    int edges[][3] = {{0,1,10},
                        {0,3,30},
                        {1,2,50},
                        {0,4,100},
                        {3,4,60},
                        {3,2,20},
                        {2,0,20},
                        {2,4,10}};
    int edgeCount = sizeof(edges)/sizeof(edges[0]);

    AdjMatrix M;
    initMatrix(M);

    for(int i = 0; i<edgeCount; i++){
        insertEdge(M, edges[i]);
    }

    displayMatrix(M);
    displayDjk(M,2);
}

void initMatrix(AdjMatrix M){
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            M[i][j] = INF;
        }
    }
}

void insertEdge(AdjMatrix M, int edges[3]){
    M[edges[0]][edges[1]] = edges[2];
}

void displayMatrix(AdjMatrix M){
    for(int i = 0; i<MAX; i++){
        printf("%d: ", i);
        for(int j = 0; j<MAX; j++){
            if(M[i][j] != INF) printf("%d ", M[i][j]);
            else printf("-1 ");
        }
        printf("\n");
    }
}

/*
    Pseudocode for dijkstraNIGGA (GLITCH IN THE MATRIX EDITION)
    1. Initialize an dynamically allocated array with MAX (macro) size
        1a. Set all values in retArr to M[origin][i] using a loop
        1b. Set the origin index to 0
    2. Initialize an array called set with MAX size
        2a. Set values in all indexes to 0 in the set Array
        2b. Set the origin to 1 with set[origin]
    3. Declare for loop, i < MAX
        3a.1 First Inner For Loop: Search for index with smallest value that is in V-S (Elements in V not in S, V in this case is retArr)
        3a.2 Record index and flip its index in set to 1
        3b.1 Second Inner For Loop: Calculate new distance by using trav->label as destination index
        3b.2 newWeight = retArr[minIndex] + trav->weight
        3b.3 Compare newWeight with retArr[trav->label]
        3b.4 if smaller, replace retArr[trav->label] value to newWeight
    4. Return retArr
*/

int* djikstra(AdjMatrix M, int origin){
    int* retArr = (int*)malloc(sizeof(int)*MAX);

    for(int i = 0; i<MAX; i++){
        retArr[i] = M[origin][i]; 
    }
    retArr[origin] = 0;

    int set[MAX];
    for(int i = 0; i<MAX; i++) set[i] = 0;
    set[origin] = 1;

    for(int i = 0; i<MAX; i++){
        
        int min = INF, minIdx = -1;
        for(int w = 0; w<MAX; w++){
            if(set[w] == 1) continue;
            if(retArr[w] < min){
                min = retArr[w];
                minIdx = w;
            }
        }
        if(minIdx != -1){
            set[minIdx] = 1;

            printf("%d ", minIdx);
            for(int v = 0; v<MAX; v++){
                if(set[v] == 0){
                    int newDist = retArr[minIdx] + M[minIdx][v];
                    if(newDist < retArr[v]) retArr[v] = newDist;
                }
            }
        }

    }

    return retArr;
}

void displayDjk(AdjMatrix M, int origin){
    int* djk = djikstra(M, origin);

    printf("Shortest path from Node %d:\n", origin);
    for(int i = 0; i<MAX; i++){
        if(djk[i] == INF) printf("Node %d: INF\n", i);
        else printf("Node %d: %d\n", i, djk[i]);
    }
}