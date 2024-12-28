#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "my_io.h"
#include "my_string.h"
void printList(List * s, const char * cc) {
	Node * ptr = s->head;
	printf("%s: \"",cc);
	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\"\n");
}

Err getList(List * s, const char * cc) {
/*	int c;
	printf("%s: ",cc);
	while ( scanf("%d",c) ) {
		if(c == '\n')
			return ERR_OK;
		Err check_memory = append(s,c);
		if(check_memory == ERR_MEM)
			return ERR_MEM;
	}*/
	return ERR_EOF;
}

