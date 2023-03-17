#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linklisttransversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("element are=%d\n",ptr->data);
        ptr=ptr->next;
    }
}

//create function insertatfirst  
struct node * insertatfirst(struct node* head,int ptr)
{
    struct node *ptr; //assing pointer ptr in the struct node
    ptr=(struct node*)malloc(sizeof(struct node));//create memory for ptr in the heap
    ptr=ptr->data;//enter the data in the created node ptr
    ptr->next=head; //link ptr to head to maintain continuation
    return ptr; //return the value of ptr
}


int main()
{ 
    //declare pointing variable under node struct
    struct node *head;
    struct node *second;
    struct node *third;

    //allocating space for each node in the heap using malloc
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    //linking one node to another
    //linking head node to second 
    head->data=11;
    head->next=second;

    //linking second node to third
    second->data=22;
    second->next=third;

    //linking third node to null
    third->data=33;
    third->next=NULL;

    linklisttransversal(head);//calling function
    head= insertatfirst(head,44);//calling function
    linklisttransversal(head);
    return 0;
}






