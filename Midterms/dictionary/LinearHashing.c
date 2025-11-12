#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10
#define EMPTY -999
#define DELETED -998


typedef int Dictionary[MAX];

void initDictionary (Dictionary D);
int hash(int x);
void insert(Dictionary D, int x);
void delete(Dictionary D, int x);
bool search(Dictionary D, int x);
void print(Dictionary D);

int main(){
    Dictionary D;

    initDictionary(D);

    // populate till full
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

    // test for full dictionary
    insert(D, 11);
    insert(D, 12);

    // test for existing elements
    delete(D, 5);
    delete(D, 6);

    // test for nonexistent elements
    delete(D, 14);
    delete(D, 13);

    // replace deleted elements
    insert(D, 11);
    insert(D, 12);
    
    // search for existing and non existing element
    printf("%d %s in the Dictionary.\n", 1, search(D,1) == true ? "is" : "is not");
    printf("%d %s in the Dictionary.\n", 17, search(D,17) == true ? "is" : "is not");

    print(D);
}

void initDictionary(Dictionary D){
    for(int i = 0; i<MAX; i++){
        D[i] = EMPTY;
    }
}

int hash(int x){
    return ((x % MAX) + MAX) % MAX;
}

void insert(Dictionary D, int x){
    int hashVal = hash(x);
    int idx;
    int stop = (x + MAX - 1) % MAX;

    for(idx = hashVal; idx != stop && D[idx] != EMPTY && D[idx] != DELETED; idx = (idx+1) % MAX){}
    if(idx != stop){
        D[idx] = x;
    }
    else{
        printf("Cannot insert %d, dictionary is full!\n", x);
    }
}

void delete(Dictionary D, int x){
    int hashVal = hash(x);
    int idx;
    int stop = (x + MAX - 1) % MAX;

    for(idx = hashVal; idx != stop && D[idx] != x; idx = (idx+1) % MAX){}
    if(idx != stop){
        D[idx] = DELETED;
    }
    else{
        printf("%d does not exist in the dictionary.\n", x);
    }
}

bool search(Dictionary D, int x){
        int hashVal = hash(x);
    int idx;
    int stop = (x + MAX - 1) % MAX;

    for(idx = hashVal; idx != stop && D[idx] != x; idx = (idx+1) % MAX){}
    
    return (idx != stop) ? true : false;
}

void print(Dictionary D){
    for(int i = 0; i<MAX; i++){
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