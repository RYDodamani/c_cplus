#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX],top = -1;
int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
int isFull(){
    if(top==MAX-1){
        return 1;
    }
    return 0;
}
void push(int key){
    if(!isFull()){
        stack[++top] = key;
    }
    else{
        printf("Stack overflow\n");
    }
}
void pop(){
    if(!isEmpty()){
        printf("%d popped from stack\n",stack[top--]);
        return;
    }
    printf("Stack underflow\n");
}

void printStack(){
    if(isEmpty()){
        return;
    }
    for(int i = 0; i<=top; i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){
    push(10);
    push(23);
    push(32);
    printStack();
    return 0;
}