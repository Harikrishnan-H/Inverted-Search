#include "inverted_search.h"
void save_database(Wlist *head[])
{
    // prompt the user to enter filename
    int i;
    char file_name[FNAME_SIZE];
    printf("Enter the file name to save the database\n");
    scanf("%s", file_name);

    // open file

    FILE *fptr = fopen(file_name, "w");
    for (i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            write_databasefile(head[i], fptr);
        }
    }
    printf("Database Saved Successfully\n");
}

void write_databasefile(Wlist *head, FILE *databasefile)
{
    Wlist *temp = head;
    int index;
    while (temp != NULL)
    {
        // finding the index
        index = tolower(temp->word[0]) % 97;
        /* Index for other than alphabets */
        if (index < 0 || index > 25)
        {
            index = 26;
        }
        fprintf(databasefile, "#:%d [%s] : [%d]", index, temp->word, temp->file_count);

        Ltable *Thead = temp->Tlink;
        // traverse through the Ltable
        while (Thead)
        {

            fprintf(databasefile, " : %s : %d", Thead->file_name, Thead->word_count);

            Thead = Thead->table_link;
        }
        fprintf(databasefile, "\n");

        temp = temp->link;
    }
}
