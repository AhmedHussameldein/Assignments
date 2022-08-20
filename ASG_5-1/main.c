#include <stdio.h>
#include <stdlib.h>

// Function used for sorting(prototype and implementation)
void Selecting_Sorting(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                arr [i] = arr[i] + arr[j];
                arr [j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
}

int main()
{
    // Declaration of array of 5 integers and max and min variables
    int arr[5], max, min;
   // Scanning 5 inputs and inserting them in the array
    printf("Please enter 5 numbers:\n");
    for(int i = 0; i < 5; i++)
        scanf("%d", arr + i);
    // Calling the sorting function
    Selecting_Sorting(arr, sizeof(arr)/4);
    // printing the integers in the array
    for(int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }
    // Printing the maximum number and the minimum number in the array
    printf("\n\nThe max = %d\nThe min = %d", arr[4], arr[0]);

    return 0;
}
