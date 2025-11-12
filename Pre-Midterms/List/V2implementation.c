#include <stdio.h>
#include <stdlib.h>
#define MAX 10



typedef struct node{
    char arr[MAX];
    int count;
}*list;


void initList(list* L);

int main(){
    list L;
}

void initList(list* L){
    (*L) = (list)malloc(sizeof(struct node));
    (*L)->count = 0;
}

