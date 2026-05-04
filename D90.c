/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.
*/

#include <stdio.h>

int isFeasible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        if(currentSum + boards[i] > maxTime) {
            painters++;
            currentSum = boards[i];

            if(painters > k)
                return 0;
        } else {
            currentSum += boards[i];
        }
    }

    return 1;
}