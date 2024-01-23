INCLUDES = include
FILES = src/mem.c
FLAGS = -Wall -Wextra -pedantic -fPIC
OBJECTS = mem linked_list tree_set tree_map
OBJECTFILES = obj/mem.o obj/linked_list.o obj/tree_set.o obj/tree_map.o

shared_library: $(OBJECTS)
	gcc $(FLAGS) -shared $(OBJECTFILES) -o lib/libgcl.so

static_lib: $(OBJECTS)
	ar rcs lib/libgcl.a $(OBJECTFILES)

all: $(OBJECTS)
	echo "Compiled all object-files successfully"

linked_list:
	gcc $(FLAGS) -c src/linked_list.c -I $(INCLUDES) -o obj/linked_list.o

tree_set:
	gcc $(FLAGS) -c src/tree_set.c -I $(INCLUDES) -o obj/tree_set.o

tree_map:
	gcc $(FLAGS) -c src/tree_map.c -I $(INCLUDES) -o obj/tree_map.o

mem:
	gcc $(FLAGS) -c src/mem.c -I $(INCLUDES) -o obj/mem.o

test_mem: mem
	gcc $(FLAGS) test/test_mem.c obj/mem.o -I $(INCLUDES) -o test/a.out
	test/a.out
