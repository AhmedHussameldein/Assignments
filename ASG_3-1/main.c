#include <stdio.h>
#include <stdlib.h>

// Prototype and implementation of the swap function
void Swap_Function(int num_1, int num_2)
{
    // Print the 2 numbers before swapping
    printf("\nBefore swapping\nThe first number = %d\tThe second number = %d\n", num_1, num_2);
    // Swapping using addition and subtraction operators
    num_1 = num_1 + num_2;
    num_2 = num_1 - num_2;
    num_1 = num_1 - num_2;
    // Print the 2 numbers after swapping
    printf("\nAfter swapping\nThe first number = %d\tThe second number = %d\n", num_1, num_2);
}

int main()
{
    // Declare input variables
    int num_1, num_2;
    // Scanning the first input number
    printf("Please enter the first number: ");
    scanf("%d", &num_1);
    // Scanning the second input number
    printf("Please enter the second number: ");
    scanf("%d", &num_2);
    // Calling the function
    Swap_Function(num_1, num_2);

    return 0;
}
