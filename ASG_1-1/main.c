#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num; // Declare a variable to be input from the user
    // Scan the input variable from the user
    printf("Please enter your number: ");
    scanf("%d", &num);
    // Using ternary operator with condition that use bit-wise operator (&) to determine weather the input is even or odd
    (num & 1? printf("The number is odd = 1\nThe number is even = 0\n"):printf("The number is odd = 0\nThe number is even = 1\n"));
    return 0;
}
