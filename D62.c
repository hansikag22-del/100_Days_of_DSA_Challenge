/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Array of linked lists
    struct Node* adjList[n];

    // Initialize all lists as empty
    for(int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    int u, v;
    printf("Enter edges (u v):\n");

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Add v to u's list
        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        // Uncomment below for undirected graph
        /*
        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
        */
    }

    // Print adjacency list
    printf("\nAdjacency List:\n");
    for(int i = 0; i < n; i++) {
        printf("%d -> ", i);
        struct Node* temp = adjList[i];
        while(temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}