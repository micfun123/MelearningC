#include <stdio.h>

struct node{
    int data;   
    struct node *left;
    struct node *right;

};

struct node *head = NULL;

void addnode(int num){
    if (head)
    {
        head ->data = num;
        return;
    }
    while(head != NULL){
        if(num < head -> data){
            head = head ->left;
        }else
        {
            head = head ->right;
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
