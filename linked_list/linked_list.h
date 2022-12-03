#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct linked_list_t{
	struct linked_list_t* next;
	struct linked_list_t* prev;
	void* data;
} linked_list_t;

linked_list_t* new_linked_list(void* data);
void free_linked_list(linked_list_t** list);
void prepend_linked_list(linked_list_t** list, void* data);
void append_linked_list(linked_list_t** list, void* data);
int length_linked_list(linked_list_t* list);
void print_linked_list(linked_list_t* list);

#endif
