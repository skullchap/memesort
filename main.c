#include "meme.h"

int main(int argc, char *argv[])
{
    if (!isatty(fileno(stdin)))
    {
        unsort_strs = malloc(BUF * 4);
        char *p = malloc(WORDLEN);
        while ((fscanf(stdin, "%128s", p) != EOF))
        {
            copystr(&unsort_strs[wordcount], p);
            wordcount++;
        }

        free(p);
        p = NULL;
    }

    node **flist;

    flist = sort(unsort_strs);
    traverse(flist, preinit);
}
