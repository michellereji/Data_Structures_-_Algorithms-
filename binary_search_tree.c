#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a book ID into the BST[cite: 22]
struct Node* insert(struct Node *root, int data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
        
    return root;
}

// Function to find the minimum value node in a subtree[cite: 22, 23]
struct Node* minValueNode(struct Node *root) {
    struct Node *current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a book ID from the BST (handles all 3 cases)
struct Node* deleteNode(struct Node *root, int data) {
    if (root == NULL)
        return NULL;
        
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Case a: Node with no child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        
        // Case b: Node with one child (only right child)[cite: 23]
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        
        // Case b: Node with one child (only left child)[cite: 23, 24]
        if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        
        // Case c: Node with two children
        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to display book IDs in ascending order using inorder traversal[cite: 24]
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int n, data, deleteData, i;
    
    printf("Enter number of book IDs: ");
    scanf("%d", &n);
    
    printf("Enter book IDs:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    
    printf("Book IDs in ascending order:\n");
    inorder(root);
    
    printf("\nEnter book ID to delete: ");
    scanf("%d", &deleteData);
    root = deleteNode(root, deleteData);
    
    printf("Book IDs after deletion:\n");
    inorder(root);
    
    return 0;
}
