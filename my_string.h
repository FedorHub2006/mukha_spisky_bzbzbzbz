#ifndef MYSTRINGH
#define MYSTRINGH
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <readline/readline.h>

#define VOWELS "AEIOUaeiou"
#define DELIM " \t"

typedef enum Err {
	ERR_MEM = -1,
	ERR_OK = 0,
	ERR_EOF = 1
} Err;

typedef struct Node{
    int data;
    struct Node * next;
} Node;
 
typedef struct List{
    Node * head;
    Node * tail;
} List;
 

//int is_vowel(const char c);
//int vowels_count(Node ** ptr);
//List* newList() ;
//Err append(List * s, int c);
//void pop_head(List * s);
//void remove_next_Node(List * s, Node * node);
//void del_all_even(List * s);
//void eliminate_delims(List * s);
void freeList(List * s);

#endif
