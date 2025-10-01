#include <stdio.h>
#include <stdlib.h>
#define MAX 10


typedef struct{
    int elem[MAX];
    int size;
}Set;

void populateSet(Set* S, int size);
void insertToSet(Set* S, int data);
void deleteFromSet(Set* S, int data);
void printSet(Set* S);
Set Union(Set A, Set B);
Set Intersection(Set A, Set B);
Set Difference(Set A, Set B);

int main(){
    Set A = {{}, 0};
    Set B = {{}, 0};

    int size;

    printf("How many elements to insert in Set A: ");
    scanf("%d", &size);
    populateSet(&A, size);



    printf("How many elements to insert in Set B: ");
    scanf("%d", &size);
    populateSet(&B, size);

    printf("\nSet A: ");
    printSet(&A);
    printf("\nSet B: ");
    printSet(&B);

    Set U = Union(A, B);
    printf("\n\nUnion: ");
    printSet(&U);

    Set I = Intersection(A,B);
    printf("\n\nIntersection: ");
    printSet(&I);
    
    Set D = Difference(A,B);
    printf("\n\nA - B: ");
    printSet(&D);
}

void populateSet(Set* S, int size){ // O(n)
    int data;
    for(int i = 0; i< size; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        insertToSet(S, data);
    }
}

void insertToSet(Set* S, int data){ // O(n)
    int i;
    for(i = 0; i<S->size && data != S->elem[i]; i++){}
    if(i == S->size){ // runs if elem is unique
        for(i = 0; i<S->size && data > S->elem[i]; i++){} // insertSorted implementation
        for(int j = S->size; j>i; j--){
            S->elem[j] = S->elem[j-1]; 
        }
        S->elem[i] = data;
        S->size++;
    }
}

void printSet(Set* S){ // O(n)
    printf("{");
    for(int i = 0; i<S->size; i++){
        printf("%d", S->elem[i]);
        if(i < S->size-1){
            printf(", ");
        }
    }
    printf("}");
}

void deleteFromSet(Set* S, int data){ // O(n)
    int i;
    for(i = 0; i<S->size && S->elem[i] != data; i++){}
    if(i == S->size){
        printf("Element doesn't exist");
    }
    else{
        for(; i<-S->size-1; i++){
            S->elem[i] = S->elem[i+1];
        }
        S->size--;
    }
}

Set Union(Set A, Set B){ // O(n)
    Set U = {{},0};
    for(int i = 0; i<A.size; i++){
        insertToSet(&U, A.elem[i]);
    }
    for(int i = 0; i<B.size; i++){
        insertToSet(&U, B.elem[i]);
    }
    
    return U;
}

Set Intersection(Set A, Set B){ // O(n^2)
    Set I = {{},0};

    for(int i = 0; i<A.size; i++){
        for(int j = 0; j<B.size;j++){
            if(A.elem[i] == B.elem[j]){
                insertToSet(&I, A.elem[i]);
            }
        }
    }
    return I;
}

Set Difference(Set A, Set B){ // O(n^2), read as elements in A that are not in B
    Set D = {{}, 0};
    int i, j, flag=0;
    for(i = 0; i < A.size; i++){
        flag=0;
        for(j = 0; j<B.size;j++){
            if(B.elem[j] == A.elem[i]){
                flag=1;
            }
        }
        if(flag == 0){
            insertToSet(&D,A.elem[i]);
        }
    
    }

    return D;

}

