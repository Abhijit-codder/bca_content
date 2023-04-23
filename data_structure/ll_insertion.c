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

//CASE-1 insert a node in the beginning
/*description- Insertion at the beginning:
Create a struct Node* function insertAtFirst which will return the pointer to the new head.
We’ll pass the current head pointer and the data to insert at the beginning, in the function.
Create a new struct Node* pointer ptr, and assign it a new memory location in the heap.
Assign head to the next member of the ptr structure using ptr-> next = head, and the given data to its data member.
Return this pointer ptr*/
struct Node * insertatfirst(struct Node *head,int data)
{
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

//CASE-2 Insert a node in between
/*DESCRIPTION-Create a struct Node* function insertAtIndex which will return the pointer to the head.
We’ll pass the current head pointer and the data to insert and the index where it will get inserted, in the function.
Create a new struct Node* pointer ptr, and assign it a new memory location in the heap.
Create a new struct Node* pointer pointing to head, and run a loop until this pointer reaches the index, where we are inserting a new node.
Assign p->next to the next member of the ptr structure using ptr-> next = p->next, and the given data to its data member.
Break the connection between p and p->next by assigning p->next the new pointer. That is, p->next = ptr.
Return head*/
struct Node* insertatindex(struct Node *head,int data,int index)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node*p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

//CASE-3 Insert a node at the end
/*DESCRIPTION-Inserting at the end is very similar to inserting at any index. The difference holds in the limit of the while loop. Here we run a loop until the pointer reaches the end and points to NULL.
Assign NULL to the next member of the new ptr structure using ptr-> next = NULL, and the given data to its data member.
Break the connection between p and NULL by assigning p->next the new pointer. That is, p->next = ptr.
Return head.*/
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
 
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
//MAIN PROGRAM
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

     printf("Linked list before insertion\n");
    //calling the functon linkedlistTraversal and pointing it to the head of the node
    linkedlisttraversal(head);
    head=insertatfirst(head,33);
    head=insertatindex(head,77,1);
    head=insertAtEnd(head,11);
    printf("\nLinked list after insertion\n");
    linkedlisttraversal(head);
    return 0;






}


