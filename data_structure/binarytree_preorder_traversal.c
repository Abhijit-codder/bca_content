#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;


};
struct node *createNode(int data)
{
    struct node *n;//creating a node pointer
    n=(struct node *)malloc(sizeof(struct node));//allocating memeory in the heap
    n->data=data;//setting the data
    n->left=NULL;//setting the left and right children to Null
    n->right=NULL;
    return n;//finally returning the created node
}  
/*Creating the preOrder function:

3. Create a void function preOrder and pass the pointer to the root node of the tree you want to traverse as the only parameter. 
Inside the function, check if the pointer is not NULL, otherwise we wouldn't do anything. So, if it is not NULL, print the data
 element of the root struct node by using the arrow operator.

4. After you finish visiting the root node, simply call the same function recursively on the left and the right subtrees and you're done.
 Applying recursion does your job in its own subtle ways. It considers the left subtree as an individual tree and applies preorder on it, 
 and the same goes for the right subtree.*/ 
void preOreder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preOreder(root->left);
        preOreder(root->right);


    }
}
/*. First of all, we wouldn't start from scratch creating the struct Node and the createNode function and everything. 
So just copy the whole thing we did in our previous programming lecture and paste them here. This would save us a lot of time.

2. Create all the five nodes, using the createNode function, and link them using the arrow operator, and altering their left and 
right pointer elements. This creates our tree. The next thing would be to create the preOrder function.*/
int main()
{
    //constructing the root node -using function (recomended)
    struct node*p=createNode(4);
    struct node *p1=createNode(1);
    struct node *p2=createNode(6);
    struct node *p3=createNode(5);
    struct node *p4=createNode(2);
    //finally the tree looks like this
    /* 4
      / \    
      1  6
      /\
      5 2
    
    
    */

   //linking the root node with left and right children
   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
   //Now simply call the preOrder function passing the pointer to the root node as its parameter and see if it actually visits each node.
   preOreder(p);
   return 0;
}
