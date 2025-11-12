#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    char* arr;
    int count;
}list;

void initList(list* ref);

int main(){
    list L;
    initList(&L);
}

void initList(list* ref){
    ref->arr = (char*)malloc(sizeof(char)*4);
    ref->count = 0;
}