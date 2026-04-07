/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // visited array
int queue[MAX];      // queue
int n;

// BFS function
void bfs(int start) {
    int front = 0, rear = 0;

    // enqueue start node
    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear) {
        int current = queue[front++];   // dequeue

        printf("%d ", current);

        // visit all adjacent nodes
        for(int i = 0; i < n; i++) {
            if(adj[current][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;      // enqueue
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // initialize visited
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}