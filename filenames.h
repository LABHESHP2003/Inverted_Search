#include "common.h"
#if !defined(FILENAME_H)
#define FILENAME_H

//FILENAME STRUCTURE
typedef struct node {
    char *fname;
    struct node *link;
} Slist;

// INSERT AT LAST FUNCTION
Status insert_at_last(Slist **head,char *filename);

//Check for duplicate file
Status DuplicateFile(char *filename, Slist *Namelist);

#endif // FILENAME_H
