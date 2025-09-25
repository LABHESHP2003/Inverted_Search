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

void display_database(mnode *arr[])
{
    printf("----------------------------------------------------------------------\n");
    printf("%-6s %-18s %-10s %-15s %-10s\n", "INDEX", "WORD", "FILECOUNT", "FILENAME", "WORDCOUNT");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < 27; i++) {
        if (arr[i] != NULL) {
            mnode *temp = arr[i];
            while (temp) {
                snode *stemp = temp->sublink;
                int first_line = 1;

                while (stemp) {
                    if (first_line) {
                        // Print full row with all details
                        printf("%-6d %-18s %-10d %-15s %-10d\n", i, temp->word, temp->filecount, stemp->filename, stemp->wordcount);
                        first_line = 0;
                    } else {
                        // Print only filename and wordcount if same word repeats in multiple files
                        printf("%-6s %-18s %-10s %-15s %-10d\n", 
                            "", "", "", stemp->filename, stemp->wordcount);
                    }
                    stemp = stemp->slink;
                }
                printf("\n");
                temp = temp->mainlink;
            }
        }
    }
    printf("----------------------------------------------------------------------\n");
}
