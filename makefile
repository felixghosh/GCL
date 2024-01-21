INCLUDES = include
FILES = src/mem.c
FLAGS = -Wall -Wextra -pedantic
OBJECTS = mem linked_list tree_set tree_map
# OBJECTFILES = obj/linked_list.o obj/tree_set.o obj/tree_map.o obj/mem.o
OBJECTFILES = obj/*

all: $(OBJECTS)
	echo "Compiled all object-files successfully"

static_lib: $(OBJECTS)
	ar rcs libgcl.a $(OBJECTFILES)

linked_list:
	gcc $(FLAGS) -c src/linked_list.c -I $(INCLUDES) -o obj/linked_list.o

tree_set:
	gcc $(FLAGS) -c src/tree_set.c -I $(INCLUDES) -o obj/tree_set.o

tree_map:
	gcc $(FLAGS) -c src/tree_map.c -I $(INCLUDES) -o obj/tree_map.o

mem:
	gcc $(FLAGS) -c src/mem.c -I $(INCLUDES) -o obj/mem.o