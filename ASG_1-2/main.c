#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_before, num_after, nth_num, tog_num = 1; // Declare variables
    // Scan the first variable which would be the number
    printf("Please enter a number: ");
    scanf("%d", &num_before);
    // Scan the second variable which would be the nth number that would be toggled
    printf("Please enter nth bit to be toggled (0-%d): ", sizeof(num_before)*8-1);
    scanf("%d", &nth_num);
    /* If the user enter nth number smaller or bigger than the number of bits of the first input number
    it would return the user to insert right numbers */
    if(nth_num >= sizeof(num_before)*8 || nth_num < 0)
    {
        printf("\nPlease enter nth bit to be toggled from 0 to %d\n\n", sizeof(num_before)*8-1);
        return main();
    }
    // Shifting the one in the first bit to the bit which wanted to toggled by the user
    tog_num <<= nth_num;
    // toggling the bit and saving the new number in num_after
    num_after = num_before ^ tog_num;
    // printing that the bit was toggled after toggling
    printf("Bit is toggled successfully.\n");
    // printing the number before toggling
    printf("\nThe number before toggling %d bit: %d(In decimal)\n", nth_num, num_before);
    // printing the number after toggling
    printf("The number after toggling %d bit: %d(In decimal)\n", nth_num, num_after);

    return 0;
}
