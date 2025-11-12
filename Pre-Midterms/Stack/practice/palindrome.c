#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 128

typedef struct node{
    char elem[MAX];
    int top;
}Stack;

void Push(Stack* S, char x);
void Pop(Stack* S);
char Top(Stack S);
void initStack(Stack* S);

bool isFull(Stack S);
bool isEmpty(Stack S);

bool isPalindrome(char palindrome[]);


int main(){
    char palindrome[MAX];
    printf("Enter string: ");
    scanf("%s", palindrome);

    printf("Palindrome? %s", (isPalindrome(palindrome)) ? "Yes!" : "No!");
}

void Push(Stack* S, char x){
    if(isFull(*S) != true){
        S->elem[++S->top] = x;
    }

}

void Pop(Stack* S){
    if(isEmpty(*S) != true){
        S->top--;
    }
}

char Top(Stack S){
    return (isEmpty(S) != true) ? S.elem[S.top] : '\0';
}

void initStack(Stack* S){
    S->top = -1;
}

bool isFull(Stack S){
    return (S.top == MAX - 1) ? true : false;
}
bool isEmpty(Stack S){
    return (S.top == -1) ? true : false;
}

bool isPalindrome(char palindrome[]){
    Stack S1;
    Stack S2;
    initStack(&S1);
    initStack(&S2);

    for(int i  = 0; palindrome[i] != '\0'; i++){ // push string into S1
        Push(&S1, palindrome[i]);
    }

    for(; isEmpty(S1) != true; Pop(&S1)){ // push S1 into S2, so S1 will be empty
        Push(&S2, Top(S1));
    }

    for(int i  = 0; palindrome[i] != '\0'; i++){ // push string back into S1abc
        Push(&S1, palindrome[i]);
    }

    for(; isEmpty(S1) != true && Top(S1) == Top(S2); Pop(&S1), Pop(&S2)){}; // now both ends of the string will start comparing to check if its palindrome

    return (S1.top == -1) ? true : false;
}
