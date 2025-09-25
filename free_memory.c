#include <stdlib.h>
#include <string.h>
#include "filenames.h"
#include "database.h"

void free_filenames(Slist *head) {
    Slist *temp;
    while (head) {
        temp = head;
        head = head->link;
        free(temp->fname);  
        free(temp);       
    }
}

void free_database(mnode *arr[]) {
    for (int i = 0; i < 27; i++) {
        mnode *mtemp = arr[i];
        while (mtemp) {
            mnode *mnext = mtemp->mainlink;

            snode *stemp = mtemp->sublink;
            while (stemp) {
                snode *snext = stemp->slink;
                free(stemp->filename);
                free(stemp);
                stemp = snext;
            }

            free(mtemp->word);
            free(mtemp);
            mtemp = mnext;
        }
    }
}
