#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare the input variables
    float num_1, num_2;
    char oper;
    // Scanning the first number as an input
    printf("Please enter the first number: ");
    scanf("%f", &num_1);
    /* Scanning the operator as an input
    To scan character after scanning integer or float or ... we need to take a space as an input in scanf function
    so that the user can insert an input character (EX: scanf(" %c", &char); instead of scanf("%c", &char);)*/
    printf("\nPlease enter the operator: ");
    scanf(" %c", &oper);
    // Scanning the second number as an input
    printf("\nPlease enter the second number: ");
    scanf("%f", &num_2);
    // According to the operator we determine the type of operation going to be done using switch function
    switch(oper)
    {
    case '+':
        printf("\nThe result = %0.4f\n", num_1 + num_2);
        break;
    case '-':
        printf("\nThe result = %0.4f\n", num_1 - num_2);
        break;
    case '*':
        printf("\nThe result = %0.4f\n", num_1 * num_2);
        break;
    case '/':
        printf("\nThe result = %0.4f\n", num_1 / num_2);
        break;
    default:
        printf("\nPlease enter right operator (EX: + - * /)\n\n");
        return main();
    }
    return 0;
}
