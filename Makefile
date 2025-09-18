CC = cc
NAME = libftprintf.a
LIBC = ar rcs
CFLAGS = -Wall -Wextra -Werror

PREF_SRC = ./

CFILES =	ft_printf.c		print_num.c  	print_hex.c 	\
			print_char.c 	print_int.c		print_hex_up.c	\
			print_str.c 	print_pointer.c	print_hex_low.c		

CSRCS  =   $(addprefix $(PREF_SRC), $(CFILES))

OBJS   =   $(CSRCS:.c=.o)

all: $(NAME)

$(PREF_OBJS)%.o:   $(PREF_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)               
	$(LIBC) $(NAME) $(OBJS)                 

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus







