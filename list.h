#ifndef MYSTRINGH
#define MYSTRINGH
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <readline/readline.h>

typedef struct Node{
    int data;
    struct Node * next;
} Node;
 
typedef struct List{
    Node * head;
    Node * tail;
} List;
 
#endif
