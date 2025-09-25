/***************************************************************************************************************************************************
*Author         :Labhesh Patil
*Date           :Sun Sep 2025 02:07:05 IST
*File           :search.c
*Title          :To search the words.
*Description    :Each word is now used to search in the linkedlist. The word has to be compared with
		:each word in the linked list. When found, the file details can be retrieved. Since the
		:linkedlist is in sorted order, the complexity of searching the word in the complete list
		:can be avoided. While string comparison, if the word in linkedlist is greater than the
		:word to be search, it shows the word doesnt exists in the list,
****************************************************************************************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include "common.h"
#include "database.h"
#include "string.h"
#include "stdlib.h"

Status search_database(mnode *arr[]){
	char word[20];

	//Read the word from user
	printf("Enter the word to search: ");
	scanf("%s",word);
	printf("\n");
	int index;
	if (isalpha(word[0]))
	{
		index = tolower(word[0]) - 'a'; // 'a' to 'z' -> 0 to 25
	}
	else
	{
		index = 26; // for special chars or digits
	}

	mnode *temp = arr[index];
	while(temp){
		//word matching
		if(strcmp(word,temp->word) == SUCCESS){
			//print filecount & word
			if(temp->filecount == 1){
				printf("The word \"%s\" is present in %d file\n",word,temp->filecount);
			}
			else{
				printf("The word \"%s\" is present in %d files\n",word,temp->filecount);
			}
			snode *stemp = temp->sublink;
			//print filename & wrodcount
			while(stemp){
				if(stemp->wordcount == 1){
				printf("In File:\"%s\"	%d time\n",stemp->filename,stemp->wordcount);
				stemp = stemp->slink;
				}
				else{
				printf("In File:\"%s\"	%d times\n",stemp->filename,stemp->wordcount);
				stemp = stemp->slink;
				}
			}
			return SUCCESS;
		}
		temp = temp->mainlink;
	}
	printf("INFO: The word '%s' was not found in the database.\n", word);
	return DATA_NOT_FOUND;
}