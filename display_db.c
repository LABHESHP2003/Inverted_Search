/***************************************************************************************************************************************************
*Author         :Labhesh Patil
*Date           :Sun Sep 2025 02:07:05 IST
*File           :display_output.c
*Title          :To display  the results.
*Description    :When all the words are searched the ouput list is formed. In this the file with max count
		:(representing maximum word match ) can be selected and displayed. For advanced searched,
		:(weightage of words stored in database linkedlist) can also be used. So the results will be more
		:accurate.
****************************************************************************************************************************************************/
#include <stdio.h>
#include "database.h"

void display_database(mnode *arr[]){
	printf("INDEX	WORD	FILECOUNT	FILENAME	WORDCOUNT\n");
	for(int i = 0; i < 27; i++){
		if(arr[i] != NULL){
			mnode *temp = arr[i];
			while(temp){
				snode *stemp = temp->sublink;
				int first_line = 1;
				if(first_line){
					printf("%d	%s	%d	", i, temp->word, temp->filecount);
                    first_line = 0;
				}
				else{
					printf("%d	%s	%d	\n", i, temp->word, temp->filecount);
					printf("\n");
				}
				while(stemp){
					printf("	    		%s	%d\n", stemp->filename, stemp->wordcount);
					stemp = stemp->slink;
				}
				temp = temp->mainlink;
			}
		}
	}
}