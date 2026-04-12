/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int val) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = val;
}

int dequeue(Queue* q) {
    int val = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return val;
}

void topologicalSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int result[MAX];
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    Queue q;
    initQueue(&q);

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        result[index++] = node;

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(&q, i);
                }
            }
        }
    }

    if (index != n) {
        printf("Graph has a cycle. No Topological Order.\n");
        return;
    }

    printf("Topological Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
}

int main() {
    int n = 4;

    int adj[MAX][MAX] = {
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    topologicalSort(n, adj);

    return 0;
}