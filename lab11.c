//Program to implement a Queue using Linked List and develop functions to perform enqueue and dequeue operations.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *next;
};
// setting front and rear as two global variables
struct Node *front = NULL;
struct Node *rear = NULL;
//creating a function to enqueue a new node in the rear of list
void enQueue(int value)
{
    //creating memory for a new node dynamically
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value; // putting the value into temp or new node
    temp->next = NULL;  // Change next of new node to point to NULL
    /* if the list is empty create first node and
	 front and rear both will point to first node */
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp; // pointing rear to the temp
    rear = temp;       // now temp becomes the rear
}
//creating a function to dequeue from the front of the list
int deQueue(int value)
{
    int removed;
    struct Node *temp = front;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    else
    {
        removed = front->data; //moving the data value of first node into the removed variable
        front = front->next;   //pointing the head towards the next of to be deleted node i.e 2nd node
    }
    free(temp); //freeing the memory from the front
    return removed;
}
//creating a function to display all the nodes data from the list
void print()
{
    struct Node *node = front;
    if (node == NULL)
    {
        printf("\nQueue is Empty.\n");
    }
    else
    {
        printf("\nPrinting the list:\n");
        //loop will run until the node is not equal to NULL and will print all the data values of list
        while (node != NULL)
        {
            printf("%d->", node->data);
            node = node->next;
        }
        printf("\n");
    }
}
int main()
{
    int element, operation;

    do
    {
        printf("\nEnter the operation\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            printf("\nEnter the element you want to insert:\n");
            scanf("%d", &element);
            enQueue(element);
            printf("\nElement inserted successfully\n");
            break;
        case 2:;
            int popped = deQueue(element);
            if (popped == INT_MIN)
            {
                printf("%d", INT_MIN);
            }
            else
            {
                printf("\n%d Removed.", popped);
                printf("\n\nElement removed successfully\n");
            }
            printf("\n");
            break;
        case 3:
            print();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    } while (1);
    return 0;
}