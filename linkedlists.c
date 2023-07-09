#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;



int printList(struct node *n)
{
    //print node from start
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}

int addNode(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return 0;
}



void main(){

    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);

    printList(head);

}