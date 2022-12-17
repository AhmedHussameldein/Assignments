// Required functions
_Bool SDB_ISFull(void)
{
    if(counter < 10)
        return 0;
        return 1;
}
u8 SDB_GetUsedSize(void)
{
    return counter;
}
_Bool SDB_AddEntry(u8 id, u8 year, u8* subject, u8* grades)
{
    Student* SD = (Student*)malloc(sizeof(Student));
    SD->id = id;
    SD->year = year;
    for (int i = 0; i < 3; i++)
    {
        SD->C_id[i] = *(subject + i);
        SD->C_grades[i] = *(grades + i);

    }
    // adding from after head
    SD->next = head;
    head = SD;

    // Another method of adding before NULL
//   Student* temp = head;
//   SD->next = NULL;
//    if(head == NULL)
//        head = SD;
//    else
//    {
//        while(temp->next != NULL)
//        {
//            temp = temp->next;
//        }
//        temp->next = SD;
//    }

    F_PTR = fopen("Data_File","w");
    fwrite(SD, sizeof(Student),10,F_PTR);

     counter++;

    return 1;
}

void SDB_DeleteEntry(u8 id)
{
    Student* Delete = head;
    Student* temp = head;

    while(Delete != NULL)
    {
        if(Delete->id == id)
        {
            if(temp->next == Delete->next)
                head = Delete->next;
            else
                temp->next = Delete->next;
            free(Delete);
            counter--;
            return;
        }
        temp = Delete;
        Delete = Delete->next;
    }
}
_Bool SDB_ReadEntry(u8 id, u8* year, u8* subject, u8* grades)
{
    Student* Read = head;
    while(Read != NULL)
    {
        if(Read->id == id)
        {
            *year = Read->year;
            for(int i = 0; i < 3; i++)
            {
                *(subject + i) = Read->C_id[i];
                *(grades + i) = Read->C_grades[i];
            }
            return 1;
        }
        Read = Read->next;
    }
    return 0;
}
void SDB_GetIdList(u8* List)
{
    Student* get = head;
    u8 i = counter - 1;

    while(get != NULL)
    {
        List[i] = get->id;
        get = get->next;
        i--;
    }
}
_Bool SDB_IsIdExist(u8 id)
{
    Student* exist = head;
    while(exist != NULL)
    {
        if(exist->id == id)
            return 1;
        exist = exist->next;
    }
    return 0;
}
