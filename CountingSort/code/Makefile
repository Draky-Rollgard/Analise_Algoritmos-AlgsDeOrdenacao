CC=gcc
CFLAGS=-Wall -Wextra -std=c11
SRC=Counting_Sort_code.c
PROG=counting_sort
EXEC=$(PROG)$(if $(filter Windows_NT,$(OS)),.exe)

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $< -o $@

run: all
	./$(EXEC)

clean:
	rm -f $(PROG) $(PROG).exe *.o