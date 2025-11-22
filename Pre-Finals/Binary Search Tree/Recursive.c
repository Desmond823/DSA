#include <stdio.h>
#include <stdlib.h>
#define MAX 10;

typedef struct node{
    int data;
    struct node* LC;
    struct node* RC;
}*BST;

void initBST(BST* T);
void insert(BST* T, int data);
void delete(BST* T, int data);
int member(BST T, int data);
int min(BST T);
int max(BST T);

void prefixPrint(BST T);
void postfixPrint(BST T);
void infixPrint(BST T);

int main(){
    int setA[7] = {10,5,14,12,7,18,15}; // sample data
    BST root;
    initBST(&root);
    
    for(int i = 0; i<7; i++){
        insert(&root, setA[i]);
    }

    printf("prefix: ");
    prefixPrint(root);
    printf("\n");

    printf("Insert 11: ");
    insert(&root, 11);
    prefixPrint(root);
    printf("\n");
    
    printf("Delete 10: ");
    delete(&root, 10);
    prefixPrint(root);
    printf("\n");

    printf("Min: %d\n", min(root));
    printf("Max: %d\n", max(root));

    printf("Is 15 a member? %s\n", member(root, 15) == 1 ? "Yes" : "No"); // check for existing element
    printf("Is 20 a member? %s\n", member(root, 20) == 1 ? "Yes" : "No"); // check for nonexisting element


}

void initBST(BST* T){
    *T = NULL;
}

void insert(BST* T, int data){
    if(*T == NULL){
        BST temp = (BST)malloc(sizeof(struct node));
        temp->data = data;
        temp->LC = NULL;
        temp->RC = NULL;
        *T = temp;
    }
    else{
        if(data < (*T)->data) insert(&(*T)->LC, data);
        else if(data > (*T)->data) insert(&(*T)->RC, data);
        else printf("not unique");
    }
}

void delete(BST* T, int data){
    if(*T == NULL){
        printf("nonexistent\n");
    }
    else if((*T)->data == data){
        BST temp = *T;
        if(temp->LC != NULL && temp->RC == NULL){
            *T = temp->LC;
            free(temp);
        } 
        else if(temp->LC == NULL && temp->RC != NULL){
            *T = temp->RC;
            free(temp);
        }
        else if(temp->LC == NULL && temp->RC == NULL){
            *T = NULL;
            free(temp);
        }
        else{
            int tempVal;
            // option 1: immediate successor
            tempVal = min(temp->RC);
            delete(&temp, min(temp->RC));
            temp->data = tempVal;

            // option 2: preceeding successor
            // tempVal = max(temp->LC);
            // delete(&temp, max(temp->LC));
            // temp->data = tempVal;
        }
    }
    else{
        if(data > (*T)->data) delete(&(*T)->RC, data);
        else if(data < (*T)->data) delete(&(*T)->LC, data);
    }
}

int member(BST T, int data){
    if(T == NULL) return 0;
    else if(T->data == data) return 1;
    else{
        if(data < T->data) return member(T->LC, data);
        if(data > T->data) return member(T->RC, data);
    }
}

int min(BST T){
    if(T->LC != NULL) return min(T->LC);
    else return T->data;
}
int max(BST T){
    if(T->RC != NULL) return max(T->RC);
    else return T->data;
}

void prefixPrint(BST T){
    if(T != NULL){
        printf("%d ", T->data)  ;
        prefixPrint(T->LC);
        prefixPrint(T->RC);
    }
}

void postfixPrint(BST T);
void infixPrint(BST T);