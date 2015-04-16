VER=0.10-dev
RELEASE=v$(VER)

CC = gcc
CFLAGS = -Wall -ggdb -D_FILE_OFFSET_BITS=64

CFILES=interval_tree.c rbtree.c
csv_CFILES=interval_csv.c
test_CFILES=interval_tree_test.c
HEADERS=interval_tree_generic.h  interval_tree.h  rbtree_augmented.h  rbtree.h

objects = $(CFILES:.c=.o)
test_objects = $(test_CFILES:.c=.o)
csv_objects = $(csv_CFILES:.c=.o)
all_objects = $(objects) $(test_objects) $(csv_objects)

progs = interval-tree-test interval_csv

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBRARY_FLAGS)

all: $(progs)
$(all_objects): $(HEADERS)

interval_csv: $(objects) $(csv_objects)
	$(CC) $(CFLAGS) $(objects) $(csv_objects) -o interval_csv $(LIBRARY_FLAGS)

interval-tree-test: $(objects) $(test_objects)
	$(CC) $(CFLAGS) $(objects) $(test_objects) -o interval-tree-test $(LIBRARY_FLAGS)

clean:
	rm -fr $(objects) $(progs)
