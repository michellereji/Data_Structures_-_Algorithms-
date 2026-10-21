#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array around a pivot
int Partition(int A[], int lb, int ub) {
    int pivot = A[lb];
    int left = lb;
    int right = ub;
    
    while(left < right) {
        while(A[left] <= pivot && left < ub)
            left++;
        while(A[right] >= pivot && right > lb)
            right--;
        if(left < right)
            swap(&A[left], &A[right]);
    }
    swap(&A[lb], &A[right]);
    return right;
}

// Function to implement Quick Sort recursively[cite: 30]
void QuickSort(int A[], int lb, int ub) {
    if(lb < ub) {
        int position = Partition(A, lb, ub);
        QuickSort(A, lb, position - 1);
        QuickSort(A, position + 1, ub);
    }
}

int main() {
    int A[50], n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);
        
    QuickSort(A, 0, n - 1);
    
    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}