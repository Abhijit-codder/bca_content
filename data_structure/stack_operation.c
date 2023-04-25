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

void push(struct stack * ptr,int val)
{
    if(isFull(ptr))
    {
        printf("stack is overflow!cannot push %d to the stack",val);//when there is no space in the stack to push any further elements
    }
    else{
        ptr->top++;//increase the value of top by 1
        ptr->arr[ptr->top]=val;//insert the entered val to the top of the stack to be pushed
    }
}

int pop(struct stack *ptr  )
{
    if(isEmpty(ptr))
    {
        printf("stack underflow!cannot pop from the stack\n");//when stack has no elemnts in it to pop
        return -1;
    }
    else
    {
        int val=ptr->arr[ptr->top];//value of val equal to the top element of stack
        ptr->top--;//bring the top one value down
        return val;//the the stored value of val to be pop
    }
}
int main()
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));
    printf("stack has been created successfully\n");
    
    printf("before pushing ,full %d\n",isFull(s));
    printf("before poping,empty-%d\n",isEmpty(s));
    push(s, 1);   
    push(s, 23);
    push(s, 99);
    push(s, 75);
    push(s, 3);
    push(s, 64);
    push(s, 57);
    push(s, 46);
    push(s, 89);
    push(s, 6); // ---> Pushed 10 values 
    printf("After pushing, Full: %d\n", isFull(s));
    printf("After pushing, Empty: %d\n", isEmpty(s));
    printf("Popped %d from the stack\n", pop(s)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(s)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(s)); // --> Last in first out!
    

    
    return 0;
}
