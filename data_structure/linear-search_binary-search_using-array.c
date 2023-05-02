#include<stdio.h>
/*Linear Search:
1. We’ll start with coding the linear search. Create an integer function linearSearch. 
This function will receive the array, its size, and the element to be searched as its parameters.

2. Run a for loop from its 0 to the last index, checking the if condition at every index 
whether the element at that index equals the search element. If yes, return the index, else continue the search.

3. If the element could not be found until the last, return -1*/
int linearSearch(int arr[],int size,int element)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            return i;

        }
    }
    return -1;
}
/*Binary Search:
1. Create a function named binarySearch and pass the same three parameters as we did in linear search. 
Here, we will maintain three integer variables low, mid, and high. Low  stores are the beginning of the search space, 
and high stores the end. Mid stores the middle element of our search space, which is   mid = (low+high)/2.

2. Check whether the mid element equals the search element. If yes, return mid, else if the mid element is greater than 
the search element, 
then the search element must lie on the left side of the current space and high becomes mid-1, else if the mid element is 
less than the search element, then we’ll shift to the right side, and low becomes mid+1.

3. This way, we reduce our search space into half every time we repeat step 2. Now our new mid becomes (low+high)/2, and we repeat step 
2. And keep repeating until either we find the search element or the low becomes greater than the high.*/
int binarySearch(int arr[],int size,int element)
{
    int low,mid,high;
    low=0;
    high=size-1;
    //keep searching until low<=high
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==element)
        {
            return mid;
        }
        if(arr[mid]<element)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    //unsorted array for linear search
    //int arr[]={1000,233,34,4,51,6,744,8,9};
    //int size=sizeof(arr)/sizeof(int);

    //sorted array for binary search 
    int arr[]={1,22,33,44,55,66,77,88};
    int size=sizeof(arr)/sizeof(int);
    int element =44;
    int searchIndex=binarySearch(arr,size,element);
    printf("The element %d was found at index %d\n",element,searchIndex);
    return 0;

}
