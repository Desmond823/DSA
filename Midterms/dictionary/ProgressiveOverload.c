#include <stdio.h>
#include <stdbool.h>
#define ARR_MAX 10
#define HASH_MAX (ARR_MAX/2)
#define EMPTY -999
#define DELETED -998

typedef struct{
    int data;
    int link;
}NodeType;

typedef struct{
    NodeType arr[ARR_MAX];
    int avail;
}Dictionary;

void initDict(Dictionary* D);
int hash(int x);
void insert(Dictionary* D, int x);
void delete(Dictionary* D, int x);
bool search(Dictionary* D, int x);
void print(Dictionary* D);

int main(){
    Dictionary D;
    initDict(&D);

    //populate my dict (heheheha)
    insert(&D, 1);
    insert(&D, 2);
    insert(&D, 3);
    insert(&D, 4);
    insert(&D, 5);
    insert(&D, 6);
    insert(&D, 7);
    insert(&D, 8);
    insert(&D, 9);
    insert(&D, 10);

    // test for full dict
    insert(&D, 11);
    insert(&D, 12);

    // test to delete element in main bucket
    delete(&D, 1);
    delete(&D, 2);

    // test to delete element in synonym bucket
    delete(&D, 10);
    delete(&D, 7);

    // replace deleted elements
    insert(&D, 11);
    insert(&D, 12);
    insert(&D, 16);
    insert(&D, 21);

    // search for existing element and non existing element
    printf("%d %s in the dictionary\n", 5, search(&D, 5) == true ? "is" : "is not");
    printf("%d %s in the dictionary\n", 99, search(&D, 99) == true ? "is" : "is not");

    print(&D);

}

void initDict(Dictionary* D){
    for(int i = 0; i<ARR_MAX-1; i++){
        if(i<HASH_MAX){
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
    return ((x % HASH_MAX) + HASH_MAX) % HASH_MAX;
}

void insert(Dictionary* D, int x){
    int hashVal = hash(x);
    if(D->arr[hashVal].data == EMPTY || D->arr[hashVal].data == DELETED){
        D->arr[hashVal].data = x;
    }
    else{
        int idx;
        for(idx = hashVal; D->arr[idx].link != -1; idx = D->arr[idx].link){}
        if(D->arr[idx].link == -1){
            int temp = D->avail;
            if(temp != -1){
                D->avail = D->arr[temp].link;
                D->arr[temp].data = x;
                D->arr[temp].link = -1;
                D->arr[idx].link = temp;
            }
            else printf("Cannot insert %d, dictionary is full :(\n", x);
        }
    }
}

void delete(Dictionary* D, int x){
    int hashVal = hash(x);
    if(D->arr[hashVal].data == x){
        D->arr[hashVal].data = DELETED;
    }
    else{
        int idx, temp;
        for(idx = hashVal; idx != -1 && D->arr[idx].data != x; idx = D->arr[idx].link){}
        if(idx != -1){
            for(temp = hashVal; D->arr[temp].link != idx; temp = D->arr[temp].link){} // unlink from previous node
            D->arr[temp].link = -1;
            D->arr[idx].link = D->avail;
            D->avail = idx;
        }
        else printf("%d does not exist in the dictionary\n", idx);
    }
}

bool search(Dictionary* D, int x){
    int hashVal = hash(x);
    int idx;
    for(idx = hashVal; idx != -1 && D->arr[idx].data != x; idx = D->arr[idx].link){}
    return (idx != -1) ? true : false;
}

void print(Dictionary* D){
    for(int i = 0; i<HASH_MAX; i++){
        printf("[%d]: ", i);
        for(int j = i; j != -1; j = D->arr[j].link){
            if(D->arr[j].data == EMPTY) printf("EMPTY ");
            if(D->arr[j].data == DELETED) printf("DELETED ");
            else printf("%d ", D->arr[j].data);
            if(D->arr[j].link != -1){
                printf("-> ");
            }
        }
        printf("\n");
    }
}

