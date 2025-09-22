/***************************************************************************************************************************************************
*Author         :Labhesh Patil
*Date           :Sun Sep 2025 02:07:05 IST
*File           :create_database.c
*Title          :To create the database
*Description    :The list of the files can be provided by storing all the file names in another file, FileList the names of the files which 
		:are to be documented are provided by this file. When a file is added or removed, FileList is changed accordingly.
		:So read the file names and start indexing.
****************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "database.h"

mnode *create_mainnode(char *word);
snode *create_subnode(char *fname);

void create_database(mnode *arr[], Slist *filename)
{
	char word[20];
	while(filename){
		//open the file
		FILE *fp = fopen(filename->fname,"r");

		//get the word
		while(fscanf(fp,"%s",word) != EOF){
			int index = tolower(word[0] % 'a');
			if(arr[index] == NULL){
				//create a new mainnode
				mnode *new_main = create_mainnode(word);
				//create a new subnode
				snode *new_sub = create_subnode(filename->fname);
				//update mainnode sublink with subnode
				new_main->sublink = new_sub;
				//update index of array of mainnode with address of mainnode
				arr[index] = new_main;
			}
			else{
				mnode *temp = arr[index], *prev;
				//traverse through mainnodes
				while(temp){
					//compare current file word with mainnode words
					if(strcmp(temp->word,word) == 0){
						break;
					}
					prev = temp;
					temp = temp->mainlink;
				}
				//if word not matching
				if(temp == NULL){
					//create new mainnode
					mnode *new_main = create_mainnode(word);
					//create new subnode
					snode *new_sub = create_subnode(filename->fname);
					//update mainnode sublink with subnode
					new_main->sublink = new_sub;
					prev->mainlink = new_main;
				}
				else{
					//word matching
					snode *stemp = temp->sublink,*sprev;
					//traverse through subnodes
					while(stemp){
						if(strcmp(stemp->filename,filename->fname) == 0){
							break;
						}
						sprev = stemp;
						stemp = stemp->slink;
					}
					//filename not matching
					if(stemp == NULL){
						//create a new subnode
						snode *new_sub = create_subnode(filename->fname);
						//update last subnode sublink with new subnode address
						sprev->slink = new_sub;
						//update filecount
						temp->filecount ++;
					}
					//filename matching
					else{
						//update wordcout
						stemp->wordcount ++;
					}
				}
			}
		}

		filename = filename->link;
	}
}

mnode * create_mainnode(char *word){
	mnode *new = malloc(sizeof(mnode));
	new->filecount = 1;
	new->word = malloc(strlen(word) + 1);
	strcpy(new->word,word);
	new->sublink = NULL;
	new->mainlink = NULL;
	return new;
}

snode * create_subnode(char *fname){
	snode *new = malloc(sizeof(snode));
	new->filename = malloc(strlen(fname) + 1);
	strcpy(new->filename,fname);
	new->wordcount = 1;
	new->slink = NULL;
	return new;
}

