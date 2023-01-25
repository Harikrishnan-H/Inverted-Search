#include "inverted_search.h"

void create_database(Flist *f_head, Wlist *head[])
{
	/*traverse through the file linked list*/

	Flist *temp = f_head;
	while (temp)
	{

		read_datafile(temp, head, temp->file_name);
		temp = temp->link;
	}
}

// read the contents of the file
void read_datafile(Flist *file, Wlist *head[], char *filename)
{

	/* open the file in read mode */

	FILE *fptr = fopen(filename, "r");

	int flag;
	flag = 1;

	strcpy(fname, filename);

	// declare an array to store the words

	char word[WORD_SIZE];

	while (fscanf(fptr, "%s", word) != EOF)
	{

		/* Finding index */
		int index;
		flag = 1;

		index = tolower(word[0]) % 97;

		/* Index for other than alphabets */
		if (index < 0 || index > 25)
		{

			index = 26;
		}

		// check whether words are repeated or not
		if (head[index] != NULL)
		{

			Wlist *temp = head[index];
			// compare the words at each node with new word
			while (temp)
			{

				if (!strcmp(temp->word, word))
				{

					update_word_count(&temp, filename);

					flag = 0;
					break;
				}
				temp = temp->link;
			}
		}

		if (flag == 1)
		{

			// words are not repeated

			insert_at_last(&head[index], word);
		}
	}
}

int update_word_count(Wlist **head, char *file_name)
{

	// check for whether filenames are same or not
	Wlist *Wtemp = *head;
	Ltable *Thead = (*head)->Tlink;
	Ltable *prev;

	while (Thead)
	{
		/* if the filenames are same */
		if (!(strcmp(Thead->file_name, file_name)))
		{
			// increment the word count
			(Thead->word_count)++;
			return SUCCESS;
		}
		prev = Thead;
		Thead = Thead->table_link;
	}

	/*if filenames are different*/
	/* Increment file count */
	((*head)->file_count)++;

	/* Create new node of type Ltable  */

	Ltable *new = malloc(sizeof(Ltable));

	/* Update new node */
	strcpy(new->file_name, file_name);
	new->word_count = 1;
	new->table_link = NULL;

	/* Add node to list */
	prev->table_link = new;

	return SUCCESS;
}
