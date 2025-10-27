#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARR_MAX 10
#define HASH_MAX ARR_MAX/2
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
void printHashMap(int x);

void initDict(Dictionary* D);

int main(){
    Dictionary D;

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

void insertDictionary(Dictionary* D,int x){
    int* trav;
    int hashVal = hash(x);
    if(D->arr[hashVal].data == EMPTY || D->arr[hashVal].data == DELETED){
        D->arr[hashVal].data = x;
    }
    else{
        for(trav = &D->arr[hashVal].link; *trav != -1; trav = &D->arr[hashVal].link){}
        int temp = D->avail;
        if(temp != -1){
            D->avail = D->arr[temp].link;
            D->arr[temp].data = x;
            D->arr[temp].link = -1;
        }
    }
}