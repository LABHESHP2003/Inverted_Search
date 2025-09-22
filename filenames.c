#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "filenames.h"

// INSERT AT LAST FUNCTION
Status insert_at_last(Slist **head,char *filename){
    Slist *new = (Slist *)malloc(sizeof(Slist));
    if(!new){
        perror("Failed to Allocate Memory for Filename!\n");
        return FAILURE;
    }

    new->fname = (char *)malloc(strlen(filename)+1);
    if(!new->fname){
        perror("Failed to allocate memory for filename string");
        free(new);
        return FAILURE;
    }

    strcpy(new->fname,filename);
    new->link = NULL;

    if(*head == NULL){       //If list is empty
        *head = new;
    }
    else{                  // list is not empty
        Slist *temp = *head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = new;
    }

    return SUCCESS;
}

//Check for duplicate file
Status DuplicateFile(char *filename, Slist *Namelist)
{
    if (Namelist == NULL)
    {
        return SUCCESS;
    }

    Slist *temp = Namelist;
    while (temp != NULL)
    {
        if(strcmp(filename,temp->fname) == 0){
            return FAILURE;
        }
        temp = temp->link;
    }
    return SUCCESS;
}