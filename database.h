#include "filenames.h"
#if !defined(DATABASE_H)
#define DATABASE_H

//SUBNODE
typedef struct subnode{
    int wordcount;
    char *filename;
    struct subnode *slink;
} snode;

//MAIN NODE
typedef struct mainnode{
    char *word;
    int filecount;
    snode *sublink;
    struct mainnode *mainlink;
} mnode;

void create_database(mnode *arr[], Slist *filename);

void display_database(mnode *arr[]);


#endif // DATABASE
