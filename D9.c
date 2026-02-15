/* Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/

#include <stdio.h>
#include <string.h>

// Recursive function to print string in reverse
void mirror(char str[], int index) {
    if (index < 0)
        return;   // Base case

    printf("%c", str[index]);   // Print current character
    mirror(str, index - 1);     // Recursive call
}

int main() {
    char str[100];

    printf("Enter the code name: ");
    scanf("%s", str);

    int length = strlen(str);

    printf("Mirror format: ");
    mirror(str, length - 1);

    printf("\n");

    return 0;
}

