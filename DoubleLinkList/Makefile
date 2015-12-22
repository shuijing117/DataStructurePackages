CC=gcc

SRCS=DoubleLinkList.c\
	 test.c

OBJS=$(SRCS:.c=.o)

EXEC=test

start: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

.c.o:
	$(CC) -o $@ -c $<

.PHONY: clean

clean:
	rm -rf $(EXEC) $(OBJS)
