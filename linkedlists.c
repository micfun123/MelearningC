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

    int exit = 1;
    while (exit != 0)
    {
        printf("\n");
        printf("1. Add Node\n");
        printf("2. Get Node\n");
        printf("3. Edit Node\n");
        printf("4. Print List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            int data;
            scanf("%d", &data);
            addNode(data);
            break;
        case 2:
            printf("Enter index: ");
            int index;
            scanf("%d", &index);
            printf("Node at index %d is %d\n", index, getNode(index));
            break;
        case 3:
            printf("Enter index: ");
            int index1;
            scanf("%d", &index1);
            printf("Enter data: ");
            int data1;
            scanf("%d", &data1);
            editNode(index1, data1);
            break;
        case 4:
            printList(head);
            break;
        case 0:
            exit = 0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        printf("\n");
        
    }
    

}