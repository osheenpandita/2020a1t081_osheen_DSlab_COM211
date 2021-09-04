//Implement a Doubly Linked List and develop functions to perform insertion, deletion and linear search operations
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
    struct node *prev;
} *head = NULL;
int linear_search(int data)
{
    struct node *traverse = head;
    int position = -1;
    int i = 1;
    while (traverse != NULL)
    {
        if (traverse->data == data)
        {
            position = i;
            break;
        }
        i++;
        traverse = traverse->next;
    }
    return position;
}
void insert(int element)
{
    struct node *traverse = head;
    // *IF head node is not present
    if (traverse == NULL)
    {
        traverse = (struct node *)malloc(sizeof(struct node));
        traverse->data = element;
        traverse->next = NULL;
        traverse->prev = NULL;
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
        new_node->prev = traverse;
        new_node->data = element;
        new_node->next = NULL;
    }
}
int delete (int element)
{
    int removed = INT_MIN;
    int pos = linear_search(element);
    if (pos != -1)
    {
        // *Deleting head node(special case cus we need to shift head)
        if (pos == 1)
        {
            struct node *t = head;
            removed = head->data;
            if (t->next != NULL)
            {

                head = head->next;
                head->prev = NULL;
            }
            else
            {
                head = NULL;
            }

            free(t);
        }
        else
        {

            struct node *pre_node = NULL, *next = head;
            while (pos > 1)
            {
                pre_node = next;
                next = next->next;
                pos--;
            }
            //** (Now next is pointing to node that need to be removed)
            // **Case for last node
            removed = next->data;
            if (next->next == NULL)
            {
                pre_node->next = NULL;
            }
            // **Delete in-between node
            else
            {

                pre_node->next = next->next;
                next->next->prev = pre_node;
            }
            free(next);
        }
    }
    return removed;
}

void print()
{
    int choice;
    printf("Press '1' for Start->End\nPress '2' for End->Start\n");
    scanf("%d", &choice);
    // **Print start to end
    if (choice == 1)
    {
        struct node *trav = head;
        if (trav == NULL)
        {
            printf("Empty.");
        }
        else
        {
            while (trav != NULL)
            {
                printf("|%d|->", trav->data);
                trav = trav->next;
            }
            printf("[NULL]");
        }
    }
    // **Print end to start
    else if (choice == 2)
    {
        struct node *end = head;
        if (end == NULL)
        {
            printf("Empty.");
        }
        else
        {
            // Moving end to last
            while (end->next != NULL)
            {
                end = end->next;
            }

            while (end != NULL)
            {
                printf("|%d|->", end->data);
                end = end->prev;
            }
            printf("[NULL]");
        }
    }
    printf("\n");
}
int main()
{

    int c;
    do
    {
        printf("\nMENU\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Linear Search\n");
        printf("4.Display\n");
        printf("5.Press any other key to Exit\n");
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
            if (element && 1)
            {
                insert(element);
            }
            else
            {
                printf("no\n");
            }

            break;
        case 2:;
            int el;
            printf("Delete What?\n");
            if (scanf("%d", &el) == false)
            {
                printf("Invalid Input!!\n");
                return 0;
            }
            int x = delete (el);
            if (x != INT_MIN)
            {
                printf("%d Removed.", x);
            }
            else
            {
                printf("No element");
            }
            break;

        case 3:;
            int e;
            printf("Find What?\n");
            if (scanf("%d", &e) == false)
            {
                printf("Invalid Input!!\n");
                return 0;
            }
            int temp = linear_search(e);
            if (temp != -1)
            {
                printf("\nFound at Pos:%d\n", temp);
            }
            else
            {
                printf("\nNot Found.\n");
            }
            break;

        case 4:
            print();
            break;
        default:
            printf("------------END------------\n");
            break;
        }
    } while (c < 5 && c >= 1);

    return 0;
}