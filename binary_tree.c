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
    newNode -> data = num;
    newNode -> left = NULL;
    newNode -> right = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct node *current = head;
    while(current != NULL){
        if(num < current -> data){
            if ( current -> left == NULL) 
            {
                current -> left = newNode;
                break;
            }
            current = current -> left;
        }
        else if(num > current -> data){
            if ( current -> right == NULL) 
            {
                current -> right = newNode;
                break;
            }
            current = current -> right;
                   
        }
    }
}

void printtree(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> right;
    }
    printf("\n");
    temp = head -> left;
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> right;
    }
    printf("\n");

}

int main(){
    addnode(5);
    addnode(3);
    addnode(8);
    addnode(2);
    addnode(4);
    addnode(7);
    addnode(9);
    printtree();
}
