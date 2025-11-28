#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 9999


typedef struct node{
    int label;
    int weight;
    struct node* next;
}*Vertex;

typedef Vertex AdjList[MAX];

int* dijkstras(AdjList L, int origin);
void displayDjk(int* arr, int root);
void initList(AdjList L);
void insertEdge(AdjList L, int edges[3]);
void displayList(AdjList L);

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

    AdjList L;
    initList(L);

    for(int i = 0; i< edgeCount; i++){
        insertEdge(L,edges[i]);
    }

    displayList(L);

    int* djkArr = dijkstras(L, 2);
    displayDjk(djkArr, 2);
    

}

void initList(AdjList L){
    for(int i = 0; i < MAX; i++){
        L[i] = NULL;
    }
}

void insertEdge(AdjList L, int edges[3]){
    Vertex temp = (Vertex)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->label = edges[1];
        temp->next = L[edges[0]];
        temp->weight = edges[2];
        L[edges[0]] = temp;
    }
}

void displayList(AdjList L){
    for(int i = 0; i<MAX; i++){
        printf("Node %d: ", i);
        if(L[i] == NULL){
            printf("No Adjacent Node");
        }
        else{
            for(Vertex trav = L[i]; trav != NULL; trav=trav->next){
                printf("%d ", trav->label);
            }
        }
        printf("\n"); // NIGGER
    }
}

/*
    Pseudocode for dijkstraNIGGA
    1. Initialize an dynamically allocated array with MAX (macro) size
        1a. Set all values in retArr to INF
        1b. Set the origin index to 0
    2. Initialize an array called set with MAX size
        2a. Set values in all indexes to 0 in the set Array2
        2b. Declare origin index in set array to 1
    3. Declare for loop, i < MAX
        3a.1 First Inner For Loop: Search for index with smallest value that is in V-S (Elements in V not in S, V in this case is retArr)
        3a.2 Record index and flip its index in set to 1
        3b.1 Second Inner For Loop: Calculate new distance by using trav->label as destination index
        3b.2 newWeight = retArr[minIndex] + trav->weight
        3b.3 Compare newWeight with retArr[trav->label]
        3b.4 if smaller, replace retArr[trav->label] value to newWeight
    4. Return retArr
*/

int* dijkstras(AdjList L, int origin){
    if(origin < MAX){
        int* retArr = (int*)malloc(sizeof(int) * MAX);
        int set[MAX] = {0,0,0,0,0};
        set[origin] = 1;

        for(int i = 0; i<MAX; i++){
            retArr[i] = INF;
        }
        retArr[origin] = 0;

        for(Vertex trav = L[origin]; trav != NULL; trav=trav->next){
            retArr[trav->label] = trav->weight;
        }

        for(int i = 0; i<MAX; i++){
            int min = INF, index;
            for(int w = 0; w<MAX; w++){ // find minimum vertex;
                if(set[w] == 1) continue;
                if(retArr[w] < min){
                    min = retArr[w];
                    index = w;
                } 
            }
            set[index] = 1;
            //printf("%d ", index);


            for(Vertex trav = L[index]; trav!=NULL; trav=trav->next){ // compute for new weights
                int newWeight = retArr[index] + trav->weight;
                retArr[trav->label] = (newWeight < retArr[trav->label]) ? newWeight : retArr[trav->label];
            }
        }

        return retArr;
    }else{
            printf("That Node doesn't exist!\n");
        }
}

void displayDjk(int* arr, int root){
    printf("Shortest Path originating from Node %d:\n", root);
    for(int i = 0; i<MAX; i++){
        printf("Node %d: ", i);
        if(arr[i] == INF){
            printf("INF\n");
        }
        else{
            printf("%d\n", arr[i]);
        }
    }
}


