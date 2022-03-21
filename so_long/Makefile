CC		= gcc
CFLAGS	= 
RM		= /bin/rm -f

NAME	= solongte

SRCS	= get_next_line.c get_next_line_utils.c so_long.c 2map_start.c ft_itoa.c map_test.c main.c key_1.c step_pixel.c



OBJS	= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) libmlx.a -lmlx -framework OPENGL -framework Appkit -lm

bonus:		all

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus