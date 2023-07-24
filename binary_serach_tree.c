#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * getNode(int data){
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int main(){
    struct Node *root = getNode(5);
    printf("root %d",root->data);

    return 0;
}