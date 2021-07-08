// Write a program to check if a given expression is correctly parenthesized using stacks
#include <stdio.h>
#include <stdlib.h>   // for dyanimc memory allocation
#include <string.h>   // for checking the length of the expression using strlen()
// structure representing a stack
struct Stack
{
    char *arr;      // stores the elements in the stack
    int top;        // index of the top element
    int maxSize;    //maximum size of the stack
};
// isFull() is used for checking if the stack is full or not
int isFull(struct Stack *sp)
{
    if (sp->top == sp->maxSize - 1)    // when top is equal to the last index, the stack is full
    {
        return 1;
    }
    else
        return 0;
}
// isEmpty() is used for checking if the stack is empty or not
int isEmpty(struct Stack *sp)
{
    if (sp->top == -1)       // when top is equal to -1, the stack is empty
    {
        return 1;        
    }
    else
        return 0;
}
// Push function
void push(struct Stack *sp, char ch)
{
    if (isFull(sp))
    {
       printf("Stack Overflow!!\n");
    }
    sp->arr[++sp->top] = ch;
}
// Pop function
int pop(struct Stack *sp)
{
    if (isEmpty(sp))
    {
        return 0;
    }
    sp->top--;
    return 1;
}
int main()
{
    int expSize, i, ret;
    char exp[30];
    struct Stack sp;
    sp.top = -1;                    // initializing top to -1.
    
    printf("Enter the expression : \n");
    gets(exp);                     // input the expression using gets()
    expSize = strlen(exp);         // using strlen() to find the length of the expression.
    sp.maxSize = expSize;          // assigning the size of the expression as the maximum size of the stack.
    sp.arr = (char *)malloc(sp.maxSize * sizeof(char));
    for (i = 0; i < expSize; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(&sp, exp[i]);   // if the character is the starting bracket,then push into the stack
        }
        // check if the character is the closing bracket
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            // if the character is a closing bracket, check if the top of the stack is the pair of the character
            if ((sp.arr[sp.top] == '(' && exp[i] == ')') || (sp.arr[sp.top] == '{' && exp[i] == '}') || (sp.arr[sp.top] == '[' && exp[i] == ']'))  //Thank you Aditya Kotwal for this part
            {
                ret = pop(&sp);
            }
            else
            {
                printf("This expression is NOT BALANCED!!! \n");
                return 0;
            }    
        }
    }
    if (isEmpty(&sp))
    {
        // if the stack is empty, the expression is balanced.
        printf(" This expression is BALANCED!! \n");
    }
    else
    {
        // if the stack is not empty, the expression is not balanced.
        printf("This expression is NOT BALANCED!! \n");
    }
    return 0;
}
