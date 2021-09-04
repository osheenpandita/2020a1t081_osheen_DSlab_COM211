//Implement a Singly Linked List and develop functions to perform insertion, deletion and linear search operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *next; //next is pointer of the last node
} *head = NULL; //head points to the first node
int linear_search(int data)
{
    struct Node *node = head;
    int index = -1;
    int count = 0;
    while (node != NULL)
    {
        if (node->data == data)
        {
            index = count;
            break;
        }
        count++;
        node = node->next;
    }
    return index;
}
void insertion(int element)
{
    struct Node *node = head;
    // IF head node is not present
    if (node == NULL)
    {
        node = (struct Node *)malloc(sizeof(struct Node)); //Memory for new node
        node->data = element; 
        node->next = NULL; //Change next of new node to point to head
        head = node; //Change head to point to recently created node
    }
    else
    {

        while (node->next != NULL)
        {
            node = node->next;
        }
        // Now node is pointing to last node
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        node->next = new_node;
        new_node->data = element;
        new_node->next = NULL;
    }
}
int deletion(int element)
{
	int removed;
    if (head  == NULL)
        printf("\nList is empty\n");
    else {
	struct Node *temp = head;
            removed = head->data;
            head = head->next;
            free(temp);
	}
	return removed;
}
void print()
{

    struct Node *node = head;
    if (node == NULL)
    {
        printf("\nList is Empty.\n");
    }
    else
    {

        printf("\nPrinting the list:\n");


        while (node != NULL)
        {

            if (node->next != NULL)
            {
                printf("%d->", node->data);
            }
            else
            {
                printf("%d->NULL", node->data);
            }

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
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Linear Search\n");
        printf("4.Display\n");
	printf("5.Exit\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            printf("\nEnter the element you want to insert:\n");
            scanf("%d", &element);
            insertion(element);
            break;
        case 2:;
            int remove_element;
            int remove = deletion (remove_element);
            if (remove != INT_MIN)
            {
                printf("%d Removed.", remove);
            }
            else
            {
                printf("No element Like that found");
            }
            break;
        case 3:;
            int search_element;
            printf("\nEnter the element you want to search\n");
            scanf("%d", &search_element);
            int search = linear_search(search_element);
            if (search != -1)
            {
                printf("\nElement found at index : %d\n", search);
            }
            else{
                printf("\nElement not found\n");
            }
            break;
        case 4:
            print();
            break;
	case 5:
            exit(0);
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    } while (1);
    return 0;
}