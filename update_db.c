#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "database.h"
#include "filenames.h"
//update only one file at time 
void update_database(mnode *arr[], Slist **filename){
    char *file = malloc(sizeof(char)*30);
    if(!file){
        perror("Failed to allocate memory\n");
        return;
    }
    printf("Enter the filename to update database: ");
    scanf("%29s",file);

    char *files[] = {"a.out",file};

    if(read_validate(2,files,filename) == FAILURE){
        free(file);
        return;
    }

    //update the database for the file added at the last of the stack
    Slist *new = *filename;
    while(new->link != NULL){
        new = new->link;
    }
    
    create_database(arr,new,UPDATE);
    free(file);
}
