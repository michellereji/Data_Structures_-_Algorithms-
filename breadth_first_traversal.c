#include <stdio.h>
#define MAX 100

int main() {
    int n, i, j, source;
    int graph[MAX][MAX], visited[MAX] = {0};
    int queue[MAX], front = -1, rear = -1;

    // Enter number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Enter the adjacency matrix representation of the graph
    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Enter the starting vertex
    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    // Step 4: Mark the starting vertex as visited[cite: 32]
    visited[source] = 1;

    // Step 5: Insert the starting vertex into the queue[cite: 32]
    front = rear = 0;
    queue[rear] = source;

    printf("BFS Traversal: ");

    // Step 6: Repeat while the queue is not empty[cite: 32]
    while(front <= rear) {
        // Step 6.i: Remove a vertex from the front of the queue[cite: 32]
        int vertex = queue[front++];

        // Step 6.ii: Display the vertex[cite: 32]
        printf("%d ", vertex);

        // Step 6.iii: Check all adjacent vertices[cite: 32]
        for(i = 0; i < n; i++) {
            // If edge exists and vertex is unvisited[cite: 32]
            if(graph[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;          // Mark as visited[cite: 32]
                queue[++rear] = i;       // Insert into queue[cite: 32]
            }
        }
    }
    
    printf("\n");
    return 0;
}