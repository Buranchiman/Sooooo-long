#####################################SO_LONG#####################################

NAME	= so_long
NAME_BONUS = so_long_bonus

#####################################SRCS########################################

PATH_SRCS = srcs/

SRCS	+= get_map.c
SRCS	+= checking.c
SRCS	+= direction.c
SRCS	+= travel.c
SRCS	+= init.c
SRCS	+= window.c
MAIN	+= srcs/main.c

vpath %.c $(PATH_SRCS)

###################################OBJS#########################################

PATH_OBJS = objs
OBJS	= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

OBJS_BONUS	= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS_BONUS))

################################COMPILATION####################################

INCLUDE	= -Ilibft/includes -Iinclude -I /mnt/nfs/homes/wvallee/42cursus/minilibx-linux

LINK	= libft/libft.a -L /mnt/nfs/homes/wvallee/42cursus/minilibx-linux/ -lmlx -lXext -lX11

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g3

##################################RULES#######################################

all:  libft $(NAME)

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

.PHONY: all libft clean fclean re
