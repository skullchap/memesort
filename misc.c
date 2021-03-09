#include "memesort.h"

size_t BUF = 8192000;

char **unsort_strs = NULL;

int wordcount = 0;

void traverse(node **pp, node *nn)
{
    memenumsort(nn->keys, &nn->kqty);

    for (int n = 0; n < nn->kqty; n++)
    {

        if (pp[nn->keys[n]] == NULL)
            continue;

        if (pp[nn->keys[n]] != NULL && pp[nn->keys[n]]->kword != NULL)
        {
            int r = pp[nn->keys[n]]->keyrepeat;
            do
            {
                printf("%s\n", pp[nn->keys[n]]->kword);
                r--;
            } while (r > 0);
        }

        if (pp[nn->keys[n]] != NULL && pp[nn->keys[n]]->word != NULL)
        {
            int r = pp[nn->keys[n]]->repeat;
            do
            {
                printf("%s\n", pp[nn->keys[n]]->word);
                r--;
            } while (r > 0);
        }

        if (pp[nn->keys[n]] != NULL && pp[nn->keys[n]]->next != NULL)
            traverse(pp[nn->keys[n]]->next, pp[nn->keys[n]]);
        free(pp[nn->keys[n]]);
    }
    free(pp);
}

void copystr(char **dst, char *src)
{
    *dst = malloc(strlen(src) + 1);
    strncpy(*dst, src, (strlen(src) + 1));
}

node **page_init()
{
    node **page = calloc(ARR, sizeof(node *));
    return page;
}

node *node_init()
{
    node *n = malloc(sizeof(node));
    n->repeat = 0;
    n->keyrepeat = 0;
    n->kqty = 0;
    memset(&n->keys[0], 0, sizeof(n->keys));
    n->next = NULL;
    return n;
}

int _ascii_to_index(const char ch)
{
    if (ch & CASEBIT)
        return (ch - LOWEROFF);
    else if (!(ch & CASEBIT))
    {
        return (ch - UPPEROFF);
    }
    else if (ch >= 48 && ch <= 57) // 0 to 9 in ascii
        return (ch - 48);
    else
        return -1;
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void memenumsort(int *src_arr, int *qty)
{
    int dst_arr[ARR] = {0};
    int *ptr = src_arr;

    for (int i = 0; i < *qty; i++)
    {
        dst_arr[*ptr] = *ptr;
        ptr++;
    }
    int j = 0;
    for (int i = 0; i < ARR; i++)
    {
        if (dst_arr[i] != 0)
        {
            src_arr[j] = dst_arr[i];
            j++;
        }
    }
}