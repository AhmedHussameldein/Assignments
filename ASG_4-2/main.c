#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare the strings
    char string_array[] = "I like this program very much", rev_array[strlen(string_array)];
    // Declare some variables used as counter
    int n = strlen(string_array), i = 0, j = 0;
    // while loop that store the string reversed in rev_array
    while(n >= -1)
    {
        if(string_array[n] == ' ' || n == -1)
        {
            n++;
            while (string_array[n] != ' ' && n < strlen(string_array))
            {
                rev_array[i] = string_array[n];
                i++;
                n++;
                j++;
            }
            n -= j+1;
            j = 0;
            rev_array[i] = ' ';
            i++;
        }

        n--;
    }
    // Printing the reversed array using for loop
    for(i = 0; i <= strlen(string_array); i++)
        printf("%c", rev_array[i]);

    return 0;
}
