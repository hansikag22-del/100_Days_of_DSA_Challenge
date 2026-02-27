/* Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node *longer = head1, *shorter = head2;

    if (len2 > len1) {
        longer = head2;
        shorter = head1;
    }

    for (int i = 0; i < diff; i++)
        longer = longer->next;

    while (longer != NULL && shorter != NULL) {
        if (longer == shorter)
            return longer;

        longer = longer->next;
        shorter = shorter->next;
    }

    return NULL;
}

// Find node in first list by value
struct Node* findNode(struct Node* head, int value) {
    while (head != NULL) {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

int main() {
    int n, m, value;

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }

    // Second list
    scanf("%d", &m);

    struct Node* temp2 = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d", &value);

        struct Node* intersectionNode = findNode(head1, value);

        if (intersectionNode != NULL) {
            if (head2 == NULL)
                head2 = intersectionNode;
            else
                temp2->next = intersectionNode;
            break;  // stop creating new nodes
        }

        struct Node* newNode = createNode(value);

        if (head2 == NULL)
            head2 = newNode;
        else
            temp2->next = newNode;

        temp2 = newNode;
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}