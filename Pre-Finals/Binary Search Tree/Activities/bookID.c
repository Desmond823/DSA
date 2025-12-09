#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct{
    int bookID;
    String bookName;
}Book;

typedef struct node{
    Book book;
    struct node* left;
    struct node* right;
}*BST;

void insertNode(BST* root, Book newBook);
int searchNode(BST root, int search);

void prefix(BST root);
void infix(BST root);
void postfix(BST root);

int main(){
    BST T = NULL;
    Book thisBook = {1,"CRAZY BOOK"};
    Book thatBook = {2,"YUCKY BOOK"};
    Book theirBook = {3,"SLEEPY BOOK"};

    insertNode(&T, thatBook);
    insertNode(&T, thisBook);
    insertNode(&T, theirBook);

    printf("%d", searchNode(T, 1));
    printf("%d", searchNode(T, 5));
    printf("%d", searchNode(T, 4));
}

void insertNode(BST* root, Book newBook){
    BST* trav = root;
    while(*trav != NULL && newBook.bookID != (*trav)->book.bookID){
        if(newBook.bookID < (*trav)->book.bookID) trav = &(*trav)->left;
        else trav = &(*trav)->right;
    }

    if(*trav == NULL){
        BST temp = (BST)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->book = newBook;
            temp->left = NULL;
            temp->right = NULL;
            *trav = temp;
        }
    }
}

int searchNode(BST root, int search){
    if(root == NULL) return 0;
    if(search == root->book.bookID) return 1;
    else if(search < root->book.bookID) return searchNode(root->left, search);
    else if(search > root->book.bookID) return searchNode(root->right, search);
}

void prefix(BST root){
    if(root != NULL){
        printf("(%d, %s)", root->book.bookID, root->book.bookName);
        prefix(root->left);
        prefix(root->right);
    }
}
void infix(BST root){
    if(root != NULL){
        infix(root->left);
        printf("(%d, %s)", root->book.bookID, root->book.bookName);
        infix(root->right);
    }
}
void postfix(BST root){
    if(root != NULL){
        postfix(root->left);
        postfix(root->right);
        printf("(%d, %s)", root->book.bookID, root->book.bookName);
    }
}


