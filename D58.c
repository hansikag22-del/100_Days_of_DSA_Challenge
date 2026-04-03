/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to build tree
struct Node* buildTree(int preorder[], int inorder[],
                       int preStart, int preEnd,
                       int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // Root from preorder
    int rootVal = preorder[preStart];
    struct Node* root = newNode(rootVal);

    // Find root in inorder
    int k;
    for (k = inStart; k <= inEnd; k++) {
        if (inorder[k] == rootVal)
            break;
    }

    int leftSize = k - inStart;

    // Left subtree
    root->left = buildTree(preorder, inorder,
                           preStart + 1, preStart + leftSize,
                           inStart, k - 1);

    // Right subtree
    root->right = buildTree(preorder, inorder,
                            preStart + leftSize + 1, preEnd,
                            k + 1, inEnd);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(preorder, inorder, 0, n-1, 0, n-1);

    postorder(root);

    return 0;
}