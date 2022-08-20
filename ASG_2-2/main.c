#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaration of variable and arrays
    int num, mod_num , n = 0, ans = 0;
    char arr_1[10] = {0};
    int arr_2[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    // Scanning the input number
    printf("Please enter the number: ");
    scanf("%d", &num);
    mod_num = num;
    // While loop used to save each digit from the input variable in the first array
    while(mod_num != 0)
    {
        arr_1[n] = mod_num%10;
        mod_num /= 10;
        n++;
    }
    /* For loop used to save each digit power the number of digits in the second array
    then take the summation of all digits in the second array and save it in ans variable */
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            arr_2[i] *= arr_1[i];
        ans += arr_2[i];
    }
    // comparing the summation saved in ans variable with the input variable to see if they are equal
    (ans == num? printf("\n%d is armstrong number\n", num):printf("\n%d is not armstrong number\n", num));

    return 0;
}
