#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int value;
    struct stack *next;
};
struct stack *top = NULL;

void push_element();
void pop_element();
void display_stack();
void display_top();

void main()
{
    int choice;
    while (1)
    {
        printf("Enter 1 to Push element\n");
        printf("Enter 2 to Pop element\n");
        printf("Enter 3 to Display top element\n");
        printf("Enter 4 to Diaplay all elements\n");
        printf("Enter 0 Exit.\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push_element();
            break;

        case 2:
            pop_element();
            break;

        case 3:
            display_top();
            break;

        case 4:
            display_stack();
            break;

        case 0:
            exit(0);

        default:
            printf("wrong input!...Try again!");
        }
    }
}
void push_element()
{
    int num ;
    struct stack *tmp;
    tmp = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter value to be inserted:\n");
    scanf("%d", &num);

    tmp->value = num;
    tmp->next = top;
    top = tmp;
}
void pop_element()
{
    struct stack *tmp;
    if (&top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        tmp = top;
        printf("value to be popped is: %d\n", tmp->value);
        top = top->next;
        free(tmp);
    }
}
void display_top()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top of the stack is : %d\n", top->value);
    }
}
void display_stack()
{
    struct stack *tmp;
    tmp = top;
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        while (tmp != NULL)
        {
            printf("%d\n", tmp->value);
            tmp = tmp->next;
        }
    }
}
