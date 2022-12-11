ALL: test-luaminheap
LIBS := -llua5.3
INC_DIRS := -I/usr/include/lua5.3
%.o:%.c
	$(CC) $(CFLAGS) $(LIBS) $(INC_DIRS)  -o $@ -c $^

test-luaminheap: test-luaminheap.o minheap.o luaminheap.o
	gcc $^  $(LIBS)  -o $@