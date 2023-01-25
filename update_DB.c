
#include "inverted_search.h"
void update_database(Wlist *head[], Flist **f_head)
{
	/* prompt the user to enter new filename */

	char file_name[FNAME_SIZE];
	Flist *temp = *f_head;
	int empty, i;
	printf("Enter the filename\n");
	scanf("%s", file_name);

	// validate the file_name
	empty = isFileEmpty(file_name);
	/* If the given file is not available */
	if (empty == FILE_NOTAVAILABLE)
	{
		printf("file : %s is not available \n", file_name);
		printf("Hence we are not adding the file into file linked list\n");
		i++;
	}
	/* If the given file is empty */
	else if (empty == FILE_EMPTY)
	{
		printf("file : %s is not having any contents in it \n", file_name);
		printf("Hence we are not adding the file into file linked list\n");
		i++;
	}
	else
	{
		int ret_val = to_create_list_of_files(f_head, file_name);
		if (ret_val == SUCCESS)
		{
			printf("Successfull : Inserting the file name : %s into the file linked list\n", file_name);
		}
		else if (ret_val == REPEATATION)
		{
			printf("The file name : %s is repeated , hence we are not adding into the linked list\n", file_name);
		}
		else
		{
			printf("FAILURE\n");
		}
	}

	while (temp)
	{
		if (!strcmp(temp->file_name, file_name))
		{
			create_database(temp, head);
		}
		temp = (temp->link);
	}
}
