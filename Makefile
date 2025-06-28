CC = gcc
CFLAGS = -Wall -g
SRCDIR = src
SRCS = main.c $(wildcard $(SRCDIR)/*/*.c)
OBJS = $(SRCS:.c=.o)

OUTPUT_DIR = output
EXEC = $(OUTPUT_DIR)/hospital$(EXT)

UNAME_S := $(shell uname -s)

ifeq ($(OS),Windows_NT)
    RM = del /f /q
    MKDIR = if not exist $(OUTPUT_DIR) mkdir $(OUTPUT_DIR)
    EXT = .exe
else
    RM = rm -f
    MKDIR = mkdir -p $(OUTPUT_DIR)
    EXT =
endif

all: $(EXEC)

$(EXEC): $(OBJS)
	@$(MKDIR)
	$(CC) $(OBJS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(EXEC)
ifeq ($(OS),Windows_NT)
	REM Remove .o adicionais se houver
	for /r %%f in (*.o) do del /f /q "%%f"
else
	find . -name "*.o" -type f -delete
endif

.PHONY: all clean
