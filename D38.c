/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
int count = 0;

// push_front
void push_front(int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->prev = NULL;
    temp->next = front;

    if(front != NULL)
        front->prev = temp;
    else
        rear = temp;

    front = temp;
    count++;
}

// push_back
void push_back(int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = rear;

    if(rear != NULL)
        rear->next = temp;
    else
        front = temp;

    rear = temp;
    count++;
}

// pop_front
void pop_front(){
    if(front == NULL){
        printf("Deque is empty\n");
        return;
    }

    struct Node* temp = front;
    front = front->next;

    if(front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    free(temp);
    count--;
}

// pop_back
void pop_back(){
    if(rear == NULL){
        printf("Deque is empty\n");
        return;
    }

    struct Node* temp = rear;
    rear = rear->prev;

    if(rear != NULL)
        rear->next = NULL;
    else
        front = NULL;

    free(temp);
    count--;
}

// front element
int getFront(){
    if(front == NULL)
        return -1;
    return front->data;
}

// rear element
int getBack(){
    if(rear == NULL)
        return -1;
    return rear->data;
}

// check empty
int empty(){
    return front == NULL;
}

// size
int size(){
    return count;
}

// clear deque
void clear(){
    while(front != NULL)
        pop_front();
}

// display deque
void display(){
    struct Node* temp = front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);

    display();

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());

    pop_front();
    pop_back();

    display();

    printf("Size: %d\n", size());

    clear();

    printf("Empty: %d\n", empty());

    return 0;
}