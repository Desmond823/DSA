#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6
#define EMPTY '?'
#define DELETED '*'


typedef char Dictionary[MAX];

void initDictionary(Dictionary D);
void displayDict(Dictionary D);
int hash(char elem);
void insert(Dictionary D, char elem);
void delete(Dictionary D, char elem);
bool isMember(Dictionary D, char elem);


int main(){

}

void initDictionary(Dictionary D){
    for(int i = 0; i<MAX; i++){
        D[i] = EMPTY;
    }
}

int hash(char elem){
    int idx;
    char arr[10] = {'a','b','c','d','e','f'};
    

}
