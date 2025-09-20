#if !defined(FILENAME_H)
#define FILENAME_H

//FILENAME STRUCTURE
typedef struct node {
    char *fname;
    struct node *link;
} Slist;

#endif // FILENAME_H
