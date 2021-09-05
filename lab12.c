// Program to implement a Priority Queue using Linked List and develop functions to perform enqueue and dequeue operations.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node
{
    int data;          // variable for the data to be inserted into the node of the list
    int priority;      // variable for the corresponding priority of the element inserted
    struct Node *next; // next is pointer of the last node
};
// setting head as global variable
struct Node *head = NULL;
//creating function to enqueue elements into priority queue based on corresponding priorities
void enQueue(int element, int elementPriority)
{
    struct Node *node;
    struct Node *temp;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = element;
    node->priority = elementPriority;
    /* if the head of list has lesser
    priority than new node. So insert new
    node before head node and change head node. */
    if (head == NULL || head->priority > elementPriority)
    {
        // Insert New Node before head
        node->next = head;
        head = node;
    }
    else
    {
        temp = head;
        // Traverse the list and find a position to insert new node
        while (temp->next != NULL && temp->next->priority <= elementPriority)
        {
            temp = temp->next;
        }
        // Either at the ends of the list or at required position
        node->next = temp->next;
        temp->next = node;
    }
}
// creating a function to remove the element with the highest priority form the list
int deQueue()
{
    int removed;
    struct Node *temp;
    if (head == NULL)
    {
        printf("\nQueue is Empty\n");
        return INT_MIN;
    }
    else
    {
        temp = head;
        removed = temp->data;
        head = head->next; //pointing the head towards the next of to be deleted node i.e 2nd node
        free(temp);        //freeing the memory from the front
    }
    return removed;
}
// creating a function to print the details of the  priority queue
void print()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("\nData = %d\nCorresponding Priority = %d\n", temp->data, temp->priority);
            temp = temp->next;
        }
    }
}
// creating a function to print the highest priority element from the list
void peek()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("\nList is empty\n");
    }
    else
        printf("\nData with highest priority : %d\nCorresponding Priority : %d\n", temp->data, temp->priority);
}
int main()
{
    int operation, element, priority;

    do
    {
        printf("\nEnter the operation\n");
        printf("1.Enqueue into Priority Queue\n");
        printf("2.Dequeue Highest Priority Element\n");
        printf("3.Display the Priority Queue\n");
        printf("4.Display the Highest Priority Element\n");
        printf("5.Exit\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            printf("\nEnter the element to insert\n");
            scanf("%d", &element);
            printf("\nEnter its corresponding priority\n");
            scanf("%d", &priority);
            enQueue(element, priority);
            break;
        case 2:;
            int popped = deQueue();
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
            peek();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nWrong choice\n");
            break;
        }
    } while (1);
    return 0;
}