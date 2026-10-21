#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// (a) Insert element at the beginning
void insertBegin() {
    int value;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    printf("Element inserted successfully\n");
}

// (b) Insert element at the last
void insertLast() {
    int value;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;
    
    if(head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Element inserted successfully\n");
}

// (c) Insert element at a specific position
void insertPosition() {
    int value, pos, i;
    struct node *newnode, *temp;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &value);
    
    if(pos == 1) {
        insertBegin();
        return;
    }
    
    temp = head;
    for(i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if(temp == NULL) {
        printf("Invalid position\n");
    } else {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Element inserted successfully\n");
    }
}

// (d) Delete the first element
void deleteFirst() {
    struct node *temp;
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        head = head->next;
        free(temp);
        printf("First element deleted successfully\n");
    }
}

// (e) Delete the last element
void deleteLast() {
    struct node *temp, *prev;
    if(head == NULL) {
        printf("List is empty\n");
    } else if(head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last element deleted successfully\n");
    } else {
        temp = head;
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        printf("Last element deleted successfully\n");
    }
}

// (f) Delete a specific element by value
void deleteElement() {
    int value;
    struct node *temp, *prev;
    printf("Enter element to delete: ");
    scanf("%d", &value);
    
    if(head == NULL) {
        printf("List is empty\n");
    } else if(head->data == value) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Element deleted successfully\n");
    } else {
        temp = head;
        while(temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        
        if(temp == NULL) {
            printf("Element not found\n");
        } else {
            prev->next = temp->next;
            free(temp);
            printf("Element deleted successfully\n");
        }
    }
}

// Display all elements in the linked list[cite: 11]
void display() {
    struct node *temp = head;
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        printf("List: ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while(1) {
        printf("\n1. Insert Begin\n2. Insert Last\n3. Insert Position\n4. Delete First\n5. Delete Last\n6. Delete Element\n7. Display\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: insertBegin(); break;
            case 2: insertLast(); break;
            case 3: insertPosition(); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: deleteElement(); break;
            case 7: display(); break;
            case 8: return 0;
            default: printf("Invalid choice\n");
        }
    }
}