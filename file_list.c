#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{

	int i = 1, empty;
	while (argv[i] != NULL)
	{
		empty = isFileEmpty(argv[i]);

		if (empty == FILE_NOTAVAILABLE)
		{
			printf("file : %s is not available \n", argv[i]);
			printf("Hence we are not adding the file into file linked list\n");
			i++;
			continue;
		}
		else if (empty == FILE_EMPTY)
		{
			printf("file : %s is not having any contents in it \n", argv[i]);
			printf("Hence we are not adding the file into file linked list\n");
			i++;
			continue;
		}
		else
		{

			int ret_val = to_create_list_of_files(f_head, argv[i]);
			if (ret_val == SUCCESS)
			{
				printf("Successfull : Inserting the file name : %s into the file linked list\n", argv[i]);
				i++;
			}
			else if (ret_val == REPEATATION)
			{
				printf("The file name : %s is repeated , hence we are not adding into the linked list\n", argv[i]);
				i++;
			}
			else
			{
				printf("FAILURE\n");
				i++;
			}
		}
	}
}

// fun() is used to check for file exist or not
//  check for file contents
int isFileEmpty(char *filename)
{
	FILE *fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		if (errno == ENOENT) // ---->
		{
			return FILE_NOTAVAILABLE;
		}
	}

	fseek(fptr, 0, SEEK_END);
	if (ftell(fptr) == 0)
	{
		return FILE_EMPTY;
	}
}

// fun() to create list of files

int to_create_list_of_files(Flist **f_head, char *name)
{
	Flist *temp = *f_head;

	// check if filename is duplicate by traversing through the list
	while (temp != NULL)
	{
		if (strcmp(temp->file_name, name) == 0)
		{
			return REPEATATION;
		}
		else
			temp = temp->link;
	}

	// create node
	Flist *new = malloc(sizeof(Flist));

	// error checking
	if (new == NULL)
		return FAILURE;

	// update
	strcpy(new->file_name, name);
	new->link = NULL;

	// check list empty or not
	if (*f_head == NULL)
	{
		*f_head = new;
		return SUCCESS;
	}

	// create reference pointer temp
	temp = *f_head;

	// traverse the list till last node
	while (temp->link != NULL)
		temp = temp->link;

	// establish link between last and new node
	temp->link = new;
	return SUCCESS;
}
