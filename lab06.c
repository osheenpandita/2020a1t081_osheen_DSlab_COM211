#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Queue
{
    int *arr;
    int size;	 //size is allocated at the time of creation of the queue
    int front;			//index of the front item, starts from 0
    int rear;			//index of the rear item, starts from 0
};
//creating a function to count total number of items in a queue....
int CreateQueue(struct Queue *q){
	if (q->rear == -1 && q->front==-1)
	{
		return 0;
	} else if (q->rear >= q->front){
		return (q->rear - q->front)+1;
	} else{
		return (((q->size - 1) - q->front) + 1) + (q->rear + 1);
	}
}
//creating a function to check whether the queue is empty or not
int isEmpty(struct Queue *q){
    if(q->rear == q->front){
        return 1;
    }
    return 0;
}
//creating a function to check whether the queue is full or not
int isFull(struct Queue *q){
    if (CreateQueue(q) == q->size){
        return 1;
    }
    return 0;
}
//creating a function to enqueue the elements into the queue
int enQueue(struct Queue *q, int value){
	if (isFull(q) == 0){
		if (CreateQueue(q) == 0)
		{
			// queue->front = -1 as the queue is empty
			// we have to make it 0 as now we will insert an item
			q->front = 0;
		}
		// incrementing the rear circularly
	    q->rear = (q->rear +1)%(q->size);
	    // inserting new element at the rear
	    q->arr[q->rear] = value;
	    printf("Enqueued element: %d\n", value);
	    return 1;
	}
	else{
		printf("\nQueue is full\n");
		return 0;
	}
}
//creating a function to dequeue the elements from the queue
int deQueue(struct Queue *q){
	if (CreateQueue(q) != 0){
		// copy the front item in a variable (temp)
		int temp = q->arr[q->front];
		if (q->front == q->rear)
		{
			/* the front should never cross the rear
			it means that the queue is going to become empty after this deQueue operation*/
			q->front = -1;
			q->rear	 = -1;
		} else{
			q->front = (q->front + 1)%(q->size); // operate in circular way
		}
		// return the variable (temp)
		return temp;
	}
	else{
		// return the extreme value of integer if queue is empty
		return INT_MIN;
	}
}
//creating a function to display the details of queue
void printQueueDetails(struct Queue *q){
	printf("\nsize=%d  front=%d  rear=%d \n", q->size, q->front, q->rear);
}
//creating a function to display all the elements of queue
void DisplayQueue(struct Queue *q){
	int count;
	count = q->front;
	if (CreateQueue(q) != 0)
	{
		do
	    {
	        printf("Arr[%d]= %d ", count, q->arr[count]);
	        count = (count + 1) % (q->size);
	    } while (count != (q->rear + 1) % q->size);
		printf("\n");
	}
}
int main()
{
	int item, value, sizeOfQueue, operation;
	struct Queue q;
	printf("\nEnter the size of the queue\n");
	scanf("%d", &sizeOfQueue);
	/* keeping the maximum capacity of queue as 
	the entered size of queue by the user */
	q.size = sizeOfQueue; 
	q.front=-1;// the queue is empty
	q.rear=-1;// the queue is empty
	// dynamically allocating the memory of queue
	q.arr = (int *)malloc(q.size*sizeof(int));
	do
    {
    	printf("\nChoose an operation\n");
      	printf("1.Enqueue into the Queue\n");
      	printf("2.Dequeue from the Queue\n");
      	printf("3.Display the details of Queue\n");
      	printf("4.Display the Queue\n");
      	printf("5.Exit\n");
      	scanf("%d", &operation);
      	switch (operation){
      		case 1:
            	printf("\nEnter the value to be enqueued\n");
        		scanf("%d", &item);
        		enQueue(&q, item);			// calling enQueue function
        		break;
         	case 2:
            	value = deQueue(&q);		// calling deQueue function
            	if (value == INT_MIN)
            	{
                	printf("\nQueue is empty\n");
            	} else{
                	printf("\n%d is removed", value);
            	}
            	break;
         	case 3:
            	printf("\nDetails of the Queue :\n");
            	printQueueDetails(&q);		// calling printQueueDetails function
            	printf("\nTotal number of elements in queue = %d \n", CreateQueue(&q));
            	break;
         	case 4:
            	printf("\nDisplaying the entire queue :\n");
            	DisplayQueue(&q);			// calling printQueue function
            	printf("\nTotal number of elements in queue = %d \n", CreateQueue(&q));
            	break;
         	case 5:
            	printf("\nPress Enter to exit\n");
            	exit(0);
            	break;
            default:
        		printf("\nWrong operation\n");
        		break;
        }
    }
    while (1);
    return 0;
}