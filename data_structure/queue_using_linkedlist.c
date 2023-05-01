#include<stdio.h>
#include<stdlib.h>

struct node* f=NULL;
struct node * r=NULL;
struct node
{
    int data;
    struct node *next; 
};
 void linkedlistTraversal(struct node * ptr)
 
 {
    printf("Printing the elements of this linked list\n");
    while(ptr!=NULL)
    {
        printf("Elements =%d\n");
        ptr=ptr->next;
    }

 }
 /*We learned in the last lecture that to enqueue, we only use the rear pointer and add a new node at the end of the list. 
 So, create a void function enqueue, and the value to enqueue is the only parameter since we have declared the pointers f and r globally. 
 In the function, create a new struct Node pointer n, and assign its memory in heap dynamically using malloc. Don’t forget to include the header file<stdlib.h>.
  Then check if the queue is full or, in other words, if there is no space in the heap. And that can be done by checking if the new pointer n equals NULL. 
  If it does, then print the condition of the queue overflow and return. Else, insert the val in the data member of n, and make this node point to NULL. If you recall,
   we discussed a special case, where we were inserting in the list for the first time, when both f and r equals NULL. For this case, make both f and r equal to n, and for all the other cases, 
   just make the r point the new node n. Ultimately make r equal to n since n becomes our new rear end.
  And that would be all*/
 void enqueue(int val)
 {
    struct node *n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL)
    {
        printf("Queue is Full");
    }
    else 
    {
        n->data=val;
        n->next=NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else{
            r->next =n;
            r=n;

        }
    }
 }
 /*As we discussed in the last lecture, Dequeue needs you to just delete the head node, which is the f node here. 
 So, create an integer function dequeue. And we have no parameters to pass. Create a struct Node pointer ptr to 
 hold the node we will delete. Make ptr equal to f. In the function, check if the queue is already not empty by 
 checking if our front f is NULL or not. If it is NULL, then print the condition of the queue underflow and return.
  Else, make f equal to the next node to f. Store the data of ptr in an integer variable val. We can now free the pointer ptr. 
 And return val, which is the data of the node we deleted.*/
 int dequeue()
 {
    int val=-1;
    struct node *ptr=f;
    if(f==NULL)
    {
        printf("Queue is Empty\n");

    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);

    
    }
    return val;

 }
 int main()
 {
    linkedlistTraversal(f);
    //printf("Dequeue element %d\n",dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeue element %d\n",dequeue());
    printf("Dequeue element %d\n",dequeue());
    printf("Dequeue element %d\n",dequeue());
    printf("Dequeue element %d\n",dequeue());
    linkedlistTraversal(f);
    return 0;

 }
