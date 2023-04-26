#include<stdio.h>
#include<stdlib.h>
 struct node
 {
    int data;
    struct node * next;

 };

 void linkedlisttraversal(struct node*ptr)
 {
    while(ptr!=NULL)
    {
        printf("Elements %d\n",ptr->data);
        ptr=ptr->next;
    }
 }
 //isEmpty():
/*Create an integer function isEmpty, and 
pass the pointer to the top node as the parameter. 
If this top node equals NULL, return 1, else 0.*/
 int isEmpty(struct node *top)
 {
    if(top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
 }
 /*isFull():
Create an integer function isFull, and pass the pointer to the top node as the parameter.
Create a new struct Node* pointer p, and assign it a new memory location in the heap.
If this newly created node p is NULL, return 1, else 0.*/
 int isFull(struct node *top)
 {
    struct node*p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL)
    {
        return 1;

    }
    else{
        return 0;
    }
 }
 /*Push():
Create a struct Node* function push which will return the pointer to the new top node.
We’ll pass the current top pointer and the data to push in the stack, in the function.
Check if the stack is already not full, if full, return the condition stack overflow.
Create a new struct Node* pointer n, and assign it a new memory location in the heap.
Assign top to the next member of the n structure using n-> next = top, and the given data to its data member.
Return this pointer n, since this is our new top node*/
 struct node * push(struct node * top,int x)
 {
    if(isFull(top))
    {
        printf("Stack is overflow\n");
    }
    else{
        struct node * n=(struct node*)malloc(sizeof(struct node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
 }
 /*
 Pop() :
Create an integer function pop which will return the element we remove from the top.
We’ll pass the reference of the current top pointer in the function. We are passing the reference this time, because we are not returning the updated top from the function.
Check if the stack is already not empty, if empty, return the condition stack underflow.
Create a new struct Node* pointer n, and make it point to the current top. Store the data of this node in an integer variable x.
Assign top to the next member of the list, by top = top->next, because this is going to be our new top.
Free the pointer n. And return x.*/
 int pop(struct node **top)
 {
    if(isEmpty(*top))
    {
        printf("Stack is underflow\n");

    }
    else{
        struct node *n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;

    }
 }
 int main()
 {
    struct node * top=NULL;
    top=push(top,78);
    top=push(top,77);
    linkedlisttraversal(top);
    /*Let’s pop one element out from the stack. And then again traverse through it.*/
    int element =pop(&top);
    printf("Popped element is %d\n",element);
    linkedlisttraversal(top);
    return 0;

 }
