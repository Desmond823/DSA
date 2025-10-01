#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node* next;
}*Set;

void populateSet(Set* S, int size);
void insertToSet(Set* S, int data);
void deleteFromSet(Set* S, int data);
void printSet(Set S);
Set Union(Set A, Set B);
Set Intersection(Set A, Set B);
Set Difference(Set A, Set B);

int main(){
    Set A = NULL;
    Set B = NULL;

    int size;
    printf("How many elements to insert in Set A: ");
    scanf("%d", &size);
    populateSet(&A, size);

    printf("How many elements to insert in Set B: ");
    scanf("%d", &size);
    populateSet(&B, size);

    printf("\nSet A: ");
    printSet(A);
    printf("\nSet B: ");
    printSet(B);

    Set U = Union(A, B);
    printf("\n\nUnion: ");
    printSet(U);

    Set I = Intersection(A,B);
    printf("\n\nIntersection: ");
    printSet(I);
    
    Set D = Difference(A,B);
    printf("\n\nA - B: ");
    printSet(D);
    
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
    Set* trav = S;
    for(; (*trav) != NULL && (*trav)->elem != data; trav = &(*trav)->next){} // check if unique
    if(*trav == NULL){
        Set temp = (Set)malloc(sizeof(struct node));
        for(trav = S;(*trav) != NULL && (*trav)->elem < data; trav = &(*trav)->next){} //insertSorted
        temp->elem = data;
        temp->next = NULL;
        (*trav) = temp;
    }
}

void printSet(Set S){ // O(n)
    printf("{");
    for(Set trav = S; trav != NULL; trav = trav->next){
        printf("%d", trav->elem);
        if(trav->next != NULL){
            printf(", ");
        }
    }
    printf("}");
}

Set Union(Set A, Set B){
    Set U = NULL;
    Set trav;

    for(trav = A; trav!=NULL; trav=trav->next){
        insertToSet(&U,trav->elem);
    }

    for(trav = B; trav!=NULL; trav=trav->next){
        insertToSet(&U,trav->elem);
    }

    return U;
}
Set Intersection(Set A, Set B){
    Set I = NULL;
    Set travA, travB;

    for(travA = A; travA != NULL; travA = travA->next){
        for(travB = B; travB != NULL; travB = travB->next){
            if(travA->elem == travB->elem){
                insertToSet(&I, travA->elem);
            }
        }
    }

    return I;
}

Set Difference(Set A, Set B){
    Set D = NULL;
    Set travA, travB;
    int flag = 0;

    for(travA = A; travA != NULL; travA = travA->next){
        flag = 0;
        for(travB = B; travB != NULL && travB->elem != travA->elem; travB = travB->next){}
        if(travB == NULL){
            insertToSet(&D, travA->elem);
        }
    }

    return D;
}