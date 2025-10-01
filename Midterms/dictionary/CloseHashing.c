#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define EMPTY '?'
#define DELETED '*'


typedef char Dictionary[MAX];

void initDictionary(Dictionary D);

int main(){

}

void initDictionary(Dictionary D){
    for(int i = 0; i<MAX; i++){
        D[i] = EMPTY;
    }
}
