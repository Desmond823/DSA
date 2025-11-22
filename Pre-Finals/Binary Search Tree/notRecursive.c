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
    initBST(&root); //initialize root

    for(int i = 0; i<7; i++){ //store setA into the BST
        insert(&root, setA[i]);
    }

    printf("prefix: ");
    prefixPrint(root);
    printf("\n");

    printf("Insert 11: ");
    insert(&root, 11);
    prefixPrint(root);
    printf("\n");

    printf("Remove 10: ");
    delete(&root, 10);
    prefixPrint(root);
    printf("\n");

    printf("Min: %d\n", min(root));
    printf("Max: %d\n", max(root));

    printf("Is 15 a member? %s\n", member(root, 15) == 1 ? "Yes" : "No"); // check for existing element
    printf("Is 20 a member? %s\n", member(root, 20) == 1 ? "Yes" : "No"); // check for nonexisting element

    // printf("postfix: ");
    // postfixPrint(root);
    // printf("\n");

    // printf("infix: ");
    // infixPrint(root);
    // printf("\n");

}

void initBST(BST* T){
    *T = NULL;
}

void insert(BST* T, int data){
    BST* trav = T;

    while(*trav != NULL && (*trav)->data != data){ // travel to null and check if unique
        if(data < (*trav)->data) trav = &(*trav)->LC;// if data is smaller
        else if(data > (*trav)->data) trav = &(*trav)->RC; // if data is larger
    }

    if(*trav == NULL){
        BST temp = (BST)malloc(sizeof(struct node)); // make the new node
        temp->data = data;
        temp->RC = NULL;
        temp->LC = NULL;
        *trav = temp; // assign child node the parent node
    }
}

void delete(BST* T, int data){
    if(*T == NULL){
        printf("this tree empty bru\n");
    }
    else{
        BST* trav = T;
        BST temp;

        while(*trav != NULL && (*trav)->data != data){ // travel to null and check if unique
            if(data < (*trav)->data) trav = &(*trav)->LC;// if data is smaller
            else if(data > (*trav)->data) trav = &(*trav)->RC; // if data is larger
        }
        if(*trav != NULL){ // if data has been found
            temp = *trav;
            if(temp->LC != NULL && temp->RC == NULL) *trav = temp->LC; // if node has left child only
            else if(temp->RC != NULL && temp->LC == NULL) *trav = temp->RC; // if node has right child only
            else if(temp->RC == NULL && temp->LC == NULL) *trav = NULL;
            else{ // if node has 2 child nodes
                // search for immediate successor (option 1)
                trav = &(*trav)->RC;
                while((*trav)->LC != NULL){
                    trav = &(*trav)->LC;
                }

                // search for preceeding succesor (option 2)
                /*
                trav = &(*trav)->LC;
                while((*trav)->RC != NULL){
                    *trav = &(*trav)->RC;
                }
                (*trav)->data = temp->data;
                */

            temp->data = (*trav)->data; // replace node val to preceeding/immediate succesor
            *trav = NULL; // unlink the preceeding/immediate successor
            temp = *trav; // assign temp to the preceeding/immediate successor node
            }
            free(temp); // delete
        }
    }
}

int member(BST T, int data){
    while(T != NULL && T->data != data){ // travel to null and check if unique
        if(data < T->data) T = T->LC;// if data is smaller
        else if(data > T->data) T = T->RC; // if data is larger
    }
    return (T == NULL) ? 0 : 1;
}

int min(BST T){
    if(T == NULL) printf("this tree empty cuh\n");
    else{
        while(T->LC != NULL){ // travel to the left most node
            T = T->LC;
        }
        return T->data;
    }
}

int max(BST T){
    while(T->RC != NULL){ // travel to the right most node
        T = T->RC;
    }
    return T->data;
}

void prefixPrint(BST T){
    if(T != NULL){
        printf("%d ", T->data);
        prefixPrint(T->LC);
        prefixPrint(T->RC);
    }
}

void postfixPrint(BST T){
    if(T != NULL){
        prefixPrint(T->LC);
        prefixPrint(T->RC);
        printf("%d ", T->data);
    }
}
void infixPrint(BST T){
    if(T != NULL){
        prefixPrint(T->LC);
        printf("%d ", T->data);
        prefixPrint(T->RC);
    }
}