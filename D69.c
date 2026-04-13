/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex, weight;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap structure
struct MinHeap {
    int vertex[MAX];
    int dist[MAX];
    int size;
};

// Swap
void swap(struct MinHeap* h, int i, int j) {
    int t1 = h->vertex[i];
    int t2 = h->dist[i];

    h->vertex[i] = h->vertex[j];
    h->dist[i] = h->dist[j];

    h->vertex[j] = t1;
    h->dist[j] = t2;
}

// Heapify
void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->dist[left] < h->dist[smallest])
        smallest = left;

    if (right < h->size && h->dist[right] < h->dist[smallest])
        smallest = right;

    if (smallest != i) {
        swap(h, i, smallest);
        heapify(h, smallest);
    }
}

// Extract min
int extractMin(struct MinHeap* h) {
    int v = h->vertex[0];
    h->vertex[0] = h->vertex[h->size - 1];
    h->dist[0] = h->dist[h->size - 1];
    h->size--;
    heapify(h, 0);
    return v;
}

// Decrease key
void decreaseKey(struct MinHeap* h, int v, int d) {
    for (int i = 0; i < h->size; i++) {
        if (h->vertex[i] == v) {
            h->dist[i] = d;
            while (i && h->dist[(i - 1)/2] > h->dist[i]) {
                swap(h, i, (i - 1)/2);
                i = (i - 1)/2;
            }
            break;
        }
    }
}

// Check empty
int isEmpty(struct MinHeap* h) {
    return h->size == 0;
}

// Dijkstra
void dijkstra(int V, int source) {
    int dist[MAX];

    struct MinHeap heap;
    heap.size = V;

    // Initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        heap.vertex[i] = i;
        heap.dist[i] = INT_MAX;
    }

    dist[source] = 0;
    heap.dist[source] = 0;

    while (!isEmpty(&heap)) {
        int u = extractMin(&heap);

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                decreaseKey(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int V, E, u, v, w, source;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize adjacency list
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // for undirected graph
    }

    printf("Enter source: ");
    scanf("%d", &source);

    dijkstra(V, source);

    return 0;
}