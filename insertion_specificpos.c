# include <stdio.h>
int main()
{
    int a[50],i,n,pos,num;
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
        printf("enter the position where the number is to be inserted: ");
        scanf("%d",&pos);
        if(pos<0 || pos>n+1)
        {
            printf("invalid position");
        }
        else
        {
            for(i=n-1;i>=pos-1;i--)
            {
                a[i+1]=a[i];

            }
            a[pos-1]=num;
            n++;
            printf("the elements in the array after insertion are: ");
            for(i=0;i<n;i++)
            {
                printf("%d ",a[i]);
            }
        }
        
    }
    return 0;
}

