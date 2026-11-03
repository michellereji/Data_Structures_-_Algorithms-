#include <stdio.h>

int main()
{
    int a[50],i,n,pos,item;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);  
    }
    printf("Enter the position of the element to be deleted: ");
    scanf("%d",&pos);
    item=a[pos-1];
    printf("Element to be deleted: %d\n",item);

    for(i=pos-1;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    n--;
    printf("Array after deletion: ");   
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}


