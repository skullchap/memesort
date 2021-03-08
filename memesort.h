#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <string.h>

#define CASEBIT 0x20
#define UPPEROFF 64+9 // yes its 64, so 'A'(65) will take place at 1 in array and 0 will stay empty
#define LOWEROFF 96+9
#define WORDLEN 128
#define BUFSIZE 8192000
#define ARR 36

typedef struct node
{
  char *word;
  char *kword;
  int repeat;
  int keyrepeat;
  int keys[ARR];
  int kqty;
  struct node **next;
} node;

struct
{
  char *word;
  int repeat;
} temp;

//PROTOTYPES
int _ascii_to_index(const char ch);
void traverse(node **pp, node *nn);
void copystr(char **dst, char *src);
node **page_init();
node *node_init();
node **sort(char **unsorted);
int cmpfunc(const void *a, const void *b);

extern size_t BUF;
extern char **unsort_strs;
extern int wordcount;
extern int trav_level;

extern node *preinit;
extern node **initpage;
