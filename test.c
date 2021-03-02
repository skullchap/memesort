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
 
 /////////////////////////////////////////////////////////
 
    // unsigned char arr[] = {25, 34, 62, 1, 55, 2, 53};
    // unsigned char qty = sizeof arr / sizeof(unsigned char);

    // unsigned char *nums = NULL;
    // nums = malloc(ARR);
    // memset(nums, 0, ARR);
    // unsigned char *p = arr;
    // unsigned char *temp = malloc(1);

    // for (int i = 0; i < qty; i++)
    // {
    //     // if (*p >= 53 && *p <= 62)
    //     // {
    //     //     nums[*p] = nums[*p - 53];
    //     //     nums[*p - 53] = *p;
    //     // }
    //     // else
    //     nums[*p] = *p;

    //     p++;
    // }

    // for (int i = 52; i <= ARR; i++)
    // {
    //     if (i == ARR)
    //         i = 0;

    //     if (i + 1 == 52)
    //         break;

    //     if (nums[i] != 0)
    //         printf("%u\n", nums[i]);
    // }

    // free(nums);
}
