#include<stdio.h>
#include<stdlib.h>
 struct circularqueue{
    int size;
    int f;
    int r;
    int *arr;
 };
 /*If you remember, the condition for isEmpty remains the same for both queues and circular queues*/
 int isEmpty(struct circularqueue *q)
 {
    if(q->r==q->f)
    {
       return 1;
    }
    return 0;
 }
 /*Earlier, isFull checked if our rear has reached the limit of the array. And if it did, we returned the overflow statement.
  But now, the queue isn’t full until technically. So, just see if the index next to the rear becomes front or not. Use circular increment (modulus) 
  to pursue any increment in a circular queue. 

So, check if (r element of q) +1 is equal to the (f element of q). 
If it is, then there is no space left in the queue to insert anymore elements, 
hence return 1, else 0.*/
 int isFull(struct circularqueue *q)
 {
    if((q->r+1)%q->size==q->f)
    {
     return 1;   
    }
    return 0;
    
 }
 /*In the function enqueue, first of all, check if the queue is full by calling the isFull function. 
 If it returns 1, then print the condition of the queue overflow and return. Else, 
 increase the r value of q circularly using the arrow operator and modulus,
  and insert the new value at the increased index r of the array arr.*/
 void enqueue(struct circularqueue *q,int val)
 {
    if(isFull(q))
    {
        printf("Queue is Full");

    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("Enqued element %d\n",val);
    }
 }
 /*Earlier when we dequeued in a queue, we would simply increase the value of f by 1. 
 We would now increase but circularly, and that would be it.

In the function dequeue, first, check whether the circular queue is already not empty by calling isEmpty. 
If it returns 1, then print the condition of the queue underflow and return. Else, increase the f value of q
 using the arrow operator circularly, and store the value at the index f of the array in some integer variable a. 
Later, return a.*/
 int dequeue(struct circularqueue*q)
 {
    int a=-1;
    if (isEmpty(q))
    {
        printf("Queue is Empty");


    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
 }
 int main()
 {
    /*In main, we had declared a struct circularQueue q, and initialized its instances. 
    Here is a subtle change, we don’t initialize circular queues’ f and r with -1, rather 0.
     Since -1 is unreachable in circular incrementation.*/
    struct circularqueue q;
    q.size=5;
    q.f=q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));

    //Enqueue few elements
    enqueue(&q,12);
    enqueue(&q,33);
    enqueue(&q,45);
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    //enqueue(&q,21);
    //enqueue(&q,13);
    //enqueue(&q,40);
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
