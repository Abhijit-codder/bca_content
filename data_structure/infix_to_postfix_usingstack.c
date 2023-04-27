#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct  stack{
    int size;
    int top;
    char *arr;
};
int stackTop(struct stack*sp)
{
    return sp->arr[sp->top];
}
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack*ptr,char val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow!Cannot push %d into stack\n",val);
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
        printf("Stack Underflow!Cannoot pop from Stack\n");
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int precedence(char ch)
{
    if(ch=='*'||ch=='/')
    {
        return 3;
    }
    else if (ch=='+'||ch=='-')
    {
        return 2;
    }
    else 
    {
        return 0;
    }
}
int isOperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
    {
        return 1;

    }
    else{
        return 0;
    }
}
/*. First of all, create a character pointer function infixToPostfix since the function has to return a character array. And now pass into this function the given expression, which is also a character pointer.

2. Define a struct stack pointer variable sp. And give it the required memory in the heap. Create the instance. It’s safe to assume that a struct stack element and all its basic operations, push, pop, etc., have already been defined. You better copy everything from the stack tutorial.

3. Create a character array/pointer postfix, and assign it sufficient memory to hold all the characters of the infix expression in the heap.

4. Create two counters, one to traverse through the infix and another to traverse and insert in the postfix.
5. Run a while loop until we reach the EOE of the infix. And inside that loop, check if the current index holds an operator, and if it’s not, add that character into the postfix and increment both the counters by 1. And if it does hold an operator,
 call another function that would check if the precedence of the stackTop is 
less than the precedence of the current operator. If yes, push it inside the stack. Else, pop the stackTop, and add it back into the postfix. Increment j by 1.*/
char * infixTopostfix(char *infix)
{
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size *sizeof(char));
    char * postfix =(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;//track infix traversal
    int j=0;//track postfix addition
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(sp)))
            {
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;

            }
        }
    }
    while(isEmpty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;

}
int main()
{
    char *infix="x-y/z-k*d+g";
    printf("postfix is %s",infixTopostfix(infix));
    return 0;
}
