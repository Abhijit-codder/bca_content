#include<stdio.h>
int main()
{
int i,j,rows,column,a[100][100];
printf("enter the number of rows=");
scanf("%d",&rows);
printf("enter the no. of column =");
scanf("%d",&column);

for(i=0;i<rows;i++)
{
    for(j=0;j<column;j++)
    {
        printf("enter the element=a[%d][%d]",i,j);
        scanf("%d",&a[i][j]);

    }
    
}
printf("printing the matrix:\n");
{
    for(i=0;i<rows;i++)
    
    
    {
        printf("\n");
        for(j=0;j<column;j++)
    {
        printf("%d\t",a[i][j]);
    }
        }
    }
    return 0;
}
