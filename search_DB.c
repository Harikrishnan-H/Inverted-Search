#include "inverted_search.h"
void search(Wlist *head, char *word)
{
	// check list is empty or not
	if (head == NULL)
	{
		printf("Search word is not found , list is empty\n");
		return;
	}

	// traverse the list
	while (head != NULL)
	{
		// compare the search word with available word in the list
		if (strcmp(head->word, word) == 0)
		{
			printf("Word %s is present in %d file/s ", word, head->file_count);
			Ltable *Thead = head->Tlink;
			while (Thead)
			{
				printf("In the file : %s  %d time/s ", Thead->file_name, Thead->word_count);
				Thead = Thead->table_link;
			}
			printf("\n");
			return;
		}
		head = head->link;
	}
	printf("Search word is not found in the list\n");
}
