#include <stdio.h>
#include <stdbool.h>
#define MAX 50


typedef struct{
    int elem;
    int next;
}NodeType;

typedef struct{
    NodeType Nodes[MAX];
    int avail;
}VHeap;

typedef int Set;

int allocSpace(VHeap* ref);
void deallocSpace(VHeap* ref, int idx);
void initVHeap(VHeap* ref);
void initSet(Set* S);
void insertToSet(VHeap* ref, Set* S, int data);
void populateSet(VHeap* ref, Set* S, int size);
void printSet(VHeap* ref, Set S);

Set Union(VHeap* ref, Set A, Set B);
Set Intersection(VHeap* ref, Set A, Set B);
Set Difference(VHeap* ref, Set A, Set B);

int main(){
    VHeap VH;
    Set A = -1, B = -1;

    initVHeap(&VH);

    int size;

    printf("How many elements to insert in Set A: ");
    scanf("%d", &size);
    populateSet(&VH,&A, size);



    printf("How many elements to insert in Set B: ");
    scanf("%d", &size);
    populateSet(&VH,&B, size);

    printf("\nSet A: ");
    printSet(&VH,A);
    printf("\nSet B: ");
    printSet(&VH, B);

    Set U = Union(&VH,A, B);
    printf("\n\nUnion: ");
    printSet(&VH, U);

    Set I = Intersection(&VH,A,B);
    printf("\n\nIntersection: ");
    printSet(&VH, I);
    
    Set D = Difference(&VH,A,B);
    printf("\n\nA - B: ");
    printSet(&VH, D);


}

void printSet(VHeap* ref, Set S){
    Set trav;
    printf("{");
    for(trav = S; trav != -1; trav = ref->Nodes[trav].next){
        printf("%d", ref->Nodes[trav].elem);
        if(ref->Nodes[trav].next != -1){
            printf(", ");
        }
    }
    printf("}");

}

void initVHeap(VHeap* ref){
    for(int i = 0; i<MAX;i++){
        ref->Nodes[i].next = i-1;
    }
    ref->avail = MAX-1;
}


int allocSpace(VHeap* ref){
    int temp = ref->avail;
    if(ref->avail != -1){
        ref->avail = ref->Nodes[temp].next;
    }
    return temp;
}

void populateSet(VHeap* ref, Set* S, int size){ // O(n)
    int data;
    for(int i = 0; i< size; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        insertToSet(ref, S, data);
    }
}

void deallocSpace(VHeap* ref, int idx){
    ref->Nodes[idx].next = ref->avail;
    ref->avail = idx;
}

void insertToSet(VHeap* ref, Set* S, int data){
    Set* trav = S;
    for(; *trav != -1 && ref->Nodes[*trav].elem != data; trav = &ref->Nodes[*trav].next){} // chekc if uniqeu
    if(*trav == -1){
        for(trav = S; *trav != -1 && ref->Nodes[*trav].elem < data; trav = &ref->Nodes[*trav].next){}
        int temp = allocSpace(ref);
        ref->Nodes[temp].elem = data;
        ref->Nodes[temp].next = *trav;
        *trav = temp;
    }
}

Set Union(VHeap* ref, Set A, Set B){
    Set U = -1;
    Set trav;
    for(trav = A; trav!= -1; insertToSet(ref, &U, ref->Nodes[trav].elem), trav = ref->Nodes[trav].next);
    for(trav = B; trav!= -1; insertToSet(ref, &U, ref->Nodes[trav].elem), trav = ref->Nodes[trav].next);

    return U;
}

Set Intersection(VHeap* ref, Set A, Set B){
    Set I = -1;
    Set travA,travB;
    
    for(travA = A; travA != -1; travA = ref->Nodes[travA].next){
        for(travB = B; travB != -1 && ref->Nodes[travB].elem <= ref->Nodes[travA].elem; travB = ref->Nodes[travB].next){
            if(ref->Nodes[travB].elem == ref->Nodes[travA].elem){
                insertToSet(ref, &I, ref->Nodes[travA].elem);
            }
        }
    }

    return I;
}

Set Difference(VHeap* ref, Set A, Set B){
    Set D = -1;
    Set travA, travB;

    for(travA = A; travA != -1; travA = ref->Nodes[travA].next){
        for(travB = B; travB != -1 && ref->Nodes[travB].elem != ref->Nodes[travA].elem; travB = ref->Nodes[travB].next);
        if(travB == -1){
            insertToSet(ref, &D, ref->Nodes[travA].elem);
        }
    }

    return D;
}


