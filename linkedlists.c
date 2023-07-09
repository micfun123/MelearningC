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
    printf("\n");
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

int editNode(int index, int data)
{
    struct node *current = head;
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
        {
            current->data = data;
        }
        count++;
        current = current->next;
    }
}

void main(){

    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    addNode(6);
    addNode(7);
    

    printList(head);

    
    printf("The second node is %d\n", getNode(2));
    editNode(2, 10);
    printf("The second node is %d\n", getNode(2));

    printList(head);

}