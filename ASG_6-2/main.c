#include <stdio.h>
#include <stdlib.h>

// forming new data-type called comp_num consist of 2 float numbers
struct comp_num
{
    float real;
    float imag;
};

int main()
{
    // Declare 2 objects of comp_num data-type
    struct comp_num num_1, num_2;
    // Scanning the first complex number
    printf("For first complex number\n");
    printf("Enter real and imaginary part respectively:\n");
    scanf("%f", &num_1.real);
    scanf("%f", &num_1.imag);
    // Scanning the second complex number
    printf("\nFor second complex number\n");
    printf("Enter real and imaginary part respectively:\n");
    scanf("%f", &num_2.real);
    scanf("%f", &num_2.imag);
    // Adding the real part of each number and the complex part of each number
    float real_sum = num_1.real + num_2.real;
    float imag_sum = num_1.imag + num_2.imag;
    // Printing the sum of the 2 complex numbers
    printf("\nThe sum = %0.1f + %0.1fi", real_sum, imag_sum);

    return 0;
}
