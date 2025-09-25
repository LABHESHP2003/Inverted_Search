#include <stdio.h>
#include "database.h"
#include <string.h>
#include <stdlib.h>

void save_database(mnode *arr[]){
    char filename[30];
        while (1) {
        printf("Enter the filename to save the database: ");
        scanf("%29s", filename);
        
        if (strstr(filename, ".txt") != NULL) {
            break;
        }
        
        printf("Invalid file format.\n");
        printf("Usage   : Please enter a filename with a '.txt' extension.\n");
        printf("Example : backup.txt\n\n");
    }

    FILE *fp = fopen(filename,"w");
    if(!fp){
        printf("Failed to create file");
        return;
    }

    for(int i = 0; i < 27; i++){
        if(arr[i] != NULL){
            mnode *temp = arr[i];
            while(temp){
                snode *stemp = temp->sublink;
                fprintf(fp,"#%d;%s;%d;",i,temp->word,temp->filecount);
                while(stemp){
                    fprintf(fp,"%s;%d;#",stemp->filename,stemp->wordcount);
                    stemp = stemp->slink;
                }
                temp = temp->mainlink;
            }
        }
    }
    fclose(fp);
    printf("Successfully saved the database in \"%s\" file. \n",filename);
    return;
}
