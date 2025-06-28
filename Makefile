CC = gcc
CFLAGS = -Wall -g
SRCDIR = src
SRCS = main.c $(wildcard $(SRCDIR)/*/*.c)
OBJS = $(SRCS:.c=.o)
EXEC = "./output/hospital"

all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p output
	$(CC) $(OBJS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
	find . -name "*.o" -type f -delete

.PHONY: all clean