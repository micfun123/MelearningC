#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;   
    struct node *left;
    struct node *right;
};

struct node *head = NULL;

void addnode(int num){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->left = NULL;
    newNode->right = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct node *current = head;
    while (current != NULL){
        if (num < current->data){
            if (current->left == NULL){
                current->left = newNode;
                break;
            }
            current = current->left;
        }
        else if (num > current->data){
            if (current->right == NULL){
                current->right = newNode;
                break;
            }
            current = current->right;
        }
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

int main(){
    addnode(5);
    addnode(3);
    addnode(8);
    addnode(2);
    addnode(4);
    addnode(7);
    addnode(9);
    
    // Print the entire tree (in-order traversal)
    printtree(head);
    printf("\n");
    
    findnode(9, head);
    findnode(2, head);
    findnode(5, head);
    findnode(30, head);
    findnode(4, head);
}
