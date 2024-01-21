#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"


linked_list_t* new_linked_list(void* data){
	linked_list_t* p = malloc(sizeof(linked_list_t));
	if(p == NULL){
		fprintf(stderr, "ERROR: Linked list allocation failed!");
		return NULL;
	} 
	p->next = p;
	p->prev = p;
	p->data = data;

	return p;
}

void free_linked_list(linked_list_t** list){
	linked_list_t *p, *q;

	p = *list;

	if(p == NULL)
		return;

	p->prev->next = NULL;
	do{
		q = p->next;
		free(p);
		p = q;
	}while(p != NULL);

	*list = NULL;
}

void append_linked_list(linked_list_t** list, void* data){
	linked_list_t* p = *list;		//Old list
	linked_list_t* q;				//New link
	
	if(p == NULL){
		*list = new_linked_list(data);
		return;
	}

	q = malloc(sizeof(linked_list_t));
	if(q == NULL){
		printf("ERROR: malloc failed, out of memory!\n");
		exit(EXIT_FAILURE);
	}

	q->data = data;
	q->prev = p->prev;
	q->next = p;
	p->prev->next = q;
	p->prev = q;
}

void prepend_linked_list(linked_list_t** list, void* data){
	linked_list_t* p = *list;		//Old list
	linked_list_t* q;				//New link

	if(p == NULL){
		*list = new_linked_list(data);
		return;
	}

	q = malloc(sizeof(linked_list_t));
	if(q == NULL){
		printf("ERROR: malloc failed, out of memory!\n");
		exit(EXIT_FAILURE);
	}
	
	q->data = data;
	q->prev = p->prev;
	q->next = p;
	p->prev->next = q;
	p->prev = q;

	*list = q;

}

int length_linked_list(linked_list_t* list){
	int l = 0;
	linked_list_t* head = list;
	
	if(list == NULL)
		return l;

	do{
		l++;
		list = list->next;
	}while(list != head);

	return l;
}

void print_linked_list(linked_list_t* list){
	linked_list_t* head = list;

	if(list == NULL){
		printf("[]");
		return;
	}

	printf("[ ");
	do{
		printf("%d ", *(int*)(list->data));
		list = list->next;
	}while(list != head);
	printf("]\n");
}
