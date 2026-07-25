#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node *left, *right;
};

struct Node* createNode(char name[]) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->name, name);
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, char name[]) {
    if(root==NULL)
        return createNode(name);

    if(strcmp(name, root->name)<0)
        root->left=insert(root->left,name);
    else if(strcmp(name, root->name)>0)
        root->right=insert(root->right,name);

    return root;
}

void inorder(struct Node* root) {
    if(root) {
        inorder(root->left);
        printf("%s\n",root->name);
        inorder(root->right);
    }
}

int search(struct Node* root,char name[]) {
    if(root==NULL)
        return 0;

    int cmp=strcmp(name,root->name);

    if(cmp==0)
        return 1;

    if(cmp<0)
        return search(root->left,name);

    return search(root->right,name);
}

int main() {
    struct Node* root=NULL;

    root=insert(root,"Rahul");
    root=insert(root,"Amit");
    root=insert(root,"Pank