#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaration of array
    int arr[] = {1, 2, 3, 4, 5};
    // Printing the array before reversing
    printf("The original array: ");
    for(int i = 0; i < sizeof(arr)/4; i++)
        printf("%d ", arr[i]);
    // Printing the array after reversing
    printf("\nThe reversed array: ");
    for(int i = sizeof(arr)/4 - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
