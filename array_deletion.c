// to delete an element from the beginning 

// for(i=0;i<n-1;i++)
// {
//     a[i]=a[i+1];
// }
// n--;


// to delete an element from the end

// n--;


// to delete an element from the end
#include <stdio.h>
int main()
{
    int a[50],i,n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);  
    }
    
    n--;
    
    printf("Array after deletion: ");   
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

