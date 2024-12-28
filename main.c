#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <readline/readline.h>

#include "my_string.h"
#include "my_io.h"

#define MESSAGE_1 "INPUT STRING"
#define MESSAGE_2 "STRING_BEFORE_FORMATTING"
#define MESSAGE_3 "STRING_AFTER_FORMATTING"

List* newList() {
	return (List *) calloc(1, sizeof(List));
}
Node * my_newNode(int c){
	Node * ans = (Node*) malloc(sizeof(Node));
	ans->data = c;
	ans->next = NULL;
	return ans;
}
int my_append(List * s, int c){
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
	return 0;
}
void my_pop_head(List * s){
	if(s != NULL){
		Node * head = s->head ;
		if(head->next == NULL)
			s->tail = NULL;
		s->head = head->next;
		free(head);
	}
}
void my_remove_next_Node(List * s, Node * node){
	if ( node != NULL && node->next != NULL){
		Node * next = node->next;
		if(next == s->tail)
			s->tail = node;
		node->next = next->next ;
		free(next);
	}
}
void freeList(List * s){	
	while(s->head != NULL){
		my_pop_head(s);
	}
	free(s);
}

void process1(List* list) {
	if (!list || list->head == NULL) {
		return;
	}

	Node* cur = list->head;
	while (cur != NULL) {
		if (cur->data < 0) {
			Node* newNode = my_newNode(0 - cur->data);
			newNode->next = cur->next;
			cur->next = newNode;
			if (cur == list->tail) {
				list->tail = newNode;
			}
			cur = newNode->next; 
		} else {
			cur = cur->next;
		}
	}
}

void process2(List * list){
	if(!list || list->head == NULL ){
		return ; 
	}
	Node * counter = list->head;
	//count_1
	int am_otr = 0;
	while(counter != NULL){
		am_otr += (counter->data < 0 );
		counter = counter->next;
	}
	counter = NULL;

	int i = 0 ;
	while(list->head != NULL && (list->head)->data < 0 && i<am_otr ){
		++i;
		int c = (list->head)->data ;
		my_pop_head(list);
		my_append(list,c);
	}

	Node * cur_ptr = list->head ;
	while(i < am_otr && cur_ptr!=NULL){
		while(i<am_otr && cur_ptr->next != NULL && (cur_ptr->next)->data < 0){
			++i;
			int c = (cur_ptr->next)->data ; 
			my_append(list,c);
			my_remove_next_Node(list,cur_ptr);
		}
		cur_ptr = cur_ptr->next;		
	}
	cur_ptr = NULL;	

}

void process3(List* list) {
	if (!list || list->head == NULL) {
		return;
	}

	Node* prev = NULL;
	Node* cur = list->head;

	while (cur != NULL && cur->next != NULL) {
		Node* A = cur;
		Node* B = cur->next;

		if (!prev) {
			list->head = B;
		} else {
			prev->next = B; 
		}

		A->next = B->next;
		B->next = A;
		prev = A;        
		cur = A->next; 
	}

	if (cur == NULL)
		list->tail = prev;

}


/*
   void del_all_even(Str * s){
   Item * cur_ptr = s->head;
   int amount_vowels = vowels_count(&cur_ptr);
   if(amount_vowels%2 == 0 ){
   while(s->head != cur_ptr) pop_head(s);
   }
   while(cur_ptr != NULL){
   Item * cur_ptr_tail = cur_ptr->next ;
   if(cur_ptr_tail != NULL && strchr(DELIM,cur_ptr_tail->data) == NULL ){
   amount_vowels = vowels_count(&cur_ptr_tail);
   if(amount_vowels%2 == 0){
   while(cur_ptr->next != cur_ptr_tail)
   remove_next_Item(s,cur_ptr);
   }
   }
   cur_ptr = cur_ptr_tail ; 
   }
   }*/



int main() {
	//	Err inp = ERR_OK ;
	//	while(inp == ERR_OK){
	List * s = newList();
	//	inp = getList(s, MESSAGE_1);
	my_append(s,1);
	my_append(s,-2);
	my_append(s,0);
	my_append(s,-4);
	my_append(s,-5);
	my_append(s,6);
	/*		if(inp == ERR_MEM){
			fprintf(stderr,"FAILED_ALLOCATION");
			freeList(s);
			return 1;
			}
			if(inp == ERR_EOF){
			printf("EOF\n");
			freeList(s);
			return 0;
			}*/
	printList(s,MESSAGE_2);
	//	del_all_even(s);
	//	eliminate_delims(s);
	//	printList(s,MESSAGE_3);
	process2(s);
	printList(s,MESSAGE_2);
	freeList(s);
	//	}
	return 0;
}
