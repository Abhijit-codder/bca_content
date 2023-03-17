#include<stdio.h>
#include<stdlib.h>
struct node 
    {
        int data;
        struct node *next;

    };
    void linklisttransversal(struct node *ptr)
    {
        while (ptr!= NULL)
        {
            printf("elements are=%d\n",ptr->data);
            ptr=ptr->next;
        }
    }

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node * fifth;

    //allocating size of each node in the heap

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));
    fifth=(struct node*)malloc(sizeof(struct node));

    //link head node to second
    head->data=77;
    head->next=second;

    //link second node to third
    second->data=55;
    second->next=third;

    //link third node to fourth
    third->data=33;
    third->next=fourth;

    // Link fourth to fifth nodes
    fourth->data = 22;
    fourth->next = fifth;

    //link fifth to null node
    fifth->data=11;
    fifth->next= NULL;

    linklisttransversal(head);
    return 0;
}



