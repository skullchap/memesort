#include "memesort.h"

node *preinit = NULL;
node **initpage = NULL;

node **sort(char **unsorted)
{
    preinit = node_init();
    initpage = page_init();
    preinit->next = initpage;
    node **page = initpage;
    node **previous_page = NULL;
    node **next_page = NULL;

    temp.repeat = 0;

    char *p, *pp = NULL;

    for (int i = 0; i < wordcount; i++)
    {
        page = initpage;
        previous_page = NULL;
        p = pp = unsort_strs[i];
        int level = 1;
        int j;
        while (*p != '\0')
        {
            j = _ascii_to_index(*p);

            if (page[j] == NULL)
            {
                page[j] = node_init();

                if (previous_page != NULL)
                {
                    previous_page[(_ascii_to_index(*(p - 1)))]->keys[previous_page[(_ascii_to_index(*(p - 1)))]->kqty] = j;
                    previous_page[(_ascii_to_index(*(p - 1)))]->kqty++;
                }
                if (previous_page == NULL)
                {
                    preinit->keys[preinit->kqty] = j;
                    preinit->kqty++;
                }

                if (temp.word != NULL)
                {
                    page[j]->word = temp.word;
                    temp.word = NULL;
                    p = &page[j]->word[level - 1];
                    page[j]->repeat = temp.repeat;
                    temp.repeat = 0;
                }

                if (previous_page != NULL &&
                    previous_page[(_ascii_to_index(*(p - 1)))]->word != NULL &&
                    previous_page[(_ascii_to_index(*(p - 1)))]->word[level - 1] == *p)
                {
                    temp.word = previous_page[(_ascii_to_index(*(p - 1)))]->word;
                    previous_page[(_ascii_to_index(*(p - 1)))]->word = NULL;
                    temp.repeat = previous_page[(_ascii_to_index(*(p - 1)))]->repeat;

                    previous_page[(_ascii_to_index(*(p - 1)))]->repeat = 0;

                    if (page[j]->word == NULL)
                    {
                        page[j]->word = pp;
                        page[j]->repeat++;
                    }

                    page[j]->next = page_init(); //
                    previous_page = page;
                    if (temp.word != NULL)
                        p = &temp.word[level];

                    if (*p == '\0')
                    {
                        page[j]->kword = temp.word;
                        temp.word = NULL;
                        page[j]->keyrepeat = temp.repeat;
                        break;
                    }

                    page = page[j]->next;
                    level++;
                    continue;
                }

                if (previous_page != NULL &&
                    previous_page[(_ascii_to_index(*(p - 1)))]->word != NULL &&
                    previous_page[(_ascii_to_index(*(p - 1)))]->word[level - 2] == *(p - 1))
                {
                    if (previous_page[(_ascii_to_index(*(p - 1)))]->word[level - 1] == '\0')
                    {
                        previous_page[(_ascii_to_index(*(p - 1)))]->kword = previous_page[(_ascii_to_index(*(p - 1)))]->word;
                        previous_page[(_ascii_to_index(*(p - 1)))]->word = NULL;

                        previous_page[(_ascii_to_index(*(p - 1)))]->keyrepeat += previous_page[(_ascii_to_index(*(p - 1)))]->repeat;
                        previous_page[(_ascii_to_index(*(p - 1)))]->repeat = 0;
                        goto jump;
                    }
                    int k = _ascii_to_index(previous_page[(_ascii_to_index(*(p - 1)))]->word[level - 1]);
                    page[k] = node_init();

                    if (previous_page != NULL)
                    {
                        previous_page[(_ascii_to_index(*(p - 1)))]->keys[previous_page[(_ascii_to_index(*(p - 1)))]->kqty] = k;
                        previous_page[(_ascii_to_index(*(p - 1)))]->kqty++;
                    }
                    if (previous_page == NULL)
                    {
                        preinit->keys[preinit->kqty] = k;
                        preinit->kqty++;
                    }

                    page[k]->word = previous_page[(_ascii_to_index(*(p - 1)))]->word;
                    previous_page[(_ascii_to_index(*(p - 1)))]->word = NULL;

                    page[k]->repeat = previous_page[(_ascii_to_index(*(p - 1)))]->repeat;
                    previous_page[(_ascii_to_index(*(p - 1)))]->repeat = 0;

                jump:
                    if (page[j]->word == NULL)
                    {
                        page[j]->word = pp;
                        page[j]->repeat++;
                    }
                    previous_page = NULL;
                    break;
                }

                page[j]->word = pp;

                page[j]->repeat++;
                previous_page = NULL;
                break;
            }

            if (page[j] != NULL && *(p + 1) == '\0')
            {
                if (page[j]->word == NULL)
                {
                    page[j]->word = pp;
                    page[j]->repeat++;
                }
                else
                { //
                    page[j]->kword = pp;
                    page[j]->keyrepeat++;
                }

                previous_page = page;
                break;
            }

            if (page[j] != NULL && page[j]->word != NULL || page[j]->kword != NULL) //
            {
                if (page[j]->repeat != 0)
                {
                    if (page[j]->word == pp || strcmp(page[j]->word, pp) == 0) // strcmp for repeated words, since they have different addresses in memory
                    {
                        page[j]->repeat++;
                        break;
                    }
                }

                if (page[j]->keyrepeat != 0)
                {
                    if (page[j]->kword == pp || strcmp(page[j]->kword, pp) == 0) // strcmp for repeated words, since they have different addresses in memory
                    {
                        page[j]->keyrepeat++;
                        break;
                    }
                }
            }

            if (page[j] != NULL && page[j]->next == NULL)
            {
                next_page = page_init();
                page[j]->next = next_page;
                previous_page = page;
                page = next_page;
                p++;
                level++;
                continue;
            }

            if (page[j] != NULL && page[j]->next != NULL)
            {
                previous_page = page;
                page = page[j]->next;
                p++;
                level++;
                continue;
            }
        }
    }
    return initpage;
}
