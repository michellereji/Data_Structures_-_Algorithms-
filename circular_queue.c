#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

int main()
{
    int ch, value;
    
    while(1) {
        printf("\n1. Enqueue (Add Booking)\n2. Dequeue (Process Booking)\n3. Display Pending Bookings\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: // Add a booking request (Enqueue)
                if((rear + 1) % MAX == front) {
                    printf("Queue Overflow\n");
                } else {
                    printf("Enter booking number: ");
                    scanf("%d", &value);
                    if(front == -1) {
                        front = rear = 0;
                    } 
                    else {
                        rear = (rear + 1) % MAX;
                    }
                    queue[rear] = value;
                    printf("Booking added successfully\n");
                }
                break;
                
            case 2: // Process a booking request (Dequeue)
                if(front == -1) {
                    printf("Queue Underflow\n");
                } 
                else {
                    printf("Processed booking: %d\n", queue[front]);
                    if(front == rear) {
                        front = rear = -1; // Queue becomes empty
                    } 
                    else {
                        front = (front + 1) % MAX;
                    }
                }
                break;
                
            case 3: // Display all pending booking requests
                if(front == -1) {
                    printf("Queue is empty\n");
                } else {
                    int i = front;
                    printf("Pending bookings:\n");
                    while(1) {
                        printf("%d ", queue[i]);
                        if(i == rear) {
                            break;
                        }
                        i = (i + 1) % MAX;
                    }
                    printf("\n");
                }
                break;
                
            case 4: // Exit the program
                return 0;
                
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
