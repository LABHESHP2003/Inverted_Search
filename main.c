/***************************************************************************************************************************************************
*Author         :Labhesh Patil
*Date           :Sun Sep 2025 02:07:05 IST
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "inverted_search.h"
#include "filenames.h"

Status read_validate(int arg_count, char *filename_argv[], Slist *filename){
	if(arg_count > 1){
		//Check file type .txt
		int count = arg_count-1;
		for(int i = 1; i < arg_count; i++){
			if(strstr(filename_argv[i],".txt") == NULL){
				printf("File is not .txt\n");
			}

			//Check if file is present or not
			FILE *ptr = fopen(filename_argv[i],"r");
			if(ptr == NULL){
				printf("File \"%s\" not found\n", filename_argv[i]);
				continue;
			}
			printf("File \"%s\" found.\n", filename_argv[i]);

			// Check file is not empty
			fseek(ptr, 0, SEEK_END);
			long size = ftell(ptr);
			
			if (size == 0){
				printf("File \"%s\" is Empty\n", filename_argv[i]);
				fclose(ptr);
				continue;
			}

			// File should not repeat(Check duplicate file)
			if (DuplicateFile(filename_argv[i], filename) == FAILURE)
			{
				printf("Duplicate File found\n");
				continue;
			}

			// Store the filename to a List
			insert_at_last(filename, filename_argv[i]);
		}
		return SUCCESS;
	}
	else{
		printf("No files provided!\n");
        printf("Usage: ./a.out <file1.txt> <file2.txt> ...\n");
        printf("Example: ./a.out data1.txt data2.txt\n");
		return FAILURE;
	}
}

int main(int argc, char *argv[])
{
	/* Define the main function here */
	Slist *filename = NULL; //Head of the FILENAME SLL
	int choice;
	if(read_validate(argc,argv,&filename) == FAILURE){
		printf("Failed to Validate Files\n");
		return FAILURE;
	}
	
}

