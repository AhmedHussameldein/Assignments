#ifndef TODOLIST_H_INCLUDED
#define TODOLIST_H_INCLUDED

#include"STD_Types.h"

u8 counter = 0, x;
u8 year;
u8 subject[3];
u8 grades[3];
u8 List[10] = {0};


typedef struct Student
{
    u8 id;
    u8 year;
    u8 C_id[3];
    u8 C_grades[3];
    struct Student* next;
}Student;

Student* head = NULL;
Student S;

// Required functions
_Bool SDB_ISFull(void);
u8 SDB_GetUsedSize(void);
_Bool SDB_AddEntry(u8 id, u8 year, u8* subject, u8* grades);
void SDB_DeleteEntry(u8 id);
_Bool SDB_ReadEntry(u8 id, u8* year, u8* subject, u8* grades);
void SDB_GetIdList(u8* List);
_Bool SDB_IsIdExist(u8 id);

#endif // TODOLIST_H_INCLUDED
