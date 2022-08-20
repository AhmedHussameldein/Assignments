#include <stdio.h>
#include <stdlib.h>

// Prototype and implementation of the recursion function of the Fibonacci sequence
int Fibonacci_Seq_RM(int n)
{
    if ( n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
       return Fibonacci_Seq_RM(n-1) + Fibonacci_Seq_RM(n-2);
    }

}
// Prototype and implementation of the iterative function of the Fibonacci sequence
void Fibonacci_Seq_IM(int n)
{
    int num_1 = 0, num_2 = 1;
    printf("%d %d ", num_1, num_2);
    for(int i = 2; i < n; i++)
    {
        printf("%d ", num_1 + num_2);
        num_2 = num_1 + num_2;
        num_1 = num_2 - num_1;
    }
}

int main()
{
    // Declaration of the input variable
    int n;
    // Scanning the input variable
    printf("Please enter the number of terms: ");
    scanf("%d", &n);
    // printing the Fibonacci sequence using the recursion function
    for (int i = 0; i < n; i++)
    printf("%d ", Fibonacci_Seq_RM(i));
    // Scanning the input variable
    printf("\n\nPlease enter the number of terms: ");
    scanf("%d", &n);
    // printing the Fibonacci sequence using the iterative function
    Fibonacci_Seq_IM(n);
    printf("\n");

    return 0;
}
