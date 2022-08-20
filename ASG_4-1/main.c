#include <stdio.h>
#include <stdlib.h>

// Prototype and implementation of function that take pointer to integer
void edit(char *ptr)
{
    *ptr += 1;
}

int main()
{
    // Declaration of input variable and pointer to that variable
    int x;
    char *ptr = &x;
    // Scanning the input using the pointer
    printf("Please enter the value of x (from -128 to 127): ");
    scanf("%d", ptr);
    // Printing the input variable before and after editing it
    printf("\nBefore calling edit x = %d\n", x);
    edit(ptr);
    printf("After calling edit x = %d\n", x);
    // Storing another number in the rest of the bytes
    *(ptr+1) = 5;
    *(ptr+2) = 20;
    *(ptr+3) = 80;
    // Printing the rest of the bytes
    printf("\nThe second byte of x contain: %d\n", *(ptr+1));
    printf("The third byte of x contain: %d\n", *(ptr+2));
    printf("The fourth byte of x contain: %d\n", *(ptr+3));

    return 0;
}
