#include <stdio.h>
#include <stdlib.h>
struct Node //creating a structure
{
    int data;
    struct Node *next; 
};
void linkedlisttraversal(struct Node *ptr) //creating  a function 
{
    while(ptr!=NULL) 
    {
        printf("element%d\n", ptr->data); //ptr=pointer
        ptr= ptr->next;
    }
}

//CASE-1 DELETING A NODE FROM THE BEGINNING
/*DESCRIPTION-Create a struct Node* function deleteFirst which will return the pointer to the new head after deleting the current head.
We’ll pass the current head pointer in the function.
Create a new struct Node* pointer ptr, and make it point to the current head.
Assign head to the next member of the list, by head = head->next, because this is going to be the new head of the linked list.
Free the pointer ptr. And return the head.*/
struct Node * deletefirst(struct Node * head)
{
    struct Node* ptr=head;
    head= head->next;
    free(ptr);
    return head;

}
//CASE-2 DELETING A NODE IN BETWEEN
/*DESCRIPTION-Create a struct Node* function deleteAtIndex which will return the pointer to the head.
In the function, we'll pass the current head pointer and the index where the node is to be deleted.
Create a new struct Node* pointer p pointing to head.
Create a new struct Node* pointer q pointing to head->next, and run a loop until this pointer reaches the index, from where we are deleting the node.
Assign q->next to the next member of the p structure using p-> next = q->next.
Free the pointer q, because it has zero connections with the list now.
Return head*/
struct Node * deletebetween(struct Node * head,int index)
{
    struct Node *p=head;
    struct Node * q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;

    }
    p->next = q->next;
    free(q);
    return head;

}

//CASE-3 DELETING A NODE AT THE LAST
/*DESCRIPTION-Deleting the last node is quite similar to deleting from any other index. The difference holds in the limit of the while loop. Here we run a loop until the pointer reaches the end and points to NULL.
Assign NULL to the next member of the p structure using p-> next = NULL.
Break the connection between q and NULL by freeing the ptr q.
Return head*/
struct Node * deletelast(struct Node * head)
{
    struct Node*p=head;
    struct Node  *q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
    
}
int main()
{ 
    //creating head second and third node under the structure node
    struct Node *head;
    struct Node *second;
    struct Node *third;
    
    //allocating space for head second third nodes in the heap or memory
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));

    //link first and second node
    head->data=7;
    head->next = second;

    //link secondnode and third
    second->data=12;
    second->next=third;

    //terminate the list at the second node
    third->data=44;
    third->next=NULL;

    printf("linked list before deletion\n");
    //calling the functon linkedlistTraversal and pointing it to the head of the node
    linkedlisttraversal(head);
   head=deletefirst(head);
   // head=deletebetween(head,2);
    head=deletelast(head);
    printf("after deletion\n");
    linkedlisttraversal(head);
    return 0;






}


