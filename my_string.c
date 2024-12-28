#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

#include "my_string.h"
#include "my_io.h"
/*
int is_vowel(const char c){
	return (strchr(VOWELS,c) != NULL);
}
int vowels_count(Node ** ptr){
	int amount_vowels = 0;
	while(*ptr != NULL && strchr(DELIM,(*ptr)->data) == NULL ){
		amount_vowels += is_vowel((*ptr)->data); 			
		*ptr = (*ptr)->next ;
	}
	return amount_vowels;

}*/
/*
Str* newStr() {
	return (Str *) calloc(1, sizeof(Str));
}
Err append(Str * s, int c){
	Node * new_node = (Node*) malloc(sizeof(Node));
	if (!new_node)
		return ERR_MEM;
	new_node->data = c;
	new_node->next = NULL;
	if(s->head == NULL)
		s->head = new_node;
	else
		(s->tail)->next = new_node;
	s->tail = new_node;	
	return ERR_OK;
}
void pop_head(Str * s){
	if(s != NULL){
		Node * head = s->head ;
		if(head->next == NULL)
			s->tail = NULL;
		s->head = head->next;
		free(head);
	}
}
void remove_next_Node(Str * s, Node * node){
	if ( node != NULL && node->next != NULL){
		Node * next = node->next;
		if(next == s->tail)
			s->tail = node;
		node->next = next->next ;
		free(next);
	}
}

/*

void del_all_even(Str * s){
	Node * cur_ptr = s->head;
	int amount_vowels = vowels_count(&cur_ptr);
	if(amount_vowels%2 == 0 ){
		while(s->head != cur_ptr) pop_head(s);
	}
	while(cur_ptr != NULL){
		Node * cur_ptr_tail = cur_ptr->next ;
		if(cur_ptr_tail != NULL && strchr(DELIM,cur_ptr_tail->data) == NULL ){
			amount_vowels = vowels_count(&cur_ptr_tail);
			if(amount_vowels%2 == 0){
				while(cur_ptr->next != cur_ptr_tail)
					remove_next_Node(s,cur_ptr);
			}
		}
		cur_ptr = cur_ptr_tail ; 
	}
}
void eliminate_delims(Str * s){
	while(s->head != NULL && strchr(DELIM,(s->head)->data ) != NULL ) pop_head(s);
	Node * cur_ptr = s->head ;
	while(cur_ptr != NULL && cur_ptr->next != NULL){
		if( strchr(DELIM,cur_ptr->data) == NULL && strchr(DELIM,(cur_ptr->next)->data)!= NULL ){
			(cur_ptr->next)->data = ' ' ;
			while( (cur_ptr->next)->next != NULL && strchr(DELIM,((cur_ptr->next)->next)->data) != NULL ){
				remove_next_Node(s,cur_ptr);
				(cur_ptr->next)->data = ' ' ;
			}
			if ( (cur_ptr->next)->next == NULL )
				remove_next_Node(s,cur_ptr);
		}
		cur_ptr = cur_ptr->next;
	}
}
*/

