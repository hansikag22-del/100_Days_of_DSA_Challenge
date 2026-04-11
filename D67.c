/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    // push after visiting all neighbors
    push(node);
}

// Topological Sort
void topoSort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print stack (reverse order)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int edges, u, v;

    scanf("%d %d", &n, &edges);

    // Initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges (u → v)
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    printf("Topological Order: ");
    topoSort();

    return 0;
}