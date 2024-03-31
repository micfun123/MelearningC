#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *previous;
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
    printf("\n");
}

int nextNode(struct node *n)
{
    //print node from start
    if (n->next != NULL)
    {
        printf("%d ", n->next->data);
    }
    else
    {
        printf("NULL\n");
    }
}

int previousNode(struct node *n)
{
    //print node from start
    if (n->previous != NULL)
    {
        printf("%d ", n->previous->data);
    }
    else
    {
        printf("NULL\n");
    }
}

int addNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

int getNode(int index)
{
    struct node *current = head;
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
        {
            return (current->data);
        }
        count++;
        current = current->next;
    }
    return 0;
}

int findNode(int looking_for)
{
    struct node *current = head;
    int count = 0;
    while (current != NULL)
    {
        if(current -> data == looking_for){
            return count;
        }
        count++;
        current = current->next;

    }
    
}

void main(){
    addNode(5);
    addNode(2);
    addNode(5);
    addNode(6);
    addNode(55);
    addNode(77);
    printf("%d\n",findNode(55));
    printf("%d\n",findNode(77));
    printf("%d\n",getNode(4));
    printf("%d\n",getNode(5));
}