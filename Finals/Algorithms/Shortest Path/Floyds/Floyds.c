#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 99999

typedef int AdjMatrix[MAX][MAX];

void insertEdge(AdjMatrix M, int edges[3]);
void initMatrix(AdjMatrix M);
void displayMatrix(AdjMatrix M);
void floyds(AdjMatrix M, AdjMatrix A);
void displayFloyds(AdjMatrix M);


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

    for(int i = 0; i<edgeCount; i++) insertEdge(M, edges[i]);
    displayMatrix(M);

    AdjMatrix A;
    floyds(M, A);
    printf("\nAfter Floyds Algo:\n");
    displayMatrix(A);

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
        printf("Node %d: ", i);
        for(int j = 0; j<MAX; j++){
            if(M[i][j] == INF) printf("-1\t");
            else printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}


/*
    Pseudocode for Floyds MAYWEATHER

    1. Assign all values in array M to array A.
    2. Set all origin points to 0.
    3. Declare a for loop (A).
    4. Declare a nested loop inside A (B).
    5. Declare a nested loop inside B (C).
        5a. Inside loop C, calculate for shortest distance using B->C = B->A + A->C
        if and only if B->A + A->C < B->C.
*/

void floyds(AdjMatrix M, AdjMatrix A){
    for(int i = 0; i<MAX; i++){ // copy all values from matrix M to matrix A
        for(int j = 0; j<MAX; j++){
            A[i][j] = M[i][j];
        }
    }

    for(int i = 0; i<MAX; i++) A[i][i] = 0; // set all origin points to 0

    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            for(int k = 0; k<MAX; k++){
                if(A[j][i] + A[i][k] < A[j][k]){
                    A[j][k] = A[j][i] + A[i][k];
                }
            }
        }
    }
}

// j = 3, k = 2, i = 0
// A[3][2] = 20
// A[3][0] = inf, A[0][2] = -1
// basically b->a + a->c < b->c then b->c = whatever i added up
