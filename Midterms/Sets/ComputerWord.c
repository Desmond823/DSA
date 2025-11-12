#include <stdio.h>
#include <stdlib.h>
#define MAX (sizeof(unsigned int) * 8)

typedef unsigned int Set;

void initSet(Set* S);
void showBitPattern(Set S);

void insertElem(Set* S, int elem);
void deleteElem(Set* S, int elem);
void displayElem(Set S);
Set Union(Set A, Set B);
Set Intersection(Set A, Set B);
Set (Set A, Set B);

int main(){
    Set S;
    initSet(&S);

    showBitPattern(S);
    //displayElem(S);

    // insertElem(&S, 3);
     insertElem(&S, 1);
    // insertElem(&S, 4);

    // deleteElem(&S, 5);
    // deleteElem(&S, 4);
    // deleteElem(&S, 1);

    showBitPattern(S);
    displayElem(S);
}

void initSet(Set* S){
    *S = 0;
}

void showBitPattern(Set S){
    for(int i = MAX - 1; i >= 0; i--){
        if((i+1) % 4 == 0){
            printf(" ");
        }
        printf("%d",(S >> i) & 1); // will display if the bit at position i is 1
    }
    printf("\n");
}

void insertElem(Set* S, int elem){ // basically inserting bit at that elem position
    if(elem < MAX){
        *S |= (1 << elem); // use OR when adding stuff
    }
}

void deleteElem(Set* S, int elem){ // delete bit at that elem position
    if(elem < MAX){
        *S &= ~(1 << elem); // gad knows how zeus does ts bru
    }
}

void displayElem(Set S){
    printf("[");
    for(int i = 0; i<MAX; i++){
        if((S >> i) & 1 == 1){
            printf("%d ", i);
        }
    }
    printf("]\n");
}