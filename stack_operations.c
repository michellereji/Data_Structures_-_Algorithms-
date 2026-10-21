#include <stdio.h>
#define MAX 5 

int stack[MAX],top=-1;

int main()
{
    int ch,value;
    while(1)
    {
        printf("\n 1. PUSH \n 2. POP \n 3. PEEK \n 4. DISPLAY \n 5. EXIT \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                if(top==MAX-1)
                {
                    printf("Stack is full\n");
                }
                else
                {
                    printf("Enter the value to be pushed: ");
                    scanf("%d",&value);
                    top++;
                    stack[top]=value;
                    printf("%d pushed to stack\n",value);
                }
                break;
            case 2:
                if(top == -1)
                    printf("Stack Underflow\n");
                else
                    printf("Popped element: %d\n", stack[top--]);
                break;
            case 3:
                if(top == -1)
                    printf("Stack is empty\n");
                else
                    printf("Top element: %d\n", stack[top]);
                break;
            case 4:
                if(top == -1)
                    printf("Stack is empty\n");
                else {
                    printf("Stack elements:\n");
                    for(int i = top; i >= 0; i--)
                        printf("%d ", stack[i]);
                    printf("\n");
                }
                break;
                
            case 5:
                return 0;
                
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
    
}
