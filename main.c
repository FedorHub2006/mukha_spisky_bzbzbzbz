// nomer processa - nomer zadachi - dlya KR na lmske dopolnitelno vstavlyayte functii s prefixom my_
// gcc main.c my_io.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "list.h"
#include "my_io.h"

#define MESSAGE_2 "LIST"
List* newList() {
	return (List *) calloc(1, sizeof(List));
}
Node * my_newNode(int c){
	Node * ans = (Node*) malloc(sizeof(Node));
	ans->data = c;
	ans->next = NULL;
	return ans;
}
//
int my_append(List * s, int c){
	Node * new_node = (Node*) malloc(sizeof(Node));
	if (!new_node)
		return 1;
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

int main() {
	List * s = newList();
	my_append(s,1);
	my_append(s,-2);
	my_append(s,0);
	my_append(s,-4);
	my_append(s,-5);
	my_append(s,6);

	printList(s,MESSAGE_2);
	//process1(s);
//	process2(s);
//	process3(s);
	printList(s,MESSAGE_2);
	freeList(s);
	return 0;
}
