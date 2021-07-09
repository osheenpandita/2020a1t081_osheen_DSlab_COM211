//Implementing a Stack using Arrays in C and developing functions to perform push and pop operations
#include <stdio.h>
#include <stdlib.h> // for dynamic memory allocation and exit()
#include <conio.h>  // for getch()
// Structure representing stack
struct Stack
{
    int *arr; // stores the elements in the stack
    int top;  // index of the top element
    int maxSize; // Maximum size of the stack
};
// For creating the stack and allocating the memory
struct Stack *createStack(int maxSize)
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->maxSize = maxSize;
    sp->top = -1; // initialization to -1 shows that the stack is empty
    sp->arr = (int *)malloc(sp->maxSize * sizeof(int));
    return sp;
}
// isFull() for checking if the stack is full
int isFull(struct Stack *sp)
{
    if (sp->top == sp->maxSize - 1)
    { // when top is equal to the last index, the stack is full
        return 1;
    }
    else
        return 0;
}
// isEmpty() for checking if the stack is empty
int isEmpty(struct Stack *sp)
{
    if (sp->top == -1) // when top is equal to -1, the stack is empty
    {
        return 1;
    }
    else
        return 0;
}
// push() for pushing an element in the stack
void push(struct Stack *sp, int element)
{
    if (isFull(sp))
    {
        printf("Stack Overflow !!! \n"); // calling the isFull() function to check if the stack is full
    }
    else
    {
        sp->arr[++sp->top] = element; // incrementing top by 1
        printf("The element pushed to the stack is %d\n", element);
    }
}
// pop() for deleting/removing the top most element from the stack
int pop(struct Stack *sp)
{
    if (isEmpty(sp))
    {
        return 0; // calling the isEmpty() function to check if the stack is empty
    }
    else
        return sp->arr[sp->top--];
}
void displayElements(struct Stack *sp) // for displaying the elements present in the stack
{
    if (isEmpty(sp))
    {
        printf("Empty Stack!!!\n");
    }
    else
    {
        printf("Elements present in the stack are:\n");
        int tmp;
        tmp = sp->top;
        while (tmp != -1)
        {
            printf("%d \n", sp->arr[tmp]);
            --tmp;
        }
    }
}
int main()
{
    int choice, element, popped, maxSize;
    printf("Enter the size of the stack : \n");
    scanf("%d", &maxSize);
    struct Stack *sp = createStack(maxSize); // calling the createStack() function
    do
    {
        printf("\t IMPLEMENTATIONS \n");
        printf("Press 1 to push an element in the stack\n");
        printf("Press 2 to pop an element from the stack\n");
        printf("Press 3 to display elements of the stack\n");
        printf("Press 4 to exit the stack\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice); // input choice from the user
        switch (choice)
        {
        case 1:
            printf("\n \t Pushing element in stack \n");
            printf("Enter the element you want to push in the stack : \n");
            scanf("%d", &element);
            push(sp, element); // calling the push function
            break;
        case 2:
            printf("Pop the element from stack \n");
            popped = pop(sp); // calling the pop function
            if (sp->top == -1 && popped == 0)
            {
                // s->top is -1 which means the stack is empty
                printf("Stack Underflow!!! \n");
            }
            else
                printf("The popped element is %d \n", popped);
            break;
        case 3:
            displayElements(sp); // calling the display function
            break;
        case 4:
            exit(0);
        default:
            printf("WRONG INPUT:( TRY AGAIN!! \n");
            break;
        }
        printf("Press ENTER if you wish to continue!!\n");
        getch();
    } while (1);
    return 0;
}
