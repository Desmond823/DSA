// this is zeus' linear hashing, written in the way I understood it

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10
#define EMPTY -1
#define DELETED -2


typedef int Dictionary[MAX];

void initDict(Dictionary D);
int hash(int x);
void insert(Dictionary D, int x);
void delete(Dictionary D, int x);
bool search(Dictionary D, int x);
void printDict(Dictionary D);

int main(){
    Dictionary D;
    initDict(D);

    insert(D, 1);
    insert(D, 2);
    insert(D, 3);
    insert(D, 4);
    insert(D, 5);
    insert(D, 6);
    insert(D, 7);
    insert(D, 8);
    insert(D, 9);
    insert(D, 10);

    insert(D, 15);

    delete(D, 10);
    delete(D, 20);
    insert(D, 20);

    printf("%d %s the dictionary.\n", 8, search(D, 8) == true ? "is in" : "is not in");
    printf("%d %s the dictionary.\n", 11, search(D, 11) == true ? "is in" : "is not in");

    printDict(D);
}

void initDict(Dictionary D){
    for(int i = 0; i < MAX; i++){
        D[i] = EMPTY;
    }
}

int hash(int x){
    return x % MAX;
}

void insert(Dictionary D, int x){
    int hashVal = hash(x);
    int idx = hashVal; 
    bool isFull = false;

    while(D[idx] != EMPTY && D[idx] != DELETED && isFull != true){ //if D[idx] is EMPTY or DELETED, loop breaks
        idx = (idx+1) % MAX;
        if(idx == hashVal) isFull = true; // if idx looped once, isFull becomes true and breaks the loop
    }

    if(isFull == true) printf("PUNO NA BAI!\n"); 
    else D[idx] = x;
    
}

void delete(Dictionary D, int x){
    int hashVal = hash(x);
    int idx = hashVal;
    bool looped = false;
    
    while(D[idx] != x && looped != true){ // stops if x has been found or idx looped once
        idx = (idx+1) % MAX;
        if(idx == hashVal) looped = true;
    }

    if(D[idx] == x && looped == false){ 
        D[idx] = DELETED;
        printf("%d successfully deleted\n", x);
    }
    else printf("%d does not exist.\n", x);
}

bool search(Dictionary D, int x){
    int hashVal = hash(x);
    int idx = hashVal;
    bool looped = false;

    while(D[idx] != x && looped != true){ // breaks if element is found or idx loops once
        idx = (idx+1) % MAX;
        if(idx == hashVal) looped = true;
    }
    return (looped == false) ? true : false; // returns true if elem is found
}

void printDict(Dictionary D){
    for(int i = 0; i < MAX; i++){
        printf("[%d]: ", i);
        if(D[i] == EMPTY){
            printf("EMPTY\n");
        }
        else if(D[i] == DELETED){
            printf("DELETED\n");
        }
        else{
            printf("%d\n", D[i]);
        }
    }
}

