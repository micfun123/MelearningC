#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;   
    struct node *left;
    struct node *right;
};

struct node *head = NULL;

void addnode(int num, struct node **root) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL)
    {
        *root = newNode;
        return;
    }

    struct node  *current = *root;
    struct node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (num < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (num < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void findnode(int num, struct node *head){
    struct node *current = head;
    while (current != NULL){
        if (current->data == num){
            printf("%d found.\n", num);
            return;
        }
        if (current->data > num){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    printf("%d does not exist\n", num);
}

void printtree(struct node *root){
    if (root == NULL)
        return;
    printtree(root->left);
    printf("%d ", root->data);
    printtree(root->right);
}


//pass in root node and string of new tree
void dupetrue(struct node *root, struct node *new){
    
}

int main(){
    addnode(5,&head);
    addnode(15,&head);
    addnode(20,&head);
    addnode(53,&head);
    addnode(30,&head);
    
    // Print the entire tree (in-order traversal)
    printtree(head);
    printf("\n");
    findnode(5,head);
    findnode(53,head);
    
}
