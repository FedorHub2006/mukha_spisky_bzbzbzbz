#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#include "my_io.h"
#include "list.h"

void printList(List * s, const char * cc) {
	Node * ptr = s->head;
	printf("%s: \"",cc);
	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\"\n");
}

