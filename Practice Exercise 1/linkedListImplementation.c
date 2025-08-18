#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node *link;
}*charList; 

void insertLast(charList* ref, char x);
void printList(charList ref);

bool findElem(charList ref, char x);
void deleteElem(charList* ref, char x);

int main(){
    charList L = NULL;

    printf("%d\n", findElem(L, 'u')); // test findElem if list is empty

    //populate L
    insertLast(&L,'t');
    insertLast(&L,'o');
    insertLast(&L,'x');
    insertLast(&L,'i');
    insertLast(&L,'c');

    printList(L);

    //test for findElem if list is not empty
    printf("%d\n", findElem(L, 'c')); // test if elem exists
    printf("%d\n", findElem(L, 'x'));
    printf("%d\n", findElem(L, 't')); 

    printf("%d\n", findElem(L, 'a')); // test if elem doesnt exists
    printf("%d\n", findElem(L, 'b'));
    printf("%d\n", findElem(L, 'g')); 

    //test for deleteElem if list is not empty

    deleteElem(&L, 't'); // test for first position
    deleteElem(&L, 'x'); // test for mid position
    deleteElem(&L, 'c'); // test for last position
    deleteElem(&L, 'b'); // test for elem that doesnt exist in the linked list
    printList(L);
}

void insertLast(charList *ref, char elem) {
    // Create new node
    charList temp = (charList) malloc(sizeof(struct node));
    temp->elem = elem;
    temp->link = NULL;

    if (*ref == NULL) {
        // Empty list, new node becomes head
        *ref = temp;
    } else {
        // Traverse to last node
        charList trav = *ref;
        while (trav->link != NULL) {
            trav = trav->link;
        }
        trav->link = temp;
    }
}

void printList(charList ref){
    for(charList trav = ref; trav !=NULL; trav = trav->link){
        printf("%c",trav->elem);
    }
    printf("\n");
}

bool findElem(charList ref, char x){
    charList trav;
    for(trav=ref;trav != NULL && trav->elem != x; trav = trav->link){} // check if elem exists, it exits early if it exists
    return (trav != NULL) ? true : false; // if trav == NULL, then elem doesnt exist therefore false
}

void deleteElem(charList* ref, char x){
    charList* trav, temp;
    for(trav = ref; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->link){} //find elem
    if(*trav != NULL){ // if elem exists, execute code
        temp = *trav; // declare temp, this will be the node that will be deleted
        *trav = temp->link; // change the address of trav to the next link
        free(temp); // delete temp
    }
}