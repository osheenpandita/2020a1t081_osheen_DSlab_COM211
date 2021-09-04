//Implement a Circular Linked List and develop functions to perform insertion, deletion and linear search operations
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
int Lsearch(int data)
{
    int position = -1;
    int i = 1;
    struct node *traverse = head;
    if (head != NULL)
    {
        do
        {
            if (traverse->data == data)
            {
                position = i;
                break;
            }
            i++;
            traverse = traverse->next;
        } while (traverse != head);
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
        traverse->next = traverse;
        head = traverse;
    }
    else
    {

        while (traverse->next != head)
        {
            traverse = traverse->next;
        }
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        traverse->next = new_node;
        new_node->data = element;
        new_node->next = head;
    }
}
int delete (int element)
{
    int removed = INT_MIN;
    if (head != NULL)
    {
        int pos = Lsearch(element);
        if (pos != -1)
        {
            if (pos == 1)
            {
                if (head->next == head)
                {
                    removed = head->data;
                    free(head);
                    head = NULL;
                }
                else
                {
                    struct node *traverse = head;
                    removed = head->data;
                    //Now all this code does is update last node pointing to head i.e make last node point to head->next cuz we shifting the head
                    do
                    {
                        traverse = traverse->next;
                    } while (traverse->next != head);
                    //*Now traverse is on last node
                    traverse->next = head->next;
                    traverse = head;
                    head = head->next;
                    free(traverse);
                }
            }
            else
            {

                struct node *prev = NULL, *next = head;
                while (pos > 1)
                {
                    prev = next;
                    next = next->next;
                    pos--;
                }
                removed = next->data;
                prev->next = next->next;
                free(next);
            }
        }
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
        // **TWO WAYS OF PRINTING**
        // *1ST WAY
        do
        {
            printf("|_%d_|->", traverse->data);
            traverse = traverse->next;
        } while (traverse != head);
        printf("[First Node]");
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
                printf("Invalid Input!\n");
                return 0;
            }
            insert(element);
            break;
        case 2:;
            int el;
            printf("Delete What?\n");
            if (scanf("%d", &el) == false)
            {
                printf("Invalid Input!\n");
                return 0;
            }
            int x = delete (el);
            if (x != INT_MIN)
            {
                printf("%d Removed.", x);
            }
            else
            {
                printf("No element\n");
            }
            break;

        case 3:;
            int e;
            printf("Find What?\n");
            if (scanf("%d", &e) == false)
            {
                printf("Invalid Input\n");
                return 0;
            }
            int temp = Lsearch(e);
            if (temp != -1)
            {
                printf("Found at Pos:%d\n", temp);
            }
            else
            {
                printf("Not Found.");
            }
            break;

        case 4:
            print();
            break;
        default:
            printf("------------EXITED------------\n");
            break;
        }
    } while (c < 5 && c >= 1);

    return 0;
}