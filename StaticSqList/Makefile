CC=gcc

SRCS=StaticSqList.c\
	 test.c

OBJS=$(SRCS:.c=.o)

EXEC=test

start: $(OBJS)
	$(CC) -std=c99 -o $(EXEC) $(OBJS)

.c.o:
	$(CC) -std=c99 -o $@ -c $<

.PHONY: clean

clean:
	rm -rf $(EXEC) $(OBJS)
