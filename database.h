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

//Check is for function call is from create_db() or update_db()
typedef enum{
    CREATE = 0, //if function call for create funct
    UPDATE = 1 // if function call for update funct
}Call;

Status read_validate(int arg_count, char *filename_argv[], Slist **filename);

void create_database(mnode *arr[], Slist *filename, Call mode);

void display_database(mnode *arr[]);

void search_database(mnode *arr[]);

void update_database(mnode *arr[], Slist **filename);

void save_database(mnode *arr[]);

void free_filenames(Slist *head);

void free_database(mnode *arr[]);


#endif // DATABASE
