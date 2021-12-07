CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LINK	= -c
SRCO	= get_next_line.o\
		  get_next_line_utils.o\

SRC		= get_next_line.c\
		  get_next_line_utils.c\

all:	$(SRC)

	$(CC) $(FLAGS) $(SRC) $(LINK)
	$(CC) $(FLAGS) $(SRCO) -o

clean:
	rm -rf *.o
