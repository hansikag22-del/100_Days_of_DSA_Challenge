/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int value;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'e') {   // enqueue
            scanf("%d", &value);
            enqueue(value);
        }
        else if (op[0] == 'd') {  // dequeue
            dequeue();
        }
    }

    return 0;
}