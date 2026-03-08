/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;   // dynamically allocated array
    int front;  // index of front element
    int rear;   // index of rear element
    int size;   // current number of elements
    int capacity; // maximum capacity
} Queue;

// Function to create a queue of given capacity
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->arr = (int*)malloc(capacity * sizeof(int));
    return q;
}

// Enqueue function
void enqueue(Queue* q, int value) {
    if (q->size == q->capacity) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = value;
    q->size++;
}

// Display function
void displayQueue(Queue* q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Free the queue memory
void freeQueue(Queue* q) {
    free(q->arr);
    free(q);
}

int main() {
    int n;
    scanf("%d", &n);

    Queue* q = createQueue(n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(q, val);
    }

    displayQueue(q);

    freeQueue(q);
    return 0;
}