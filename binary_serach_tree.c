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

// 1. if root is null than return new node
// 2. if key is less than root node than insert the key in left sub tree
// 3. else insert the key in right sub tree
// 4. new node is always inserted as a leaf node
struct Node * insertNode(struct Node *root,int data){
    if(root==NULL){
        return getNode(data);
    }

    if(data>=root->data){
        root->right = insertNode(root->right,data);
    }
    else{
        root->left = insertNode(root->left,data);
    }
    return root;
}

// inorder traversal gives increasing order of keys
void inorderTraversal(struct Node *root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d ",root->data);
        inorderTraversal(root->right);
    }
}

struct Node * deleteNode(struct Node * root, int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
        root->left = deleteNode(root->left,data);
    }
    else if(data>root->data){
        root->right = deleteNode(root->right,data);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            root = NULL;
        }
        else if(root->right==NULL){
            root = root->left;
            free(root->left);
        }
        else if(root->left==NULL){
            root = root->right;
            free(root->right);
        }
        else{
            
        }
    }

}

struct Node * findNode(struct Node *root,int data){
    if(root==NULL){
        return root;
    }
    if(root->data == data){
        return root;
    }
    else if(data > root->data){
        return findNode(root->right,data);
    }
    else{
        return findNode(root->left, data);
    }
}
// struct Node * findMin(struct Node *root,int data){
//     while()
// }
struct Node * inorderSuccessor(struct Node *root, int data){
    struct Node *node = findNode(root,data);
    if(node->right != NULL){
        struct Node *temp = node->right;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp;
    }

}
struct Node* findInorderSuccessor(struct Node* root, int key) {
    struct Node* successor = NULL;
    while (root) {
        if (root->data > key) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

struct Node * insuccess(struct Node * root, int data){
    struct Node * successor = NULL;
    while (root!=NULL)
    {
        if(root->data <= data){
            root = root->right;
        }
        else if(root->data > data){
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

int main(){
    int n;
    struct Node *temp = NULL,*find;
    
    struct Node *root = getNode(5);
    insertNode(root,10);
    insertNode(root,25);
    insertNode(root,12);
    insertNode(root,67);
    insertNode(root,20);
    insertNode(root,34);

    inorderTraversal(root);

    // find = findNode(root,12);
    // printf("Found %d",find->data);
    printf("Enter key: ");
    scanf("%d",&n);
    // find = findInorderSuccessor(root,n);
    // printf("Found %d",find->data);

    find = insuccess(root,n);
    if (find)
    {
        printf("Found %d",find->data);
    }
    else{
        printf("Not Found");
    }
    
    return 0;
}