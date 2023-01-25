#include "inverted_search.h"

/* To insert the words to the Wlist */
int insert_at_last(Wlist **head, data_t *data)
{
    /* create the node */

    Wlist *new = malloc(sizeof(Wlist));
    // printf("(*head)->word = %s\n", (*head)->word);

    if (new == NULL)
    {
        return FAILURE;
    }

    /* update node */

    new->file_count = 1;
    strcpy(new->word, data);

    new->Tlink = NULL;
    new->link = NULL;

    /* call fun to update link table for the new node */
    update_link_table(&new);

    /* check Wlist is empty or not */

    if (*head == NULL)
    {

        *head = new;
        return SUCCESS;
    }

    /* non empty list */
    else
    {
        Wlist *temp = *head;
        /* traverse through the Wlist */
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
        return SUCCESS;
    }
}

/* To update the Ltable by adding the new node */
int update_link_table(Wlist **head)
{

    // create node

    Ltable *new = malloc(sizeof(Ltable));

    /*Error check */
    if (new == NULL)
    {
        return FAILURE;
    }
    /* Update node details*/
    new->word_count = 1;

    strcpy(new->file_name, fname);

    new->table_link = NULL;

    /*Point the Tlink  of the Wlist head to new node */
    (*head)->Tlink = new;

    return SUCCESS;
}
