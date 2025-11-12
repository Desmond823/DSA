// This implementation is similar to cursor-based
// dont do the same mistake I did and use PPN for inserting heheheha

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARR_MAX 10
#define HASH_MAX (ARR_MAX/2)
#define EMPTY -1
#define DELETED -2

typedef struct{
    int data;
    int link;
}nodeType;

typedef struct{
    nodeType arr[ARR_MAX];
    int avail;
}Dictionary;

int hash(int x);
void insertDictionary(Dictionary* D,int x);
int deleteDictionary(Dictionary* D,int x);
void printHashMap(Dictionary* D);

void initDict(Dictionary* D);

int main(){
    Dictionary D;

    initDict(&D);

    insertDictionary(&D, 1);
    insertDictionary(&D, 2);
    insertDictionary(&D, 3);
    insertDictionary(&D, 4);
    insertDictionary(&D, 5);
    insertDictionary(&D, 6);
    insertDictionary(&D, 7);
    insertDictionary(&D, 8);
    insertDictionary(&D, 9);
    insertDictionary(&D, 11);
    insertDictionary(&D, 16);

    deleteDictionary(&D, 2);
    deleteDictionary(&D, 11);
    insertDictionary(&D, 13);

    printHashMap(&D);
}

void initDict(Dictionary* D){
    for(int i = 0; i< ARR_MAX-1; i++){
        if(i < HASH_MAX){
            D->arr[i].data = EMPTY;
            D->arr[i].link = -1;
        }
        else{
            D->arr[i].link = i+1;
        }
    }
    D->arr[ARR_MAX-1].link = -1;
    D->avail = HASH_MAX;
}

int hash(int x){
    return x % HASH_MAX;
}

void printHashMap(Dictionary* D){ 
    for(int i = 0; i<HASH_MAX; i++){
        printf("Hash value %d: ", i);
        for(int j = i; j != -1; j = D->arr[j].link){
            D->arr[j].data != DELETED ? printf("%d ", D->arr[j].data) : printf("DELETED ");
            if(D->arr[j].link != -1){
                printf("-> ");
            }
        }
        printf("\n");
    }
}

void insertDictionary(Dictionary* D,int x){ 
    int trav;
    int hashVal = hash(x);
    
    if(D->arr[hashVal].data == EMPTY || D->arr[hashVal].data == DELETED){
        D->arr[hashVal].data = x;
    }
    else{
        for(trav = hashVal; D->arr[trav].link != -1; trav = D->arr[trav].link){} //travel to the end of the link of that hashVal index
        int temp = D->avail; // allocSpace
        if(temp != -1){
            D->avail = D->arr[temp].link;
            D->arr[temp].data = x;
            D->arr[temp].link = -1;
            D->arr[trav].link = temp;
        }
        else{
            printf("Cant insert %d! Dictionary is full!\n", x);
        }
    }
}

int deleteDictionary(Dictionary* D,int x){
    int hashVal= hash(x);
    int trav;
    for(trav = hashVal; trav != -1 && D->arr[trav].data != x; trav = D->arr[trav].link){}
    
    if(trav < HASH_MAX) D->arr[trav].data = DELETED;
    else if(trav>=HASH_MAX){
        D->arr[trav].data = DELETED;
        D->arr[trav].link = D->avail;
        int temp = trav;
        D->avail = trav;
        
        for(trav = hashVal; D->arr[trav].link != temp; trav = D->arr[trav].link){}
        D->arr[trav].link = -1;
    }
    else printf("%d does not exist!\n", x);
}