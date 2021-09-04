//Implement a Queue using Array and develop functions to perform enqueue and dequeue operations
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
}

int isEmpty(struct queue *q)
{
    if (q->front > q->rear || q->rear == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enQueue(struct queue *q, int val)
{

    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        if (q->rear == -1)
        {
            q->front = 0;
        }

        q->rear++;
        q->arr[q->rear] = val;
        printf("Operation successfull the Enqeued element is: %d\n", val);
    }
}

int deQueue(struct queue *q)
{
    int deQueuedelement = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
        return INT_MIN;
    }
    else
    {

        deQueuedelement = q->arr[q->front];
        q->front++;
    }
    return deQueuedelement;
}
void display(struct queue *q)
{
    int i;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }

    else
    {

        for (i = q->front; i <= q->rear; i++)
            printf("queue is %d \n", q->arr[i]);
    }
}

int main()
{
    struct queue q;
    int size, disp;
    printf("Enter Maximum size of the Queue:");
    scanf("%d", &size);
    create(&q, size);
    int choice;
    do
    {
        printf("MENU:\n");
        printf("1.EnQueue\n");
        printf("2.DeQueue\n");
        printf("3.Print QueueA\n");
        printf("4.Exit\n");
        printf("Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:;
            int x;
            printf("Enter element:");
            scanf("%d", &x);

            enQueue(&q, x);
            break;
        case 2:;
            int temp = deQueue(&q);

            printf("deQueued operation is successfull :%d is deQueued\n", temp);

            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Choice:(\n");
            break;
        }
    } while (choice < 4 && choice > 0);

    return 0;
}