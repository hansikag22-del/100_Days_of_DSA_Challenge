/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push function
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop function
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    
    return value;
}

// Function to evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0;
    
    while (exp[i] != '\0') {
        
        // If operand
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        
        // If operator
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            
            int val2 = pop();
            int val1 = pop();
            int result;
            
            switch(exp[i]) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    result = val1 / val2;
                    break;
            }
            
            push(result);
        }
        
        i++;
    }
    
    return pop();
}

int main() {
    char exp[100];
    
    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    
    int result = evaluatePostfix(exp);
    
    printf("Result = %d\n", result);
    
    return 0;
}