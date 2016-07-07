#include <sys/queue.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct mydata__
{
	int data;
	LIST_ENTRY(mydata__) list;
} mydata;
LIST_HEAD(listhead, mydata__) head;

static mydata all_data[100];							

int main(int argc, char *argv[])
{
	LIST_INIT(&head);
	int i;
	for (i = 0; i < 10; i++) {
		all_data[i].data = i;
		LIST_INSERT_HEAD(&head, &all_data[i], list);
	}

	for (; i < 20; i++) {
		all_data[i].data = i;
		LIST_INSERT_AFTER(&all_data[2], &all_data[i], list);
	}

	
	mydata *p;
	for (p = head.lh_first; p != NULL; p = p->list.le_next) {
		printf("data = %d\n", p->data);
	}
	
	
    return 0;
}
