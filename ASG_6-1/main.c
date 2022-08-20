#include <stdio.h>
#include <stdlib.h>

// Forming new data-type that contain string and 3 integers calling it data
struct data
{
    char *Name;
    int Age;
    int Degree;
    int Section;
};
// prototype and implementation of print function that print the data of each student
void Print(struct data *arr)
{
    for(int i = 0; i < 5; i++)
    {
        printf("Student %d", i+1);
        printf("\n\nName\t: ");
        for(int j = 0; j < strlen((arr+i)->Name); j++)
        printf("%c", (arr+i)->Name[j]);
        printf("\nAge\t: %d", (arr+i)->Age);
        printf("\nDegree\t: %d", (arr+i)->Degree);
        printf("\nSection\t: %d", (arr+i)->Section);
        printf("\n-------------\n");
    }
}

int main()
{
    // Declare array of data data-type
    struct data arr[5];
    // Inserting the information of first student
    arr->Name = "Ahmed";
    arr->Age = 21;
    arr->Degree = 100;
    arr->Section = 1;
    // Inserting the information of second student
    (arr+1)->Name = "Sara";
    (arr+1)->Age = 19;
    (arr+1)->Degree = 100;
    (arr+1)->Section = 1;
    // Inserting the information of third student
    (arr+2)->Name = "Muhammed";
    (arr+2)->Age = 27;
    (arr+2)->Degree = 91;
    (arr+2)->Section = 2;
    // Inserting the information of fourth student
    (arr+3)->Name = "Mahmoud";
    (arr+3)->Age = 25;
    (arr+3)->Degree = 73;
    (arr+3)->Section = 2;
    // Inserting the information of fifth student
    (arr+4)->Name = "Ramy";
    (arr+4)->Age = 33;
    (arr+4)->Degree = 50;
    (arr+4)->Section = 3;
    // Calling the print function
    Print(arr);

    return 0;
}
