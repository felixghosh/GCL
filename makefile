static_lib: linked_list.o tree_set.o tree_map.o util.o
	ar rcs libGCL.a obj/linked_list.o obj/tree_set.o obj/tree_map.o obj/util.o

linked_list.o:
	gcc -O3 -c linked_list/linked_list.c -o obj/linked_list.o

tree_set.o:
	gcc -O3 -c tree_set/tree_set.c -o obj/tree_set.o

tree_map.o:
	gcc -O3 -c tree_map/tree_map.c -o obj/tree_map.o

util.o:
	gcc -O3 -c util/util.c -o obj/util.o