#if !defined(INVERTED_SEARCH_H)
#define INVERTED_SEARCH_H

// Status SUCCESS OR FAILURE
typedef enum{
    SUCCESS = 0,
    FAILURE = 1
}Status;

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


#endif // INVERTED_SEARCH
