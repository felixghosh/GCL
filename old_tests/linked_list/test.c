#include <stdio.h>
#include "gcl_linkedlist.h"

int main(){
	linked_list_t* list = new_linked_list(1);
	printf("size: %d\n", length_linked_list(list));
	print_linked_list(list);
	prepend_linked_list(&list, 0);
	printf("size: %d\n", length_linked_list(list));
	print_linked_list(list);
	append_linked_list(&list, 2);
	printf("size: %d\n", length_linked_list(list));
	print_linked_list(list);
}
