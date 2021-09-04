//Implement a Stack using Linked List and develop functions to perform push and pop operations
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;
void push(int element)
{
    struct node *traverse = head;
    // *IF head node is not present
    if (traverse == NULL)
    {
        traverse = (struct node *)malloc(sizeof(struct node));
        traverse->data = element;
        traverse->next = NULL;
        head = traverse;
    }
    else
    {

        while (traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        // **Now traverse is pointing to last node
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        traverse->next = new_node;
        new_node->data = element;
        new_node->next = NULL;
    }
}
int pop()
{

    int removed = INT_MIN;
    struct node *trav = head;
    if (trav == NULL)
    {
        return removed;
    }
    else if (trav->next == NULL)
    {
        removed = head->data;
        free(head);
        head = NULL;
    }
    else
    {
        struct node *prev = NULL;
        while (trav->next != NULL)
        {
            prev = trav;
            trav = trav->next;
        }
        // *trav is pointing to last elemt and prev is pointing to second last element
        removed = trav->data;
        prev->next = NULL;
        free(trav);
    }

    return removed;
}

void print()
{

    struct node *traverse = head;
    if (traverse == NULL)
    {
        printf("Empty.\n");
    }
    else
    {

        printf("Now Printing:\n");

        while (traverse != NULL)
        {

            if (traverse->next != NULL)
            {
                printf("|_%d_|->", traverse->data);
            }
            else
            {
                printf("|_%d_|->NULL", traverse->data);
            }

            traverse = traverse->next;
        }
        printf("\n");
    }
}
int main()
{

    int c;
    do
    {
        printf("\nMENU\n");
        printf("1.Insert\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Press any other key to Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:;
            int element;
            printf("Enter Element:");
            if (scanf("%d", &element) == false)
            {
                printf("Invalid Input!!\n");
                return 0;
            }
            push(element);
            break;
        case 2:;
            int x = pop();
            if (x != INT_MIN)
            {
                printf("%d Popped.", x);
            }
            else
            {
                printf("Stack is Empty!");
            }
            break;

        case 3:
            print();
            break;
        default:
            printf("------------EXITED------------\n");
            break;
        }
    } while (c < 4 && c >= 1);

    return 0;
}