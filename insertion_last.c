// insertion at the end of an array
#include <stdio.h>
int main()
{
    int a[50],i,n,num;
    printf("enter the number of elements in the array: ");  
    scanf("%d",&n);
    printf("enter the elements in the array: ");
    for(i=0;i<n;i++)    
    {
        scanf("%d",&a[i]);
    }
    if(n>=50)
    {
        printf("array is full");
    }
    else
    {
        printf("enter the number to be inserted: ");
        scanf("%d",&num);
        a[n]=num;
        n++;
        printf("the elements in the array after insertion are: ");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    }
    return 0;
}   
