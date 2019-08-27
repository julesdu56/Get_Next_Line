CC = Clang

NAME = GNL
LIB = $(addprefix $(LPATH), libft.a)

IDIR = libft/
LPATH = libft/

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -I $(IDIR)

SRCS += get_next_line.c
SRCS += main.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS) : %.o: %.c $(LIB)
	$(CC) $(CFLAGS) -c $<  -o $@

$(LIB):
	make -C $(LPATH)

clean:
	make -C $(LPATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LPATH) fclean
	rm -f $(NAME)

re: fclean all
