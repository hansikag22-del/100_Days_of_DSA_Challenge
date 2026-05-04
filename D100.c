/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/

#include <stdlib.h>

#define MAX 20001  // for value range [-10000, 10000]

int BIT[MAX];

void update(int i) {
    while (i < MAX) {
        BIT[i] += 1;
        i += i & (-i);
    }
}

int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= i & (-i);
    }
    return sum;
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * numsSize);

    // Shift values to make them positive (indexing for BIT)
    int offset = 10001;

    for (int i = numsSize - 1; i >= 0; i--) {
        int val = nums[i] + offset;

        result[i] = query(val - 1); // count smaller elements
        update(val);
    }

    *returnSize = numsSize;
    return result;
}