#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    char elem[MAX];
    int count;
}charList;

bool findElem(charList L, char A);
void deleteElem(charList* L, char A);

int main(){
    charList L = {"motivation",10};
    printf("%d\n", findElem(L,'m')); // If A is in Elem
    printf("%d\n", findElem(L,'p')); // If A is not in Elem or if Elem is empty
    
    // If L isnt empty and A exists in Elem
    deleteElem(&L,'m'); // first pos
    deleteElem(&L,'a'); // middle pos
    deleteElem(&L,'n'); // last pos
    
    for(int i = 0; i<L.count; i++){ // print
        printf("%c", L.elem[i]);
    }
}

bool findElem(charList L, char A){ // constraint: one return statement only
    int i;
    for(i = 0; L.elem[i] != A && i < L.count; i++){} // i records the position and will end early if character is found
    return (L.elem[i] == A)? true : false; // ternary return statement (kinda cool lowk)
}

void deleteElem(charList* L, char A){ // constraint: no return, no break or continue statements
    int i, j;
    for(i = 0; L->elem[i] != A && i < L->count; i++){} // first loop is to determine if A exists in L->elem
    if(L->elem[i] == A){ // if it exists it will run the code inside
        for(j = i; j < L->count; L->elem[j] = L->elem[j+1], j++){}
        L->count--;
    }
}
