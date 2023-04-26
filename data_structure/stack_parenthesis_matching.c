#include<stdio.h>
#include<stdlib.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr,char val)
{
    if(isFull(ptr))
    {
        printf("Stack is overflow!cannot push %d to the stack\n",val);

    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
        }

}

char pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack is underflow!cannot pop from the stack");

    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
/*Start by creating an integer function paranthesisMatch, and pass the reference to a character array(expression) exp in the function as a parameter. 
This function will return 1 if the parentheses are balanced and zero otherwise. 
Inside that function, create a stack pointer sp. 
And initialize the size member to some big number, 
let it be 100. Initialize the top to -1, and assign the 
array pointer a memory location in the heap. You have the freedom to choose any data structure you want to implement this stack. We have learned stacks using both arrays and linked lists very efficiently.*/
int parenthesisMatch(char *expr)
{
    struct stack*sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size* sizeof(char));

    for(int i=0;expr[i]!='\0';i++)
    {
        if(expr[i]=='(')
        {
            push(sp,'(');

        }
        else if(expr[i]==')'){
            if(isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
     if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    } 
}
/*So, it would be better if you just copy everything of stack implementation because it will more or less remain the same for that part. I’ll use the array one.

4. Change the datatype of the array from integer to char. Accordingly, change everything from integer to char. And arr to exp.

5. Run a loop starting from the beginning of the expression till it reaches EOE.

6. If the current character of the expression is an opening parenthesis,’(' , push it into the stack using the push operation.

7. Else if the current character is a closing parenthesis ‘)’, see if the stack is not empty, using isEmpty, and if it is, return 0 there itself, else pop the topmost character using pop operation. 

8. In the end, if the stack becomes empty, return 1, else 0.

9. In the main, define a random character array expression and just passing this expression to parenthesisMatch would do our job.*/
 
 int main()
{
    char *expr="((8)4+6*76(())";
    if(parenthesisMatch(expr))
    {
        printf("the parenthesis is matching");
    }
    else{
        printf("The parenthesis NOT matching");
    }
    return 0;
}

