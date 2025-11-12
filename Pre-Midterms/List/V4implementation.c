#include <stdio.h>
#include <stdlib.h>
#define MAX 10



typedef struct node{
    char* arr;
    int count;
}*list;

void initList(list* ref);

int main(){
    list ptr;
    initList(&ptr);
}

void initList(list* ref){
    (*ref) = (list)malloc(sizeof(struct node));
    (*ref)->arr = (char*)malloc(sizeof(char)*MAX);
    (*ref)->count = 0;
}
