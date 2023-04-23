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

    //calling the functon linkedlistTraversal and pointing it to the head of the node
    linkedlisttraversal(head);
    return 0;






}



