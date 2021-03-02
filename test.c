#include "memesort.h"

int main(int argc, char *argv[])
{
    char **buf, *p = NULL;

    if (!isatty(fileno(stdin)))
    {
        buf = malloc(BUF * 4);
        p = malloc(WORDLEN);
        while ((fscanf(stdin, "%128s", p) != EOF))
        {
            copystr(&buf[wordcount], p);
            wordcount++;
        }
        free(p);
        p = NULL;
    }

    int j;

    for (int i = 0; i < wordcount; i++)
    {
        p = buf[i];
        while (*p != '\0')
        {
            j = _to_ascii(*p);
            printf("%d",j);
            p++;
        }
        printf("\n");
    }
}