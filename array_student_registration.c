#include <stdio.h>
int main()
{ 
    int a[100],i,n,ch,pos,value;
    printf("enter the number of students: ");
    scanf("%d",&n);
    printf("enter registration numbers of students: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(1)
    {
        printf("\n 1. DISPLAY \n 2. INSERT \n 3. DELETE \n 4. EXIT \n");
        printf("enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("student registration numbers are: ");
                for(i=0;i<n;i++)
                {
                    printf("%d ",a[i]);     
                }
                printf("\n");
                break;
            case 2:
                if(n>=100)
                {
                    printf("array is full\n");
                }
                else
                {
                    printf("enter the position to insert: ");
                    scanf("%d",&pos);
                    if(pos<1 || pos>n+1)
                    {
                        printf("invalid position\n");
                    }
                    else
                    {
                        printf("enter the registration number to be inserted: ");
                        scanf("%d",&value);
                        for(i=n-1;i>=pos-1;i--)
                        {
                            a[i+1]=a[i];
                        }
                        a[pos-1]=value;
                        n++;
                        printf("registration number inserted successfully\n");
                    }
                }
                break;
            case 3:
                if(n==0)
                {
                    printf("array is empty\n");
                }
                else
                {
                    printf("enter the position to delete: ");
                    scanf("%d",&pos);
                    if(pos<1 || pos>n)
                    {
                        printf("invalid position\n");
                    }
                    else
                    {
                        for(i=pos-1;i<n-1;i++)
                        {
                            a[i]=a[i+1];
                        }
                        n--;
                        printf("registration number deleted successfully\n");
                    }
                }
                break;
            case 4:
                printf("exiting the program\n");
                return 0;
            default:    
                printf("invalid choice\n");
        }
    }
    
    return 0;

}