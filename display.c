#include "inverted_search.h"

void display_database(Wlist *head[])
{

	printf("%-15s %-15s %-15s %s %s%s%15s\n", "[index]", "[word]", "file_count", "file/s:", "File : ", "File_name", "word_count");

	/* traverse through all head pointers and and print the words in each */
	for (int i = 0; i < 27; i++)
	{

		if (head[i] != NULL)
		{

			print_word_count(head[i]);
		}
	}
}

/* fun() to print all the words in a linked list pointed by particular head pointer  */
int print_word_count(Wlist *head)
{

	// traverse through the Wlist
	Wlist *temp = head;
	// index and count variables declared
	int index, count;
	while (temp != NULL)
	{
		count = 0;
		index = tolower(temp->word[0]) % 97;
		/* Index for other than alphabets */
		if (index < 0 || index > 25)
		{
			index = 26;
		}

		printf("%-15d %-15s %-15d file/s:", index, temp->word, temp->file_count);
		Ltable *Thead = temp->Tlink;
		// traverse through the Ltable
		while (Thead)
		{
			// count variable is used to display with proper spacing
			if (count == 0)
			{
				printf("File : %s%15d", Thead->file_name, Thead->word_count);
				// increments count
				count++;
			}
			else
				printf("\n%59s : %s%15d", "File", Thead->file_name, Thead->word_count);

			Thead = Thead->table_link;
		}
		printf("\n");

		temp = temp->link;
	}
	return SUCCESS;
}
