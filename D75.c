/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/

#include <stdio.h>

// Simple hash using arrays (for prefix sum)
#define SIZE 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, maxLen = 0;

    // Hash arrays
    int hash[SIZE];
    for (int i = 0; i < SIZE; i++)
        hash[i] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int key = sum + 500; // shift to avoid negative index

        if (hash[key] != -1) {
            int len = i - hash[key];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[key] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}