#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;//to store the size of the stack
    int top;//to store the index of the topmost element
    int *arr;//to hold the address of the array
};
int isEmpty(struct stack *ptr)//checking whether the stack is empty or not
{

    if(ptr->top==-1)//empty stack top value is always -1
    {
        return 1;
    }
    else
    {
        return 0;

    }
}
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)//full stack top value will the total size of the array -1
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct stack *s;
    s->size=80;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));

    //pushing an element manually
    s->arr[0]=7;
    s->top++;

    if(isEmpty(s))
    {
        printf("the stack is empty");
    }
    else 
    {
        printf("stack is not empty");
    }
    return 0;
}
