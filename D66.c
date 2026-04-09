#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int n;

// DFS function
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {  // edge exists
            if (!visited[i]) {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent) {
                return true;  // cycle found
            }
        }
    }
    return false;
}

// Function to check cycle
bool hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int edges, u, v;

    scanf("%d %d", &n, &edges);

    // Initialize
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // Input edges
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}