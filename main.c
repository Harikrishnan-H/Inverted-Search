/*
Name            :   Harikrishnan.H
Date            :   20/01/2023
Description     :   Project - Inverted search
*/

#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");

    Wlist *head[27];
    // initialising head pointers
    for (int i = 0; i < 27; i++)
    {
        head[i] = NULL;
    }

    // validate CLA
    if (argc <= 1)
    {
        printf("Enter the valid no. arguments\n");
        printf("./Slist.exe f1.txt f2.txt ....\n");
        return 0;
    }

    // create list of files

    // declare file head pointer

    Flist *f_head = NULL;

    // validation of files

    file_validation_n_file_list(&f_head, argv);

    if (f_head == NULL)
    {
        printf("No files are available in the file list\n");
        printf("Hence the process terminated\n");
        return 1;
    }
    // char select declared and initialised
    char select = 'y';
    do
    {
        // integer variables choice and index declared
        int choice, index;
        // string word declared
        char word[WORD_SIZE];
        // prompt the user for choice
        printf("Select your choice among following options:\n1. Create DATABASE\n2. Display Database\n3. Update DATABASE\n4. Search\n5. Save Database\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // CREATE DATABASE
            create_database(f_head, head);
            break;
        case 2:
            // DISPLAY DATABASE
            display_database(head);
            break;
        case 3:
            // UPDATE DATABASE
            update_database(head, &f_head);
            break;
        case 4:
            // SEARCH
            printf("Enter the word to search\n");
            scanf("%s", word);
            // finding the index
            index = tolower(word[0]) % 97;
            /* Index for other than alphabets */
            if (index < 0 || index > 25)
            {
                index = 26;
            }
            search(head[index], word);
            break;
        case 5:
            // SAVE DATABSE
            save_database(head);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        printf("Do you want to continue?\nEnter y/Y to continue or n/N to discontinue\n");
        __fpurge(stdin);
        // read select
        scanf("%c", &select);

    } while (select == 'y' || select == 'Y');
    return 0;
}