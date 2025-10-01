#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef int Set[MAX];

void populateSet(Set A);
void printSet(Set S);
Set* Union(Set A, Set B);
Set* Intersection(Set A, Set B);
Set* Difference(Set A, Set B);

int main(){
    Set A = {};
    Set B = {};


    printf("Enter %d elements for Set A: \n", MAX);
    populateSet(A);
    printf("Enter %d elements for Set B: \n", MAX);
    populateSet(B);

    printf("Set A: ");
    printSet(A);
    printf("Set B: ");
    printSet(B);

    Set* U = Union(A,B);
    printf("Union: ");
    printSet(*U);

    Set* I = Intersection(A,B);
    printf("Intersection: ");
    printSet(*I);

    Set* D = Difference(A,B);
    printf("A - B: ");
    printSet(*D);



}

void populateSet(Set S){
    for(int i = 0; i<MAX;){ // only 1s and 0s
        printf("Enter element %d: ", i+1);
        scanf("%d", &S[i]);
        if(S[i] == 0 || S[i] == 1){
            i++;
        }
        else{
            printf("Only 1s and 0s\n");
        }
    }
    printf("\n");
}

void printSet(Set S){
    printf("{");
    for(int i = 0; i<MAX; i++){
        printf("%d", S[i]);
        if(i<MAX-1){
            printf(", ");
        }
    }
    printf("}\n");
}

Set* Union(Set A, Set B){
    Set* U = (Set*)malloc(sizeof(Set));
    if(U != NULL){
        for(int i = 0; i<MAX; i++){
            (*U)[i] = A[i] | B[i];
        }
    }    
    return U;
}

Set* Intersection(Set A, Set B){
    Set* I = (Set*)malloc(sizeof(Set));
    if(I != NULL){
        for(int i = 0; i<MAX; i++){
            (*I)[i] = A[i] & B[i];
        }
    }
    
    return I;
}

Set* Difference(Set A, Set B){
    Set* D = (Set*)malloc(sizeof(Set));
    if(D != NULL){
        for(int i = 0; i<MAX; i++){
            (*D)[i] = A[i] & (~B[i]);
        }
    }
}