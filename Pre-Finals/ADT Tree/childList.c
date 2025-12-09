#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
    int data;
    struct node* next;
}*nodeType;

typedef struct{
    nodeType children[MAX];
    int root;
}Tree;

void initTree(Tree* T);
void insertChild(Tree* T,int parent,int data);
void preorder(Tree T,int root);

int main(){
    Tree T;
    initTree(&T);

    insertChild(&T, 5, 0);
    insertChild(&T, 5, 6);
    insertChild(&T, 5, 2);
    insertChild(&T, 3, 6);
    insertChild(&T, 6, 1);
    insertChild(&T, 1, 4);
    insertChild(&T, 1, 7);
    insertChild(&T, 2, 8);

    T.root=5;

    preorder(T, T.root);

}

void initTree(Tree* T){
    for(int i = 0; i<MAX; i++){
        T->children[i] = NULL;
    }
    T->root = -1;
}

void insertChild(Tree* T,int parent, int data){ //insert last
    nodeType* trav = &T->children[parent];
    for(; *trav != NULL; trav = &(*trav)->next){}// go to the end
    
    nodeType temp = (nodeType)malloc(sizeof(struct node));
    if(temp!=NULL){
        temp->data = data;
        temp->next = NULL;
        *trav = temp;
    }
    if(T->root == -1) T->root = parent;
}

void preorder(Tree T,int root){
    if(T.root == -1) return;
    else{
        printf("%d ", root);
        for(nodeType trav = T.children[root]; trav != NULL; trav = trav->next){
            preorder(T,trav->data);
        }
    }
}
