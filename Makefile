#####################################SO_LONG#####################################

NAME	= so_long
NAME_BONUS = so_long_bonus

#####################################SRCS########################################

PATH_SRCS = srcs/

SRCS	+= name.c
SRCS	+= parsing.c
SRCS	+= valid_path.c
MAIN	+= srcs/main.c

vpath %.c $(PATH_SRCS)

###################################OBJS#########################################

PATH_OBJS = objs
OBJS	= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

OBJS_BONUS	= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS_BONUS))

################################COMPILATION####################################

INCLUDE	= -Ilibft/includes -Iinclude -Iminilibx-linux

LINK	= libft/libft.a -L minilibx-linux/ -lmlx -lXext -lX11

CFLAGS	= -Wall -Wextra -Werror -g3

##################################RULES#######################################

all: mlx libft $(NAME)

mlx:
	${MAKE} -sC minilibx-linux

libft:
	${MAKE} -sC libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(MAIN) -o objs/main.o $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) objs/main.o $(INCLUDE) $(LINK) -g3

$(OBJS) : $(PATH_OBJS)/%.o:%.c
		mkdir -p $(PATH_OBJS)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

bonus: $(NAME_BONUS)


$(NAME_BONUS): $(OBJS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS) $(OBJS_BONUS) $(INCLUDE) $(LINK) -g3

$(OBJS_BONUS) : $(PATH_OBJS)/%.o:%.c
		mkdir -p $(PATH_OBJS)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -r $(PATH_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean
		${MAKE}

.PHONY: all mlx libft bnous clean fclean re
