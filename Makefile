LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		putnbr_base.c \
		put_pointer_addr.c
		
SURPL_O = 	ft_printf.o \
			putnbr_base.o \
			put_pointer_addr.o

CC = cc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all