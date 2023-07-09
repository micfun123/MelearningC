#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *one = NULL;
struct node *two = NULL;


int printList(struct node *n)
{
    while (n != NULL)
    {
        printf(" %d ", n->data);
        n = n->next;
    }
    return 0;
}

void main(){

    one = malloc(sizeof(struct node));
    one->data = 1;
    two = malloc(sizeof(struct node));
    two->data = 2;
    one -> next = two;
    two -> next = NULL;
    

    printList(one); 


}