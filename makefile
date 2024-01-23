INCLUDES = include
FILES = src/mem.c
FLAGS = -Wall -Wextra -pedantic -fPIC
OBJECTS = mem linked_list tree_set tree_map
OBJECTFILES = obj/mem.o obj/linked_list.o obj/tree_set.o obj/tree_map.o

shared_lib: $(OBJECTS)
	gcc -shared $(OBJECTFILES) -o /usr/lib/libgcl.so $(FLAGS)

static_lib: $(OBJECTS)
	ar rcs lib/libgcl.a $(OBJECTFILES)

all: $(OBJECTS)
	echo "Compiled all object-files successfully"

linked_list:
	gcc -c src/linked_list.c -I $(INCLUDES) -o obj/linked_list.o $(FLAGS)

tree_set:
	gcc -c src/tree_set.c -I $(INCLUDES) -o obj/tree_set.o $(FLAGS)

tree_map:
	gcc -c src/tree_map.c -I $(INCLUDES) -o obj/tree_map.o $(FLAGS)

mem:
	gcc -c src/mem.c -I $(INCLUDES) -o obj/mem.o $(FLAGS)

test_mem: mem
	gcc test/test_mem.c obj/mem.o -I $(INCLUDES) -o test/a.out $(FLAGS)
	test/a.out
