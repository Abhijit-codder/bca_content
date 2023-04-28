#include<stdio.h>
#include<stdlib.h>
/*In main, declare a struct queue q, and initialize its instances. 
Declare some size of the array, let 100. Initialize both f and r with -1. 
And allocate memory in heap for arr using malloc.
 Don’t forget to include the header file <stdlib.h>*/
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
/*Creating isEmpty:

Create an integer function isEmpty, and pass into it the pointer to the struct queue q, as the only parameter. 
Inside the function, check if the r element of the q is equal to the f element of the q. Intuitively speaking,
 the difference between the values of f & r is the size of the queue. And if they both are equal, the size is 0. 
 Therefore, if they are equal, return 1, else return 0.*/
int isEmpty(struct queue *q)
{
    if(q->r==q->f)
    {
        return 1;
    }
    return 0;
}
/* Creating isFull:

Create an integer function isFull, and pass into it the pointer to the struct queue q as the only parameter.
 In the function, check if the r element of struct queue q is equal to the (size element)-1. 
If it is, then there is no space left in the queue to insert elements anymore, hence return 1, else 0.*/
int isFull(struct queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}
/*. Creating Enqueue:

Create a void function enqueue, pass the pointer to the struct queue q, and the value to insert as parameters.
First of all, check if the queue is full by calling the isFull function. If it returns 1, then print
the condition of the queue overflow and return.
 Else, increase the r value of q using the arrow operator, and insert the new value at the index r of the array arr.*/
void enqueue(struct queue *q,int val)
{
    if(isFull(q))
    {
        printf("This queue is Full\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
        printf("Enqued element %d\n",val);

    }
}
/*Creating Dequeue:

Create an integer function dequeue, and pass the pointer to the struct queue q, as the only parameter into it. 
In the function, first of all, check if the queue is already not empty by calling the isEmpty function. If it returns 1, 
then print the condition of the queue underflow and return. Else, increase the f value of q using the arrow operator, and
 store the value at the index f of the array in some integer variable a. 
Later, return a.*/
int dequeue(struct queue *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("This queue is empty\n");
    }
    else{
        q->f++;
        a=q->arr[q->f];

    }
    return a;
}
int main()
{
    struct queue q;
    q.size=10;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));

    //Enqueue few elements
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,1);
    //Dequeue the entered elements
    printf("Dequeuing element %d \n",dequeue(&q));
    printf("Dequeuing element %d \n",dequeue(&q));
    printf("Dequeuing element %d \n",dequeue(&q));
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);

    if(isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    if(isFull(&q))
    {
        printf("Queue is Full\n");
    }
    return 0;
}
