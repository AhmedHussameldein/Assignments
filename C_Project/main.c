#include <stdio.h>
#include "TodoList.h"
#include "STD_Types.h"
#include "TodoList.c"

int main()
{
    printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% MENU %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
    printf("\t\t\t\t\t\t1-Check if database is full\n\t\t\t\t\t\t2-show number of used enterise\n\t\t\t\t\t\t3-Add new entry\n\t\t\t\t\t\t4-Delete an entry\n");
    printf("\t\t\t\t\t\t5-Read an entry\n\t\t\t\t\t\t6-Get a list of student IDs\n\t\t\t\t\t\t7-Search for ID\n\t\t\t\t\t\t8-Exit Program\n");
    printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");

    while(1)
    {
        printf("\nPlease select what you want to be done: ");
        scanf("%d", &x);

        if(x == 1)
        {
            if(SDB_ISFull())
                printf("\nFilled data\n");
            else
                printf("\nUnfilled data\n");
        }
        else if(x == 2)
        {
            printf("\nThe size: %d\n", SDB_GetUsedSize());
        }

        else if(x == 3)
        {
            if(SDB_ISFull())
                printf("\nFilled data\nIf you want to add another data please delete at least one student's data\n");
            else
            {
                printf("\nPlease enter the student ID(0~255): ");
                scanf("%d", &S.id);

                if(SDB_IsIdExist(S.id))
                    printf("\nYou have entered an exist ID\nPlease make sure to enter the right ID\n");

                else
                {
                    printf("Please enter the student year: ");
                    scanf("%d", &S.year);

                    for(int i = 0; i < 3; i++)
                    {
                        printf("Please enter the student subject %d ID(character input) and grade(0~100):\n", i + 1);
                        fflush(stdin);
                        printf("");
                        scanf("%c", S.C_id + i);
                        printf("");
                        scanf("%d", S.C_grades + i);
                    }
                    SDB_AddEntry(S.id, S.year, S.C_id, S.C_grades);
                }
            }
        }

        else if(x == 4)
        {
            printf("\nPlease enter the ID of the data you want to delete: ");
            scanf("%d", &S.id);
            if(SDB_IsIdExist(S.id))
            {
                SDB_DeleteEntry(S.id);
                printf("\nDeleted successfully.\n");
            }
            else
                printf("\nThis ID is not exist\n");
        }

        else if(x == 5)
        {
            printf("\nPlease enter the ID of the student to read: ");
            scanf("%d", &S.id);
            if(SDB_IsIdExist(S.id))
            {
                SDB_ReadEntry(S.id, &year, subject, grades);
                printf("\nStudent year: %d\n", year);
                for(int i = 0; i < 3; i++)
                {
                     printf("The subject %d: %c\n",i + 1 , subject[i]);
                     printf("The grade of subject %d: %d\n",i + 1, grades[i]);
                }
            }
            else
                printf("\nThis ID is not exist\n");

        }

        else if(x == 6)
        {
            SDB_GetIdList(List);
            printf("\nId List: ");
            for(int i = 0; i < counter; i++)
                printf("%d   ",List[i]);
            printf("\n");
        }

        else if(x == 7)
        {
            printf("\nPlease enter ID to search: ");
            scanf("%d", &S.id);

            if(SDB_IsIdExist(S.id))
                printf("This Id is exist.\n");
            else
                printf("This Id is not exist.\n");
        }

        else if(x == 8)
        {
            fclose(F_PTR);
            printf("\nThe program is closed.\nI hope it was useful for you\n");
            return 0;
        }

        else
            printf("\nPlease enter correct number from the menu.\n");
    }
}
